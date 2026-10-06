#!/usr/bin/env python3
"""Serve il sito d'allenamento e inoltra /api/grade a un LLM con API OpenAI-compatibile (piano gratuito).

Uso:  python3 server.py   →  http://localhost:8000
Chiave: variabile AI_KEY oppure file .ai_key accanto a questo script (non va su git).
Provider di default: Groq. Per Gemini:
  AI_BASE=https://generativelanguage.googleapis.com/v1beta/openai AI_MODEL=gemini-2.5-flash python3 server.py
"""
import json, os, re, urllib.request, urllib.error
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
Formule LaTeX con i comandi completi di backslash (\\prod, \\sum, \\frac), dentro $...$.
Rispondi SOLO con JSON: {"spiegazione": "..."}"""


LATEX = re.compile(r"(?<![\\a-zA-Z])(prod|sum|frac|sigma|pi|bowtie|mid|log|cdot|neq|leq|geq|theta|mu|infty|wedge|vee|neg|in|cap|cup|sqrt|alpha|beta|lambda)(?=[_{^\s(\\|])")


def fix_latex(text):
    # il modello a volte dimentica il backslash dei comandi (es. $prod_i$): lo rimetto solo dentro $...$
    return re.sub(r"\$[^$]+\$", lambda m: LATEX.sub(r"\\\1", m.group(0)), text)


def explain(req):
    user = (f"MATERIA: {req['materia']}\n\n" + (f"CONTESTO:\n{req['contesto']}\n\n" if req.get("contesto") else "")
            + f"DOMANDA:\n{req['domanda']}\n\nRISPOSTA DELLO STUDENTE:\n{req['risposta'] or '(nessuna)'}\n\n"
            + f"RISPOSTA CORRETTA:\n{req['corretta']}\n\nSOLUZIONE DI RIFERIMENTO:\n{req.get('soluzione', '')}")
    return {"spiegazione": fix_latex(str(ask(EXPLAIN, user).get("spiegazione", ""))), "modello": MODEL}


def ask(system, user):
    body = {"model": MODEL, "temperature": 0, "response_format": {"type": "json_object"},
            "messages": [{"role": "system", "content": system}, {"role": "user", "content": user}]}
    r = urllib.request.Request(BASE.rstrip("/") + "/chat/completions", json.dumps(body).encode(),
                               {"Content-Type": "application/json", "Authorization": f"Bearer {KEY}", "User-Agent": "esami/1"})
    with urllib.request.urlopen(r, timeout=90) as resp:
        text = json.load(resp)["choices"][0]["message"]["content"]
    return json.loads(text[text.find("{"):text.rfind("}") + 1])


ROUTES = {"/api/grade": grade, "/api/explain": explain}


class Handler(SimpleHTTPRequestHandler):
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
