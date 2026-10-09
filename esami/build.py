#!/usr/bin/env python3
"""Compila quiz/<materia>/*.md in data.js per index.html. Rilancia dopo ogni modifica ai quiz.

Formato di un file quiz:
    ---
    titolo: ...
    durata: 45            (minuti)
    fonte: ...
    ---
    ## Contesto                      testo condiviso dalle domande successive
    ## [mcq 3] Domanda               opzioni "- [ ]" / "- [x]" (anche più di una corretta)
    ## [num 2 = 0.75 ±0.01] Domanda  risposta numerica con tolleranza
    ## [aperta 5] Domanda            autovalutazione con griglia
    ### Soluzione
    ### Griglia                      righe "- punti | voce"
"""
import json, re, sys
from pathlib import Path

ROOT = Path(__file__).parent
NAMES = {
    "ingegneria-del-software": "Ingegneria del Software",
    "basi-di-dati": "Basi di Dati",
    "introduzione-apprendimento-automatico": "Apprendimento Automatico",
}
HEAD = re.compile(r"\[(mcq|num|aperta)\s+([\d.]+)(?:\s*=\s*([-\d.eE]+)(?:\s*±\s*([\d.eE]+))?)?\]\s*(.*)", re.S)


def parse(path):
    text = path.read_text(encoding="utf-8")
    meta = {}
    m = re.match(r"---\n(.*?)\n---\n", text, re.S)
    if m:
        meta = dict(l.split(":", 1) for l in m.group(1).splitlines() if ":" in l)
        meta = {k.strip(): v.strip() for k, v in meta.items()}
        text = text[m.end():]
    blocks = []
    for sec in re.split(r"^## ", text, flags=re.M)[1:]:
        head, _, body = sec.partition("\n")
        if head.strip() == "Contesto":
            blocks.append({"type": "contesto", "md": body.strip()})
            continue
        h = HEAD.match(head)
        if not h:
            sys.exit(f"{path}: intestazione non valida: ## {head}")
        typ, pts, ans, tol, q = h.groups()
        parts = re.split(r"^### (Soluzione|Griglia)\s*$", body, flags=re.M)
        main, extra = parts[0], dict(zip(parts[1::2], parts[2::2]))
        b = {"type": typ, "pts": float(pts), "q": q.strip(), "sol": extra.get("Soluzione", "").strip()}
        if typ == "mcq":
            opts = re.findall(r"^- \[( |x)\] (.*)$", main, re.M)
            if not opts or not any(c == "x" for c, _ in opts):
                sys.exit(f"{path}: mcq senza opzioni o senza risposta corretta: {q[:50]}")
            b["options"] = [o for _, o in opts]
            b["correct"] = [i for i, (c, _) in enumerate(opts) if c == "x"]
            main = re.sub(r"^- \[( |x)\] .*\n?", "", main, flags=re.M)
        if typ == "num":
            if ans is None:
                sys.exit(f"{path}: num senza risposta: {q[:50]}")
            b["ans"], b["tol"] = float(ans), float(tol or 0)
        if typ == "aperta":
            rub = re.findall(r"^- ([\d.]+) \| (.*)$", extra.get("Griglia", ""), re.M)
            b["rubric"] = [{"pts": float(p), "voce": v.strip()} for p, v in rub]
            if rub and abs(sum(r["pts"] for r in b["rubric"]) - b["pts"]) > 1e-6:
                print(f"attenzione {path.name}: griglia {sum(r['pts'] for r in b['rubric'])} ≠ {pts} punti", file=sys.stderr)
        b["md"] = main.strip()
        blocks.append(b)
    return {"key": path.stem, "titolo": meta.get("titolo", path.stem), "durata": int(meta.get("durata", 0) or 0),
            "fonte": meta.get("fonte", ""), "blocks": blocks}


def originals(slug, key):
    # file originali (pdf/immagini) con la stessa data, per il link "originale"
    m = re.search(r"\d{4}(-\d\d-\d\d)?", key)
    d = ROOT / "pdf" / slug
    if not m or not d.exists():
        return []
    return [f"pdf/{slug}/{f.name}" for f in sorted(d.iterdir()) if m.group(0) in f.name and f.suffix in (".pdf", ".jpeg", ".md", ".ipynb", ".zip")]


TOPICS = json.loads((ROOT / "topics.json").read_text(encoding="utf-8"))


def tag(b, topics):
    # argomenti dal testo della domanda; le opzioni solo se la domanda da sola non basta
    find = lambda t: [x["id"] for x in topics if re.search(x["re"], t, re.I)]
    opts = " ".join(b.get("options", []))
    tags = find(b["q"] + " " + b["md"]) or find(opts)
    # opzioni che citano argomenti non studiati (es. reti neurali) rendono la domanda fuori programma
    return tags + [x["id"] for x in topics if x.get("re_opzioni") and x["id"] not in tags and re.search(x["re_opzioni"], opts, re.I)]


APPUNTI = {  # appunti dell'utente: indice da .toc, pagine verificate sul PDF
    "ingegneria-del-software": ROOT.parent / "3/ing_sfw/ing_sfw",
    "basi-di-dati": ROOT.parent / "3/basi_dati/basi_dati",
    "introduzione-apprendimento-automatico": ROOT.parent / "3/apprendimento/apprendimento",
}


