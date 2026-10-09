#!/usr/bin/env python3
"""Serve il sito d'allenamento e inoltra /api/grade a un LLM con API OpenAI-compatibile (piano gratuito).

Uso:  python3 server.py   →  http://localhost:8000
Chiave: variabile AI_KEY oppure file .ai_key accanto a questo script (non va su git).
Provider di default: Groq. Per Gemini:
  AI_BASE=https://generativelanguage.googleapis.com/v1beta/openai AI_MODEL=gemini-2.5-flash python3 server.py
"""
import json, os, re, time, urllib.request, urllib.error
from functools import partial
from http.server import ThreadingHTTPServer, SimpleHTTPRequestHandler
from pathlib import Path

ROOT = Path(__file__).parent
BASE = os.environ.get("AI_BASE", "https://api.groq.com/openai/v1")
MODEL = os.environ.get("AI_MODEL", "openai/gpt-oss-120b")
KEYFILE = ROOT / ".ai_key"
KEY = os.environ.get("AI_KEY") or (KEYFILE.read_text().strip() if KEYFILE.exists() else "")

SYSTEM = """Sei un docente universitario che corregge una risposta d'esame. Hai la domanda, la soluzione di riferimento e una griglia di voci con punteggio.
Valuta SOLO la risposta dello studente, con severità equa: una voce è soddisfatta se lo studente ne ha centrato il contenuto, anche con parole o approcci diversi ma corretti (es. query SQL equivalenti). Se la risposta è vuota o fuori tema, nessuna voce è soddisfatta.
Rispondi SOLO con JSON: {"voci": [true/false per ogni voce della griglia, nello stesso ordine], "commento": "feedback in italiano, max 120 parole: cosa va bene, errori, cosa manca"}"""


def grade(req):
    rubric = "\n".join(f"{i+1}. ({r['pts']} pt) {r['voce']}" for i, r in enumerate(req["rubric"]))
    user = (f"MATERIA: {req['materia']}\n\n" + (f"CONTESTO:\n{req['contesto']}\n\n" if req.get("contesto") else "")
            + f"DOMANDA:\n{req['domanda']}\n\nSOLUZIONE DI RIFERIMENTO:\n{req['soluzione']}\n\nGRIGLIA:\n{rubric}\n\n"
            + f"RISPOSTA DELLO STUDENTE:\n{req['risposta'] or '(vuota)'}")
    out = ask(SYSTEM, user)
    voci = [bool(v) for v in out.get("voci", [])][:len(req["rubric"])]
    voci += [False] * (len(req["rubric"]) - len(voci))
    return {"voci": voci, "commento": str(out.get("commento", "")), "modello": MODEL}


EXPLAIN = """Sei un tutor universitario paziente. Lo studente ha sbagliato (in tutto o in parte) una domanda d'esame.
Spiega in italiano, in modo chiaro e breve (max 200 parole, markdown, formule in LaTeX tra $...$):
1. perché la sua risposta è sbagliata o incompleta (il ragionamento errato più probabile);
2. perché la risposta corretta è giusta, con l'idea chiave da ricordare;
3. un piccolo esempio o trucco mnemonico se aiuta.
La RISPOSTA CORRETTA indicata è quella ufficiale: spiegala. Se ti sembra davvero discutibile, dillo esplicitamente
("la chiave ufficiale è X, però…") invece di contraddirla senza avvisare. Leggi anche la SOLUZIONE DI RIFERIMENTO, che può già discuterlo.
Formule LaTeX con i comandi completi di backslash (\\prod, \\sum, \\frac), dentro $...$; nelle formule solo simboli,
niente parole (le parole italiane vanno fuori dai $). Non scrivere tu l'elenco delle sezioni da ripassare nella spiegazione:
mettile solo nel campo "sezioni".
Se è dato l'INDICE DEGLI APPUNTI dello studente, scegli da quell'elenco le 1-3 sezioni più specifiche dove ripassare
l'argomento (preferisci i sottoparagrafi ai capitoli; non inventare sezioni che non ci sono).
Rispondi SOLO con JSON: {"spiegazione": "...", "sezioni": ["4.19", "6.11"]}  (numeri di sezione come stringhe, presi dall'indice)"""


LATEX = re.compile(r"(?<![\\a-zA-Z])(prod|sum|frac|sigma|pi|bowtie|mid|log|cdot|neq|leq|geq|le|ge|theta|mu|infty|wedge|vee|neg|in|cap|cup|sqrt|alpha|beta|lambda|mathbf|mathrm|mathcal|text|top|nabla|partial|hat|bar|vec|to|times|approx|exp)(?=[_{^\s(\\|])")


