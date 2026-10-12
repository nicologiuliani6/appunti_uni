# LaTeX veloce in VS Code

Setup per compilare i `.tex` più in fretta, con il PDF aggiornato in una tab di VS Code a ogni salvataggio.
Testato il 12/10/2026 su Ubuntu 26.04, VS Code 1.140, TeX Live 2025, `apprendimento.tex` (1500 righe, 20 figure TikZ/pgfplots).

## In breve

| Cosa | Come | Risultato |
|---|---|---|
| Build al salvataggio, PDF in tab | LaTeX Workshop (`autoBuild.run: onSave`, `viewer: tab`) | come prima |
| Build veloce | script `latexmk-fast`: cache TikZ (`tikz external`) iniettata da riga di comando | ~2,5 s invece di ~8 s |
| Preview istantanea | TeXpresso in una finestra a fianco (opzionale) | < 1 s, ricompila solo da dove modifichi |

Il `.tex` **non viene modificato**: la cache è attivata solo dalla ricetta di compilazione.

## Dove vanno i tempi (misure su `apprendimento.tex`)

- Preambolo (16 pacchetti): ~1,1 s
- Testo: ~1,2 s
- TikZ/pgfplots (20 figure): ~5 s, cioè il collo di bottiglia vero
- `-draftmode` e meno pacchetti non servono: il tempo è nei disegni, non nelle immagini PNG.

| Caso | Tempo |
|---|---|
| Build normale senza cache | ~8 s |
| Prima build con cache vuota | ~40 s (una volta per documento) |
| Modifica al testo, cache calda | ~2,9 s (tutte le figure riusate) |
| Modifica a una figura | ~7,5 s (ne rigenera una sola) |

## Perché non una compilazione parziale "classica"

- `\include` + `\includeonly` richiede il file spezzato in capitoli e forza un salto pagina a ogni `\include`: la preview avrebbe un layout diverso dal PDF finale.
- I tuoi documenti sono file unici da 1500-2600 righe senza `\include`.
- L'unico vero incrementale su file unico è **TeXpresso** (fa il fork del processo TeX per pagina e riparte dalla pagina modificata), ma il suo viewer è una finestra SDL separata, non una tab di VS Code.
- Quindi: cache delle figure per la build "vera" nella tab, TeXpresso (opzionale) per la preview istantanea.

## Installazione

### 1. Script `~/.local/bin/latexmk-fast`

```bash
#!/usr/bin/env bash
# latexmk + cache TikZ/pgfplots (tikz external) iniettata da riga di comando, senza toccare il .tex.
# La cache si invalida da sola se cambia il preambolo (o questo script).
set -e
f="$1"
mkdir -p tikz-cache
cat > tikz-cache/inject.tex <<'EOF'
\AddToHook{begindocument/before}{\usetikzlibrary{external}\tikzexternalize[prefix=tikz-cache/]\tikzset{external/system call={pdflatex -shell-escape -halt-on-error -interaction=batchmode -jobname "\image" "\string\input{tikz-cache/inject.tex}\texsource"}}}
EOF
h=$( { sed '/\\begin{document}/q' "$f"; cat tikz-cache/inject.tex; } | md5sum | cut -d' ' -f1)
if [ "$(cat tikz-cache/.hash 2>/dev/null)" != "$h" ]; then
  find tikz-cache -type f ! -name inject.tex -delete
  echo "$h" > tikz-cache/.hash
fi
exec latexmk -pdf -shell-escape -synctex=1 -interaction=nonstopmode -file-line-error -halt-on-error \
  -jobname="$(basename "${f%.tex}")" \
  -pdflatex='pdflatex %O "\input{tikz-cache/inject.tex}\input{%S}"' "$f"
```

Poi: `chmod +x ~/.local/bin/latexmk-fast`.

### 2. `settings.json` utente di VS Code

```json
"latex-workshop.latex.autoBuild.run": "onSave",
"latex-workshop.view.pdf.viewer": "tab",
"latex-workshop.latex.autoClean.run": "never",
"latex-workshop.latex.tools": [
  { "name": "latexmk-fast", "command": "/home/nico/.local/bin/latexmk-fast", "args": ["%DOC_EXT%"], "env": {} }
],
"latex-workshop.latex.recipes": [
  { "name": "latexmk fast (tikz cache)", "tools": ["latexmk-fast"] }
],
"latex-workshop.latex.recipe.default": "first",
"texpresso.command": "/home/nico/texpresso/build/texpresso"
```

Vale per **tutti** i `.tex` (impostazioni utente). Per limitarla a un progetto, metti `tools` e `recipes` in `.vscode/settings.json` di quel progetto.

### 3. Git

