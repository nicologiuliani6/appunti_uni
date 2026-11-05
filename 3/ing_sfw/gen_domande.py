import re, sys, glob, os
Q = "/home/nico/Desktop/uni/esami/quiz/ingegneria-del-software/"
ORDER = [("esempi-processo","Esempi ufficiali: processo"),("esempi-prodotto","Esempi ufficiali: prodotto"),
 ("esempi-aperte","Esempi ufficiali: aperte"),("scritto-2015-01-15","Scritto 15/01/2015"),
 ("scritto-2020-01-16","Scritto 16/01/2020"),("simulazione-2023-11-21","Simulazione 21/11/2023"),
 ("scritto-2025-01-10","Scritto 10/01/2025"),("scritto-2025-11-24","Preappello 24/11/2025")]
def esc(s):
    s = s.replace("\\","\\textbackslash{}")
    for a,b in [("&","\\&"),("%","\\%"),("$","\\$"),("#","\\#"),("_","\\_"),("{","\\{"),("}","\\}"),("~","\\textasciitilde{}"),("^","\\textasciicircum{}"),("<","\\textless{}"),(">","\\textgreater{}")]:
        s = s.replace(a,b)
    s = s.replace("\\textbackslash\\{\\}","\\textbackslash{}")
    s = re.sub(r"`([^`]*)`", lambda m:"\\texttt{"+m.group(1).replace("\\textbackslash{}","\\textbackslash ")+"}", s)
    s = re.sub(r"\*\*([^*]+)\*\*", r"\\textbf{\1}", s)
    s = re.sub(r"(?<!\w)\*([^*]+)\*(?!\w)", r"\\textit{\1}", s)
    return s
def sections(txt):
    txt = txt.split("---\n",2)[2]
    return [p for p in re.split(r"(?m)^## ", txt) if p.strip()]
import json
TOP=json.load(open("/home/nico/Desktop/uni/esami/topics.json"))["ingegneria-del-software"]
TOP={t["id"]:t for t in TOP}
# ordine come negli appunti; gli argomenti non visti in fondo
SEQ=["ciclo-vita","processo","xp","user-story","testing","git","uml-base","use-case","attivita","uml-classi","uml-dinamici","componenti","realtime","ocl","pattern","refactoring","architetture","crc","solid","linguaggi","python","llm"]
def tags(q,body,opts):
    f=lambda t:[i for i in SEQ if re.search(TOP[i]["re"],t,re.I)]
    return f(q+" "+body) or f(" ".join(opts))
Qs=[]; ctx=""; n=0
for f,title in ORDER:
    for sec in sections(open(Q+f+".md").read()):
        head, _, body = sec.partition("\n")
        body = body.split("### Soluzione")[0].split("### Griglia")[0].rstrip()
        if head.startswith("Contesto"):
            ctx="\\begin{tcolorbox}[colback=gray!8,colframe=gray!50,title=Contesto]\n"+esc(body.replace("> ","").strip())+"\n\\end{tcolorbox}\n"; continue
        m = re.match(r"\[(mcq|aperta) (\d+)\]\s*(.*)", head)
        kind, pts, q = m.groups()
        # codice in fence nel testo domanda: verbatim
        parts = re.split(r"```\w*\n(.*?)```", body, flags=re.S)
        txt = ""
        opts = []
        for i,p in enumerate(parts):
            if i%2: txt += "\\begin{verbatim}\n"+p+"\\end{verbatim}\n"
            else:
                for line in p.split("\n"):
                    mo = re.match(r"- \[[ x]\] (.*)", line)
                    if mo: opts.append(esc(mo.group(1)))
                    elif line.strip(): txt += esc(line.lstrip("> "))+"\n\n"
        tg=tags(q,body,opts)
        s = "\\needspace{8\\baselineskip}\n\\subsection*{Domanda @N@%%s \\hfill {\\small %s, %s pt \\textcolor{gray}{(%s)}}}\n%s%s\n%s\n" % (kind, pts, esc(title), ctx if kind=="aperta" else "", esc(q), txt)
        bad=bool(tg) and not TOP[tg[0]]["studiato"]
        s=s.replace("@N@%s","@N@"+(" X" if bad else ""))
        if opts: s += "\\begin{enumerate}[label=\\alph*)]\n"+"".join("\\item "+o+"\n" for o in opts)+"\\end{enumerate}\n"
        s += "\\vspace{%s}\n\\noindent\\textbf{Risposta:}\\par\n\\vspace{%s}\\hrule\n\n" % ("0.2cm", "4cm" if kind=="aperta" else "1.5cm")
        Qs.append((tg[0] if tg else None, s))
out=[]
for t in SEQ+[None]:
    g=[x for k,x in Qs if k==t]
    if not g: continue
    nm="Altro (domande trasversali)" if t is None else TOP[t]["nome"]+("" if TOP[t]["studiato"] else " [X] non ancora visto")
    out.append("\\section{%s}\n" % nm.replace("&","\\&") if t is None else "\\section{%s}\n" % nm.replace("&","\\&"))
    for x in g:
        n+=1; out.append(x.replace("@N@",str(n),1))
pre = r"""\documentclass[a4paper,11pt]{article}
\usepackage[margin=2cm]{geometry}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[italian]{babel}
\usepackage{enumitem}
\usepackage{needspace}
\usepackage[most]{tcolorbox}
\usepackage{hyperref}
\usepackage{xcolor}
\setlength{\parindent}{0pt}\setlength{\parskip}{4pt}
\title{Ingegneria del Software: domande d'esame}
\author{Nicolò Giuliani}
\date{}
\begin{document}
\maketitle
\tableofcontents
\newpage
"""
open(sys.argv[1],"w").write(pre+"\n".join(out)+"\n\\end{document}\n")
print(n,"domande")
