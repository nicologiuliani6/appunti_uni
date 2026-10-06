---
titolo: Scritto 2020 (A) – Mostre, Iscrizioni, ARIES
durata: 90
fonte: Soluzioni ufficiali incomplete (manca l'esercizio 1 a risposta multipla). Punteggi stimati da Claude.
---

## [aperta 8] Si vuole modellare l'archivio di una agenzia che organizza mostre. Si disegni uno schema E/R che modelli la realtà descritta integrandolo se necessario con business rules.
- Ogni mostra si compone di alcune opere, ognuna esposta in una o più sale.
- Le mostre sono identificate dal nome e dall'anno di edizione.
- Le opere sono identificate dal titolo e dall'autore (più autori possono produrre opere con lo stesso titolo).
- Di ogni artista si vuole memorizzare il nome, oltre a un codice univoco che lo identifica.
- Ogni sala è situata in un palazzo, ed è identificata dal proprio nome (univoco solamente all'interno del palazzo di appartenenza).
- Di ogni palazzo vogliamo conoscere nome e città (che lo identificano univocamente) e indirizzo.

### Soluzione
![Schema ER ufficiale](pdf/fig/bd-2020a-er.png)

- **Artista** (codice, nome) — *autore* (0,N) — **Opera** (1,1); Opera identificata da **titolo + Artista** (identificatore esterno).
- **Palazzo** (nome + città, indirizzo) — *locazione* (0,N) — **Sala** (1,1); Sala identificata da **nome + Palazzo** (esterno).
- **Mostra** (nome + anno).
- Relazione **ternaria** *relatività* Opera–Sala–Mostra: un'opera in una mostra è esposta in una o più sale (tutte (0,N) o (1,N) a seconda di come si legge "alcune opere").

Business rule possibili: un'opera inclusa in una mostra è esposta in almeno una sala; una stessa sala non ospita due mostre diverse nello stesso anno.

### Griglia
- 2 | Identificatore esterno di Opera (titolo + artista)
- 2 | Identificatore esterno di Sala (nome + palazzo), palazzo con id composto
- 2 | Relazione tra opera, mostra e sala (ternaria) con cardinalità
- 1 | Mostra con id (nome, anno)
- 1 | Business rule sensate

## Contesto
Sono date le seguenti relazioni:
- Persona(<u>ID</u>, Nome, Cognome, Eta)
- Iscrizione(<u>Persona</u>, <u>Corso</u>)
- Corso(<u>Nome</u>, Prezzo)

## [aperta 3] Selezionare in Algebra Relazionale gli ID delle persone che partecipano ad almeno un corso a cui partecipa anche la persona con ID 45.

### Soluzione
$$\pi_{Persona}\big(Iscrizione \bowtie \pi_{Corso}(\sigma_{Persona=45}(Iscrizione))\big)$$
(Il risultato include anche 45 stesso; per escluderlo: $\sigma_{Persona \ne 45}$.)

### Griglia
- 1 | Corsi di 45 (selezione + proiezione)
- 1 | Join naturale su Corso
- 1 | Proiezione su Persona

## [aperta 3] Selezionare in SQL gli ID delle persone che partecipano ad almeno un corso a cui partecipa anche la persona con ID 45.

### Soluzione
```sql
SELECT DISTINCT Persona
FROM Iscrizione
WHERE Corso IN (SELECT Corso FROM Iscrizione WHERE Persona = 45);
```

### Griglia
- 1 | Sottoquery sui corsi di 45
- 1 | IN (o join equivalente)
- 1 | DISTINCT

## [aperta 4] Selezionare in SQL quanto paga mediamente una persona in iscrizioni, al variare dell'età (suggerimento: utilizzare una vista per calcolare quanto paga ogni persona in totale, poi calcolare la media per età).

### Soluzione
```sql
CREATE VIEW Paga AS
SELECT P.ID, P.Eta, SUM(C.Prezzo) AS PrezzoTot
FROM Persona P JOIN Iscrizione I ON P.ID = I.Persona
               JOIN Corso C ON I.Corso = C.Nome
GROUP BY P.ID, P.Eta;

SELECT Eta, AVG(PrezzoTot) AS Media
FROM Paga
GROUP BY Eta;
```
Serve la vista: `AVG(SUM(...))` annidato non è ammesso in SQL standard.

### Griglia
- 2 | Vista con SUM per persona (join a tre tabelle)
- 2 | Media per età sulla vista

## Contesto
**Recovery (ARIES).** Il valore di un elemento A di un database è inizialmente **10**. Tale valore viene modificato da una singola transazione T. Ecco in ordine cronologico le operazioni compiute dalla transazione (numerate 1–4), le operazioni di salvataggio di A e del log su disco, e il crash:
1. `1) A := A + 2;`
2. Flush del file di log su disco.
3. Salvataggio di A da buffer pool a disco.
4. `2) A := A + 2;`
5. `3) A := A + 2;`
6. Flush del file di log su disco.
7. `4) A := A + 2;`
8. Crash di sistema.

La transazione **non** ha fatto commit.

## [aperta 1] Come appare il file di log al riavvio del sistema, prima della fase di recovery? (indicare solo i numeri delle operazioni loggate)

### Soluzione
**1, 2, 3** — l'operazione 4 era solo nel buffer del log, mai flushata.

### Griglia
- 1 | 1, 2, 3

## [num 1 = 12] Qual è il valore associato ad A su disco (al riavvio)?

### Soluzione
A è stato scritto su disco solo dopo l'operazione 1: **12**.

## [aperta 1] Quali operazioni vengono rieseguite durante la fase di REDO (ARIES)?

### Soluzione
**2, 3**. ARIES "ripete la storia" per tutte le operazioni nel log il cui effetto non è sulla pagina (pageLSN = 1, quindi la 1 è già su disco).

### Griglia
- 1 | 2 e 3 (non 1, già su disco)

## [num 1 = 16] Qual è il valore di A dopo la fase di REDO?

### Soluzione
12 + 2 + 2 = **16**.

## [aperta 1] Quali operazioni vengono eseguite durante la fase di UNDO? (indicare con apice le compensazioni, es. 2' compensa 2)

### Soluzione
**3', 2', 1'** in ordine inverso: T non ha fatto commit, quindi è una *loser transaction* e va annullata completamente (vengono scritti i CLR).

### Griglia
- 1 | 3' 2' 1' in ordine inverso

## [aperta 1] Come si presenta il file di log dopo la fase di UNDO?

### Soluzione
**1 2 3 3' 2' 1'** (i CLR vengono accodati al log).

### Griglia
- 1 | 1 2 3 3' 2' 1'

## [num 1 = 10] Qual è il valore di A dopo la fase di UNDO?

### Soluzione
16 − 6 = **10**, il valore iniziale.