`~/.config/git/ignore` (globale) ignora `tikz-cache/` e i file di build LaTeX (`*.aux`, `*.log`, `*.out`, `*.toc`, `*.fdb_latexmk`, `*.fls`, `*.synctex.gz`, `*.auxlock`, ...). I `.pdf` non sono ignorati.

### 4. TeXpresso (opzionale, preview istantanea)

```bash
git clone --depth 1 https://github.com/let-def/texpresso ~/texpresso
sudo apt install build-essential pkg-config libsdl2-dev libmupdf-dev libmujs-dev libfreetype-dev \
  libgumbo-dev libjbig2dec0-dev libjpeg-dev libopenjp2-7-dev cargo libssl-dev libfontconfig-dev \
  libleptonica-dev libharfbuzz-dev
cd ~/texpresso && make texpresso texpresso-xetex      # servono ENTRAMBI i binari
code --install-extension DominikPeters.texpresso-basic
```

Uso: apri il `.tex` radice, `Ctrl+Shift+P` → **TeXpresso: Start Document**. Si apre una finestra separata. Per fermarlo: **TeXpresso: Stop**.

## Uso quotidiano

1. Apri il `.tex`, `Ctrl+Alt+V` per aprire il PDF in tab.
2. Salva: si ricompila da solo (~2,5 s).
3. Il **primo** salvataggio di ogni documento con TikZ è lento (~40 s): genera la cache. Non salvare di nuovo mentre gira.

## Problemi incontrati e come sono stati risolti

| Sintomo | Causa | Soluzione |
|---|---|---|
| `TeXpresso exited with code null` | mancava il motore `texpresso-xetex` (avevo compilato solo `make texpresso`) | `make texpresso-xetex` |
| Comando TeXpresso non nel Command Palette | VS Code aperto prima dell'installazione / testo incompleto nella ricerca | riavvio completo, cercare `TeXpresso: Start Document` |
| Pagina 51 del PDF con l'indice dentro; build iniziale da 2+ minuti | il processo figlio di `tikz external` non riceveva l'iniezione e compilava l'intero documento per ogni figura (PDF di 31 pagine in cache) | iniezione anche nel figlio tramite `external/system call` con `\input{tikz-cache/inject.tex}` |
| `! I can't write on file '.tikz-cache/...'` | `openout_any=p` di TeX vieta di scrivere in cartelle nascoste (`.xxx`) | cartella `tikz-cache/` senza punto |
| `Undefined control sequence \pgfexternal@originalshipout` | `\AtBeginDocument` troppo tardi: altri hook (es. hyperref) toccano `\shipout` prima | `\AddToHook{begindocument/before}` |
| `\jobname` diventava `inject` / `texput` | il primo file aperto determina il jobname | `-jobname=<nome documento>` |
| Il testo dopo `%` spariva | `%` nella stringa da riga di comando commenta il resto | niente `%` né newline nell'iniezione: file `inject.tex` separato |
| Virgolette annidate rompevano il comando | `"` dentro `"` nella shell | iniezione in un file, non inline |
| Cache sbagliata riusata dopo la correzione | TikZ riusa una figura se il suo codice non cambia, anche se il PDF era corrotto | l'hash del preambolo + script azzera la cache da solo |

## Limiti noti

- `-shell-escape` è attivo per tutti i documenti: ok per i tuoi file, **non aprire con questa ricetta `.tex` di sconosciuti**.
- L'invalidazione automatica guarda il preambolo del file **principale**. Se il preambolo sta in un file incluso con `\input`, una modifica lì non azzera la cache: salva una modifica nel `.tex` principale oppure cancella `tikz-cache/`.
- Se un documento usa già `\tikzexternalize` nel suo preambolo, può dare conflitto: rimuovi quella riga.
- Le figure TikZ che dipendono da dati esterni (file letti da `pgfplots`) non vengono rigenerate se cambia solo il file dati: cancella `tikz-cache/`.
- TeXpresso usa un motore XeTeX interno: la preview può differire dal PDF finale con pacchetti particolari. Il PDF definitivo è quello della tab.
- Il preambolo precompilato (`mylatexformat`) non è stato usato: avrebbe fatto risparmiare solo ~1 s.

## Se qualcosa va storto

- Cancella `tikz-cache/` nella cartella del documento e salva di nuovo.
- Guarda **Output → LaTeX Workshop** in VS Code per l'ultimo errore.
- Prova lo script a mano: `cd cartella_documento && ~/.local/bin/latexmk-fast documento.tex`.
- Torna alla build normale: in `settings.json` metti il recipe predefinito di LaTeX Workshop (`"latex-workshop.latex.recipe.default": "lastUsed"` e scegli "latexmk").
