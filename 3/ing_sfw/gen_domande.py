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
NOTES=[re.sub(r"\\[a-zA-Z]+\*?|[{}\\$&%]"," ",l).lower() for l in open("/home/nico/Desktop/uni/3/ing_sfw/ing_sfw.tex",encoding="utf-8").read().split("\n")]
STOP=set("quale seguenti software siano sistema sistemi viene essere questo questa dell dello della delle degli cosa come quali quando sono nella nello nelle dopo prima altro altri altre ogni solo anche parte detto detta tutti tutte secondo".split())
def stems(t): return {w[:5] for w in re.findall(r"[a-zàèéìòù]{5,}",t.lower()) if w not in STOP}
NS=[stems(l) for l in NOTES]
ALL=" ".join(NOTES)
def keys(t):
    k=re.findall(r'"([^"]+)"|«([^»]+)»',t); k=[a or b for a,b in k]
    k+=re.findall(r"(?<=[a-zà-ù,] )([A-Z][\w-]{3,})",t)+re.findall(r"\b([A-Z]{3,})\b",t)
    return [x.lower() for x in k]
def cover(st):
    if not st: return 1
    best=0
    for i in range(len(NS)):
        u=set().union(*NS[i:i+12]); best=max(best,len(st&u)/len(st))
    return best
COV=[]; THR=0.6
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
        opts = []; good = []
        for i,p in enumerate(parts):
            if i%2: txt += "\\begin{verbatim}\n"+p+"\\end{verbatim}\n"
            else:
                for line in p.split("\n"):
                    mo = re.match(r"- \[[ x]\] (.*)", line)
                    if mo:
                        opts.append(esc(mo.group(1)))
                        if line.startswith("- [x]"): good.append(mo.group(1))
                    elif line.strip(): txt += esc(line.lstrip("> "))+"\n\n"
        tg=tags(q,body,opts)
        s = "\\needspace{8\\baselineskip}\n\\subsection*{Domanda @N@%%s \\hfill {\\small %s, %s pt \\textcolor{gray}{(%s)}}}\n%s%s\n%s\n" % (kind, pts, esc(title), ctx if kind=="aperta" else "", esc(q), txt)
        bold = re.findall(r"\*\*([^*]+)\*\*", sec.partition("### Soluzione")[2]) if kind=="aperta" else []
        ks=keys(q+" "+" ".join(good))
        cv=1 if kind=="aperta" else (1 if ks and all(k in ALL for k in ks) else cover(stems(q+" "+" ".join(good))))
        bad=(bool(tg) and not TOP[tg[0]]["studiato"]) or cv<THR
        COV.append((cv,bad,q[:60]))
        s=s.replace("@N@%s","@N@"+(" X" if bad else ""))
        if opts: s += "\\begin{enumerate}[label=\\alph*)]\n"+"".join("\\item "+o+"\n" for o in opts)+"\\end{enumerate}\n"
        s += "\\vspace{%s}\n\\noindent\\textbf{Risposta:}\\par\n\\vspace{%s}\\hrule\n\n" % ("0.2cm", "4cm" if kind=="aperta" else "1.5cm")
        sol = sec.partition("### Soluzione")[2].split("### Griglia")[0].strip()
        sp = re.split(r"```\w*\n(.*?)```", sol, flags=re.S); st = ""
        for i,pp in enumerate(sp):
            if i%2: st += "\\begin{verbatim}\n"+pp+"\\end{verbatim}\n"
            else: st += "\n\n".join(esc(l) for l in pp.split("\n") if l.strip())+"\n\n"
        ans = ""
        if kind=="mcq":
            ol=[l for l in body.split("\n") if re.match(r"- \[[ x]\]",l)]
            ans = ", ".join("abcdefgh"[i] for i,l in enumerate(ol) if l.startswith("- [x]"))
        S = "\\needspace{4\\baselineskip}\n\\subsection*{Domanda @N@%s \\hfill {\\small \\textcolor{gray}{(%s)}}}\n%s%s\n" % (" X" if bad else "", esc(title), ("\\textbf{Risposta: %s}\\par\n" % ans) if ans else "", st)
        Qs.append((tg[0] if tg else None, s, S))
out=[]; outS=[]
for t in SEQ+[None]:
    g=[(x,y) for k,x,y in Qs if k==t]
    if not g: continue
    nm="Altro (domande trasversali)" if t is None else TOP[t]["nome"]+("" if TOP[t]["studiato"] else " [X] non ancora visto")
    out.append("\\section{%s}\n" % nm.replace("&","\\&") if t is None else "\\section{%s}\n" % nm.replace("&","\\&"))
    outS.append(out[-1])
    for x,y in g:
        n+=1; out.append(x.replace("@N@",str(n),1)); outS.append(y.replace("@N@",str(n),1))
pre = r"""\documentclass[a4paper,11pt]{article}
\usepackage[margin=2cm]{geometry}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\DeclareUnicodeCharacter{2264}{\ensuremath{\\leq}}
\DeclareUnicodeCharacter{2265}{\ensuremath{\\geq}}
\DeclareUnicodeCharacter{2212}{\ensuremath{-}}
\DeclareUnicodeCharacter{2194}{\ensuremath{\\leftrightarrow}}
\DeclareUnicodeCharacter{230A}{\ensuremath{\\lfloor}}
\DeclareUnicodeCharacter{230B}{\ensuremath{\\rfloor}}
\DeclareUnicodeCharacter{2192}{\ensuremath{\\to}}
\DeclareUnicodeCharacter{2260}{\ensuremath{\\neq}}

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
\textbf{X} = argomento non ancora visto, oppure la risposta non risulta scritta nei tuoi appunti (controllo automatico: può sbagliare, nel dubbio meglio una X in più).
\bigskip
\tableofcontents
\newpage
"""
open(sys.argv[1],"w").write(pre+"\n".join(out)+"\n\\end{document}\n")
if len(sys.argv)>2:
    pS=pre.replace("domande d'esame","soluzioni").replace("\\textbf{X} =","\\textbf{X} (come nelle domande) =")
    open(sys.argv[2],"w").write(pS+"\n".join(outS)+"\n\\end{document}\n")
print(n,"domande")
if os.environ.get("COVDBG"):
    for c,b,q in sorted(COV)[:40]: print(round(c,2),b,q)
    print(sum(b for _,b,_ in COV),"X su",len(COV))
