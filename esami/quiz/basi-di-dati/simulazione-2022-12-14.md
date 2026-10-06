---
titolo: Simulazione scritto 14/12/2022
durata: 120
fonte: Testo ufficiale; soluzioni del tutor (lavagna), riviste da Claude (query SQL 2 corretta: soglie sbagliate nella trascrizione). Punteggi stimati.
---

## [mcq 1.5] Il comando `DELETE FROM Utenti WHERE alias='gino'` dove alias è una primary key:
- [x] elimina zero o una riga.
- [ ] elimina un numero imprecisato di righe.
- [ ] elimina una tabella.
- [ ] elimina le tabelle con alias 'gino' nel database Utenti.

### Soluzione
Chiave primaria → al più una tupla con quel valore.

## [mcq 1.5] Le cardinalità delle relazioni in uno schema E-R:
- [ ] si riferiscono al numero di operazioni possibili su un'entità.
- [ ] possono contenere valori negativi.
- [ ] sono il prodotto della cardinalità delle due entità coinvolte.
- [x] dicono quante volte un'occorrenza di un'entità può essere legata a occorrenze di un'altra entità.

### Soluzione
Coppia (min, max) per ogni partecipazione di un'entità a una relazione.

## [mcq 1.5] Data la relazione R(A, B, C):
- [ ] $\pi_{AB}(R)$ può avere meno ennuple di R.
- [ ] $\pi_{A}(R)$ può avere più ennuple di R.
- [x] $\pi_{B}(R)$ può avere meno ennuple di R.
- [ ] $\pi_{BC}(R)$ ha un numero di ennuple uguale a R.

### Soluzione
La proiezione elimina i duplicati, quindi può ridurre le ennuple, mai aumentarle. Risposta ufficiale (c). Nota: anche (a) è vera se AB non è superchiave; il tutor ha indicato (c).

## [mcq 1.5] La clausola HAVING:
- [ ] si usa ogni volta che abbiamo un GROUP BY.
- [x] può essere usata solo su predicati con operatori aggregati.
- [ ] può essere usata indistintamente al posto di WHERE.
- [ ] nessuna delle precedenti.

### Soluzione
Risposta del tutor: (b) — HAVING filtra i **gruppi**, quindi i suoi predicati sono su aggregati (o attributi di raggruppamento, che il tutor considera parte del GROUP BY). A rigore SQL ammette anche predicati sui soli attributi del GROUP BY, quindi alcuni direbbero (d).

## [mcq 1.5] Nel modello relazionale:
- [ ] ogni relazione ha una o più chiavi.
- [ ] ogni relazione ha esattamente una superchiave.
- [x] possono esistere più superchiavi e una di esse può coinvolgere tutti gli attributi.
- [ ] possono esistere più chiavi e una di esse può coinvolgere tutti gli attributi.

### Soluzione
L'insieme di tutti gli attributi è sempre superchiave (non ci sono tuple duplicate). (d) è falsa: se una chiave contiene tutti gli attributi, ogni altra chiave ne sarebbe un sottoinsieme, contro la minimalità. Risposta ufficiale (c); anche (a) è vera in teoria (ogni relazione ha almeno una chiave).

## [mcq 1.5] L'operatore di join naturale:
- [x] è commutativo e associativo.
- [ ] è commutativo ma non associativo.
- [ ] è associativo ma non commutativo.
- [ ] nessuna delle precedenti.