def appunti(base):
    toc, pdf = base.with_suffix(".toc"), base.with_suffix(".pdf")
    if not toc.exists() or not pdf.exists():
        return []
    import subprocess
    pages = subprocess.run(["pdftotext", "-layout", str(pdf), "-"], capture_output=True, text=True).stdout.split("\f")
    flat = lambda s: re.sub(r"[^a-z0-9]", "", s.lower())
    out = []
    for m in re.finditer(r"\\contentsline \{((?:sub)*section)\}\{(?:\\numberline \{([^}]*)\})?(.*?)\}\{(\d+)\}\{", toc.read_text(encoding="utf-8")):
        lvl, num, title, page = m.group(1), m.group(2) or "", m.group(3), int(m.group(4))
        title = re.sub(r"\\[a-zA-Z]+\s*|[{}$]", "", title).strip()   # via comandi LaTeX
        key = flat(title)[:30]
        # il numero del .toc è quello stampato: cerco la pagina fisica dove compare davvero il titolo
        cands = sorted(range(len(pages)), key=lambda i: abs(i + 1 - page))[:12]
        phys = next((i + 1 for i in cands if key and key in flat(pages[i])), page)
        out.append({"n": num, "t": title, "p": phys, "l": lvl.count("sub")})
    return out


def gruppi(prove):
    """Raggruppa le domande a crocette ripetute tra prove diverse (opzioni rimescolate, refusi, prefisso [Categoria]).
    Stesso gruppo solo se testo quasi identico, stessi numeri, stesse opzioni e STESSA risposta giusta:
    le varianti (es. 'aumento' vs 'riduzione', 'corretta' vs 'errata') restano domande distinte."""
    import unicodedata
    from difflib import SequenceMatcher

    def norm(s):
        s = re.sub(r"^\[[^\]]*\]\s*", "", s)
        s = re.sub(r"(?<![\d.])0(?=[.,]\d)", "", s)          # 0.5 == .5
        s = s.replace("¾", "3/4").replace("¼", "1/4").replace("½", "1/2")
        s = unicodedata.normalize("NFKD", s.replace("’", "'")).encode("ascii", "ignore").decode().lower()
        s = re.sub(r"\b([a-z])'", r"\1", s)
        return re.sub(r"\s+", " ", re.sub(r"[^a-z0-9]+", " ", s)).strip()
    sim = lambda a, b: SequenceMatcher(None, a, b).ratio()

    def same(x, y):
        if len(x["o"]) != len(y["o"]) or sim(x["q"], y["q"]) < 0.9 or re.findall(r"\d+", x["q"]) != re.findall(r"\d+", y["q"]):
            return False
        pair = {i: max(range(len(y["o"])), key=lambda j: sim(x["o"][i], y["o"][j])) for i in range(len(x["o"]))}
        if len(set(pair.values())) != len(pair) or min(sim(x["o"][i], y["o"][j]) for i, j in pair.items()) < 0.85:
            return False
        return sorted(pair[i] for i in x["c"]) == sorted(y["c"])

    reps = []
    for p in prove:
        for b in p["blocks"]:
            if b["type"] != "mcq":
                continue
            it = {"q": norm(b["q"]), "o": [norm(o) for o in b["options"]], "c": b["correct"], "b": b}
            rep = next((r for r in reps if same(r, it)), None)
            if rep is None:
                reps.append(it); rep = it; rep["id"] = f"g{len(reps)}"
            b["grp"] = rep["id"]


data = []
for slug, name in NAMES.items():
    prove = []
    for f in sorted((ROOT / "quiz" / slug).glob("*.md")):
        p = parse(f)
        p["orig"] = originals(slug, p["key"])
        for b in p["blocks"]:
            if b["type"] != "contesto":
                b["topics"] = tag(b, TOPICS[slug])
                # i progetti di Apprendimento sono di deep learning: fuori programma finché le reti non sono studiate
                if p["key"].startswith("progetto") and slug == "introduzione-apprendimento-automatico" and "reti" not in b["topics"]:
                    b["topics"].append("reti")
        prove.append(p)
    # scritti/simulazioni prima, poi progetti, poi banca; dentro ogni gruppo dal più recente
    group = lambda k: 2 if k.startswith("banca") else 1 if k.startswith("progetto") else 0
    prove.sort(key=lambda p: (-group(p["key"]), re.sub(r"^\D+", "", p["key"])), reverse=True)
    gruppi(prove)
    data.append({"slug": slug, "name": name, "prove": prove, "appunti": appunti(APPUNTI[slug]),
                 "topics": [{k: t[k] for k in ("id", "nome", "studiato")} for t in TOPICS[slug]]})

(ROOT / "data.js").write_text("const DATA = " + json.dumps(data, ensure_ascii=False) + ";\n", encoding="utf-8")
for m in data:
    qs = [b for p in m["prove"] for b in p["blocks"] if b["type"] != "contesto"]
    ok = {t["id"] for t in m["topics"] if t["studiato"]}
    mirate = sum(1 for b in qs if b["topics"] and set(b["topics"]) <= ok)
    print(f"{m['name']}: appunti {len(m['appunti'])} sezioni · {len(m['prove'])} prove, {len(qs)} domande, {mirate} sugli argomenti studiati, {sum(1 for b in qs if not b['topics'])} senza argomento")