def fix_latex(text):
    """Ripara le formule del modello: backslash dimenticati ($prod_i$) e comandi mangiati dagli escape JSON
    (\\frac -> form feed + "rac", \\theta -> tab + "heta", \\neq -> a capo + "eq"). Solo DENTRO le formule:
    $$...$$ (anche su più righe) e $...$ su una sola riga, così il testo normale e i suoi a capo restano intatti."""
    ctrl = {"\f": "\\f", "\t": "\\t", "\b": "\\b", "\r": "\\r"}

    def fix(m):
        f = re.sub("[\f\t\b\r]", lambda c: ctrl[c.group(0)], m.group(0))
        f = re.sub(r"\n(?=eq|abla|ot\b|u\b|ewline|exists|e\b)", r"\\n", f)   # \neq \nabla \not \nu: solo questi
        return LATEX.sub(r"\\\1", f)
    return re.sub(r"\$\$[\s\S]+?\$\$|\$(?:[^$\n]|\n(?=eq|abla|ot\b|u\b|exists))+?\$", fix, text)


def pick_sezioni(raw, sezioni):
    """Riconduce le sezioni proposte dal modello a voci reali dell'indice (numero o titolo), max 3, senza doppioni."""
    by_n = {s["n"]: s for s in sezioni}
    by_t = {re.sub(r"\W", "", s["t"].lower()): s for s in sezioni}
    out = []
    for x in raw if isinstance(raw, list) else [raw]:
        x = str(x.get("n") or x.get("numero") or x) if isinstance(x, dict) else str(x)
        num = re.search(r"\d+(?:\.\d+)*", x)
        s = by_n.get(num.group(0)) if num else None
        s = s or by_t.get(re.sub(r"\W", "", re.sub(r"^[§\d.\s]+", "", x).lower()))
        if s and s not in out:
            out.append(s)
    return out[:3]


def sezioni_per_titolo(domanda, sezioni):
    """Ripiego se il modello non indica sezioni: quelle il cui titolo (parole significative) compare nella domanda."""
    testo = domanda.lower()
    def score(s):
        parole = [w for w in re.findall(r"[a-zàèéìòù]{5,}", s["t"].lower()) if w not in ("della", "delle", "esempio", "classificazione")]
        return sum(w in testo for w in parole) / (len(parole) or 1)
    best = sorted((s for s in sezioni if score(s) >= 0.5), key=lambda s: (-score(s), -s["n"].count(".")))
    return best[:2]


def explain(req):
    sezioni = [s for s in req.get("appunti", []) if s.get("n")]
    indice = "\n".join(f"{s['n']} {s['t']}" for s in sezioni)
    # domande "sentenza ERRATA/SCORRETTA": l'opzione da scegliere è l'affermazione FALSA (il modello tende a confondersi)
    negativa = re.search(r"\b(errat[ao]|scorrett[ao]|errone[ao])\b|\bNON\b|non è una|non può|non aiuta", req["domanda"].split("\n")[0], re.I)
    nota = ("ATTENZIONE: la domanda chiede di individuare l'affermazione FALSA. L'opzione da scegliere è quindi FALSA; "
            "se lo studente ha scelto un'opzione vera, il suo errore è aver scelto un'affermazione vera. "
            "Spiega perché l'opzione da scegliere è falsa e perché quella dello studente è vera.\n\n") if negativa else ""
    user = (f"MATERIA: {req['materia']}\n\n" + (f"CONTESTO:\n{req['contesto']}\n\n" if req.get("contesto") else "")
            + f"DOMANDA:\n{req['domanda']}\n\n{nota}OPZIONE SCELTA DALLO STUDENTE (sbagliata o incompleta):\n{req['risposta'] or '(nessuna)'}\n\n"
            + f"OPZIONE DA SCEGLIERE (risposta ufficiale):\n{req['corretta']}\n\nSOLUZIONE DI RIFERIMENTO:\n{req.get('soluzione', '')}"
            + (f"\n\nINDICE DEGLI APPUNTI (numero titolo):\n{indice}" if indice else ""))
    out = ask(EXPLAIN, user, effort="medium")
    scelte = pick_sezioni(out.get("sezioni") or [], sezioni) or sezioni_per_titolo(req["domanda"], sezioni)
    return {"spiegazione": fix_latex(str(out.get("spiegazione", ""))), "appunti": scelte, "modello": MODEL}