### Soluzione
$R \bowtie S = S \bowtie R$ e $(R \bowtie S) \bowtie T = R \bowtie (S \bowtie T)$ (gli attributi sono identificati per nome, l'ordine non conta).

## Contesto
**Modello**

| idModello | idMarca | nome | categoria |
|---|---|---|---|
| 12111 | AX42 | H2 | SUV |
| 22122 | BY80 | Classe C | Berlina |
| 31333 | CZ12 | Clio | Utilitaria |

**Valutazione**

| idModello | anno | prezzo |
|---|---|---|
| 11234 | 2003 | 7000 |
| 11234 | 2008 | 9000 |
| 21234 | 2004 | 15000 |
| 21234 | 2005 | 16000 |
| 41234 | 2012 | 13000 |

**Marca**

| idMarca | marchio | nazionalità |
|---|---|---|
| US41 | Hummer | Stati Uniti |
| FS11 | Ferrari | Italia |
| CZ12 | Renault | Francia |
| DK15 | BMW | Germania |
| BY80 | Mercedes | Germania |

Il contenuto delle tabelle è solamente indicativo.

## [aperta 3] Scrivere in SQL una query che restituisca la media delle valutazioni per ogni modello di auto italiana, indicando anche la marca.

### Soluzione
```sql
SELECT Mo.idModello, Mo.nome, Ma.marchio, AVG(V.prezzo) AS media
FROM Valutazione V
JOIN Modello Mo ON V.idModello = Mo.idModello
JOIN Marca Ma   ON Mo.idMarca  = Ma.idMarca
WHERE Ma.nazionalità = 'Italia'
GROUP BY Mo.idModello, Mo.nome, Ma.marchio;
```

### Griglia
- 1 | Join a tre tabelle corretto
- 1 | Filtro nazionalità = 'Italia'
- 1 | GROUP BY per modello (con marca) e AVG

## [aperta 3] Scrivere in SQL una query che restituisca, per ogni anno dal 2000 al 2010, il conteggio delle berline tedesche con valutazione maggiore di 30000.

### Soluzione
```sql
SELECT V.anno, COUNT(*) AS n
FROM Valutazione V
JOIN Modello Mo ON V.idModello = Mo.idModello
JOIN Marca Ma   ON Mo.idMarca  = Ma.idMarca
WHERE Ma.nazionalità = 'Germania'
  AND Mo.categoria = 'Berlina'
  AND V.anno BETWEEN 2000 AND 2010
  AND V.prezzo > 30000
GROUP BY V.anno;
```

### Griglia
- 1 | Join e filtri nazionalità/categoria
- 1 | Filtri anno 2000–2010 e prezzo > 30000
- 1 | GROUP BY anno con COUNT

## [aperta 3] Scrivere in algebra relazionale un'espressione che restituisca le valutazioni delle berline prodotte dalle case francesi che non hanno valutazione per l'anno 2007.

### Soluzione
$$BF = \pi_{idModello}\big(\sigma_{categoria='Berlina' \wedge nazionalità='Francia'}(Modello \bowtie Marca)\big)$$
$$V07 = \pi_{idModello}\big(\sigma_{anno=2007}(Valutazione)\big)$$
$$(BF - V07) \bowtie Valutazione$$

### Griglia
- 1 | Berline francesi (join Modello–Marca + selezione)
- 1 | Differenza con i modelli valutati nel 2007
- 1 | Join finale con Valutazione

## [aperta 3] Scrivere in algebra relazionale un'espressione che restituisca le valutazioni superiori ai 15000, dall'anno 2005 al 2009, delle utilitarie non italiane.

### Soluzione
$$\pi_{idModello,anno,prezzo}\Big(\sigma_{prezzo>15000 \wedge anno\ge2005 \wedge anno\le2009}(Valutazione) \bowtie \sigma_{categoria='Utilitaria'}(Modello) \bowtie \sigma_{nazionalità \ne 'Italia'}(Marca)\Big)$$
(Equivalente: $Marca - \sigma_{nazionalità='Italia'}(Marca)$ al posto della selezione con ≠.)

### Griglia
- 1 | Selezione su prezzo e intervallo di anni
- 1 | Utilitarie non italiane
- 1 | Join corretti e proiezione

## [aperta 6] Progettazione concettuale: Flatmates. Disegnare il modello E-R indicando eventuali vincoli non esprimibili.
Si vuole progettare un database per una piattaforma gestionale delle spese di un appartamento. La piattaforma fa riferimento allo scenario in cui a coinquilini diversi di un appartamento sono intestate utenze diverse, e supporta la gestione del dare/avere tra coinquilini per quanto riguarda le bollette. Ogni utente che si registra si può dichiarare coinquilino di un appartamento, oppure crea un nuovo appartamento, definito con un nome di fantasia e un indirizzo. Non è possibile inserire un appartamento con lo stesso nome e lo stesso indirizzo. L'utente ha un id univoco per la piattaforma e può essere associato a non più di un appartamento. Un coinquilino può avere nessuna, una o più utenze a sé intestate, con un contratto riportante data di stipulazione, fornitore, tipologia (e.g., luce, acqua, gas, internet) e cadenza del pagamento in mesi. Quando arriva una bolletta questa viene registrata con i suoi dati: inizio e fine periodo, costo totale, scadenza del pagamento e codice identificativo. Il codice di una bolletta è univoco solo in relazione a un contratto. Uno qualunque dei coinquilini può pagare la bolletta, e successivamente gli altri possono pagargli la somma dovuta, relativa a una specifica bolletta. Queste operazioni vengono registrate insieme con la data in cui avvengono.

### Soluzione
![Soluzione del tutor](pdf/basi-di-dati/scritto-2022-12-14-soluzione-es3.jpeg)

- **Appartamento** (nome + indirizzo = id) — *abitazione* (1,N) — **Coinquilino** (id) (0,1).
- *intestazione*: Coinquilino (0,N) — **Contratto** (1,1) (codice, tipo, data, fornitore, cadenza).
- **Bolletta**: id esterno = codice + Contratto; attributi inizio/fine periodo, totale, scadenza — *appartenenza* Contratto (0,N) / Bolletta (1,1).
- *pagamento*: Coinquilino (0,N) — Bolletta (0,1), attributo data.
- *rimborso*: relazione ternaria Coinquilino (chi paga) – Coinquilino (chi riceve) – Bolletta, attributi data e importo.

Vincoli non esprimibili: la somma dei rimborsi di una bolletta è minore del suo totale; chi rimborsa e chi riceve abitano nello stesso appartamento dell'intestatario; si rimborsa solo chi ha pagato quella bolletta.

### Griglia
- 1 | Appartamento con id composto (nome, indirizzo), utente in al più un appartamento
- 1 | Contratto intestato al coinquilino con attributi
- 1 | Bolletta con identificatore esterno (codice + contratto)
- 2 | Pagamento e rimborsi tra coinquilini con data
- 1 | Vincoli non esprimibili

## [aperta 3] Indici B+Tree. Dato il seguente B+Tree, mostrare i passi della cancellazione della chiave K = 8.
![B+tree](pdf/fig/bd-2022-12-14-btree.png)

### Soluzione
Nodi con max 3 chiavi, min 2 nelle foglie.
1. Ricerca: radice [8 | 13], 8 ≤ 8 < 13 → foglia centrale [8, 11].
2. Rimuovo 8 → la foglia diventa [11]: **underflow**.
3. La sorella sinistra [2, 4, 5] ha una chiave in eccesso → **ridistribuzione**: le presta la chiave massima 5 → foglie [2, 4] e [5, 11].
4. Il separatore nel padre si aggiorna con la nuova chiave minima della foglia centrale: radice [5 | 13].

![Soluzione del tutor](pdf/basi-di-dati/scritto-2022-12-14-soluzione-es4.jpeg)

### Griglia
- 1 | Individua la foglia e rileva l'underflow
- 1 | Ridistribuzione dalla sorella (non merge, perché la sorella ha chiavi in più)
- 1 | Aggiorna il separatore nel padre (8 → 5)
