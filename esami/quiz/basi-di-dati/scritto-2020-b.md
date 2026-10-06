---
titolo: Scritto 2020 (B) – Parco naturale, Esami, Indici
durata: 90
fonte: Soluzioni ufficiali incomplete (scansione; manca l'esercizio 1). Punteggi stimati da Claude.
---

## [aperta 8] Si vuole modellare un parco naturale. Disegnare lo schema E/R con eventuali business rules.
- Il parco contiene alcune gabbie, ognuna identificata da un nome e collocata su un sentiero.
- Ogni sentiero è identificato dalla zona in cui esso si trova (ad esempio, zona rossa, o zona verde) e dal proprio nome (zone diverse possono contenere sentieri con lo stesso nome). Se ne vuole conoscere anche la lunghezza.
- Ogni gabbia contiene zero o più animali, tutti della stessa specie.
- Ogni animale ha un nome scientifico generico e un nome proprio.
- Il nome proprio dell'animale viene utilizzato per identificarlo, in quanto ogni gabbia contiene animali con nomi diversi tra di loro.
- Gabbie differenti possono però contenere animali con lo stesso nome proprio.
- In caso di malattia, gli animali vengono visitati da un veterinario, identificato dal codice di tesserino e di cui si vogliono sapere nome e cognome.
- Si vuole memorizzare ogni visita veterinaria (data e esito). Si assuma che uno stesso animale non possa essere visitato più volte nello stesso giorno.

### Soluzione
![Schema ER ufficiale](pdf/fig/bd-2020b-er.png)

- **Sentiero** (zona + nome, lunghezza) — *locazione* (0,N) — **Gabbia** (nome, 1,1).
- **Animale** (nome proprio + Gabbia = id esterno; specie, nome scientifico) — *dimora* (1,1) / Gabbia (0,N).
- **Visita** (data + Animale = id esterno; esito) — *somministrazione* Animale (0,N) / Visita (1,1).
- *esecuzione*: Visita (1,1) — **Veterinario** (codice, nome, cognome) (0,N).

BR: tutti gli animali di una gabbia devono essere della stessa specie.

### Griglia
- 2 | Sentiero con id composto (zona, nome) e gabbia collocata
- 2 | Animale con identificatore esterno (nome + gabbia)
- 2 | Visita con identificatore esterno (data + animale), esito, veterinario
- 1 | Cardinalità corrette
- 1 | BR stessa specie per gabbia

## Contesto
Sono date le seguenti relazioni:
- Studente(<u>Matricola</u>, Nome)
- Corso(<u>Codice</u>, Nome)
- Iscrizione(<u>Matricola</u>, <u>Codice</u>, Voto)

## [aperta 3] Selezionare in Algebra Relazionale i nomi distinti degli studenti iscritti a 'Algoritmi', utilizzando solamente: join naturale, proiezione, selezione.

### Soluzione
$$\pi_{Nome}\Big((Studente \bowtie Iscrizione) \bowtie \pi_{Codice}\big(\sigma_{Nome='Algoritmi'}(Corso)\big)\Big)$$
Attenzione: Studente e Corso hanno entrambi l'attributo **Nome**: proiettare Corso su Codice prima del join, altrimenti il join naturale impone anche Nome studente = Nome corso.

### Griglia
- 1 | Selezione del corso Algoritmi
- 1 | Proiezione su Codice prima del join (evita il conflitto su Nome)
- 1 | Join naturali e proiezione finale

## [aperta 3] Selezionare in SQL i nomi distinti degli studenti iscritti a corsi il cui codice comincia per A1933.

### Soluzione
```sql
SELECT DISTINCT S.Nome
FROM Studente S JOIN Iscrizione I ON S.Matricola = I.Matricola
WHERE I.Codice LIKE 'A1933%';
```

### Griglia
- 1 | Join Studente–Iscrizione
- 1 | LIKE 'A1933%'
- 1 | DISTINCT

## [aperta 4] Selezionare in SQL la media voto di ogni studente, solo per gli studenti con una media di almeno 28 e che hanno sostenuto almeno 4 esami.

### Soluzione
```sql
SELECT Matricola, AVG(Voto) AS Media
FROM Iscrizione
GROUP BY Matricola
HAVING AVG(Voto) >= 28 AND COUNT(Voto) >= 4;
```
`COUNT(Voto)` ignora i NULL (iscrizioni senza esame sostenuto), a differenza di `COUNT(*)`.

### Griglia
- 1 | GROUP BY Matricola
- 2 | HAVING con entrambe le condizioni (non WHERE)
- 1 | COUNT(Voto) per contare solo esami sostenuti

## [aperta 3] Definire la caratteristica principale di ciascuno dei seguenti tipi di indice: (1) sparso, (2) primario, (3) clustered.

### Soluzione
1. **Sparso**: non contiene un'entrata per ogni valore della chiave di ricerca presente nei record (tipicamente una per blocco); richiede file ordinato.
2. **Primario**: la chiave di ricerca contiene la chiave primaria.
3. **Clustered**: l'ordine dei record nel file di dati è uguale (o simile) all'ordine delle entrate dell'indice.

### Griglia
- 1 | Sparso
- 1 | Primario
- 1 | Clustered

## [aperta 3] Indicare il numero medio di blocchi a cui si deve accedere, su un file contenuto in B blocchi, per: (1) equality search su chiave primaria, heap file; (2) equality search, file ordinato sulla chiave di ricerca; (3) equality search, file ordinato su un attributo UNIQUE che non è la chiave di ricerca.

### Soluzione
1. **0.5·B**: scansione finché si trova il record (in media metà file; essendo chiave ci si ferma).
2. **log₂ B**: ricerca binaria.
3. **0.5·B**: l'ordinamento non aiuta, si comporta come un heap file.

### Griglia
- 1 | 0.5 B
- 1 | log2 B
- 1 | 0.5 B con motivazione