def loose_json(text):
    """JSON dal modello, tollerante: backslash LaTeX non escapati (\\prod, \\sigma…) e testo attorno."""
    text = text[text.find("{"):text.rfind("}") + 1]
    try:
        return json.loads(text, strict=False)
    except json.JSONDecodeError:
        return json.loads(re.sub(r'\\(?!["\\/bfnrtu])', r"\\\\", text), strict=False)


def ask(system, user, effort=None):
    body = {"model": MODEL, "temperature": 0, "response_format": {"type": "json_object"},
            "messages": [{"role": "system", "content": system}, {"role": "user", "content": user}]}
    if effort and "gpt-oss" in MODEL:
        body["reasoning_effort"] = effort   # più ragionamento: meno confusione su domande con negazioni
    for tentativo in range(3):
        r = urllib.request.Request(BASE.rstrip("/") + "/chat/completions", json.dumps(body).encode(),
                                   {"Content-Type": "application/json", "Authorization": f"Bearer {KEY}", "User-Agent": "esami/1"})
        try:
            with urllib.request.urlopen(r, timeout=90) as resp:
                return loose_json(json.load(resp)["choices"][0]["message"]["content"])
        except urllib.error.HTTPError as e:
            err = e.read().decode(errors="replace")
            if e.code == 429 and tentativo < 2:   # limite token/minuto del piano gratuito: aspetto quanto chiede e riprovo
                m = re.search(r"try again in ([\d.]+)(ms|s)", err)
                time.sleep(min(30, float(m.group(1)) / (1000 if m.group(2) == "ms" else 1) + 0.5) if m else 10)
                continue
            if e.code == 400 and "json_validate_failed" in err:   # JSON rotto: recupero il testo generato
                return loose_json(json.loads(err)["error"]["failed_generation"])
            raise RuntimeError(f"provider {e.code}: {err[:300]}")
    raise RuntimeError("Limite di richieste del piano gratuito raggiunto: riprova tra un minuto")


ROUTES = {"/api/grade": grade, "/api/explain": explain}


# PDF degli appunti (fuori dalla cartella del sito): /appunti/<materia>.pdf
APPUNTI_PDF = {"ingegneria-del-software": "3/ing_sfw/ing_sfw.pdf", "basi-di-dati": "3/basi_dati/basi_dati.pdf",
               "introduzione-apprendimento-automatico": "3/apprendimento/apprendimento.pdf"}


class Handler(SimpleHTTPRequestHandler):
    def do_GET(self):
        slug = self.path.split("?")[0].removeprefix("/appunti/").removesuffix(".pdf")
        if self.path.startswith("/appunti/") and slug in APPUNTI_PDF:
            f = ROOT.parent / APPUNTI_PDF[slug]
            if not f.exists():
                return self.send_error(404, "Appunti non trovati")
            data = f.read_bytes()
            self.send_response(200)
            self.send_header("Content-Type", "application/pdf")
            self.send_header("Content-Length", str(len(data)))
            self.end_headers()
            return self.wfile.write(data)
        return super().do_GET()

    def end_headers(self):
        # niente cache: dopo ogni modifica a index.html/data.js il browser prende sempre la versione nuova
        self.send_header("Cache-Control", "no-store")
        super().end_headers()

    def do_POST(self):
        if self.path not in ROUTES:
            return self.send_error(404)
        try:
            if not KEY:
                raise RuntimeError("Nessuna chiave: crea il file esami/.ai_key con la tua API key (vedi README in testa a server.py)")
            req = json.loads(self.rfile.read(int(self.headers["Content-Length"])))
            res, code = ROUTES[self.path](req), 200
        except urllib.error.HTTPError as e:
            res, code = {"errore": f"provider {e.code}: {e.read().decode(errors='replace')[:300]}"}, 502
        except Exception as e:  # ponytail: errori mostrati così come sono nella pagina
            res, code = {"errore": str(e)}, 500
        data = json.dumps(res, ensure_ascii=False).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)


if __name__ == "__main__":
    port = int(os.environ.get("PORT", 8000))
    print(f"http://localhost:{port}  ·  modello {MODEL}  ·  chiave {'OK' if KEY else 'MANCANTE (.ai_key)'}")
    ThreadingHTTPServer(("127.0.0.1", port), partial(Handler, directory=str(ROOT))).serve_forever()
