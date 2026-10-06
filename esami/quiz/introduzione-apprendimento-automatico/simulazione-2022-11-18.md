---
titolo: Simulazione quiz 18/11/2022 (6 domande)
durata: 10
fonte: Screenshot del quiz Virtuale con risposte ufficiali; spiegazioni di Claude.
---

## [mcq 1] Selezionare la sentenza ERRONEA riguardo agli alberi di decisione
- [x] Possono essere utilizzati solo con features discrete
- [ ] Il costo computazionale della predizione è molto basso
- [ ] Hanno una forte tendenza all'overfitting
- [ ] Possono esprimere qualunque funzione di classificazione

### Soluzione
Gli alberi gestiscono anche features continue con test a soglia ($x_j < t$).

## [mcq 1] Perchè la tecnica Naive Bayes è detta "naive" (ingenua)?
- [x] Perchè suppone ingenuamente che le features siano indipendenti tra loro, date le classi
- [ ] Perchè suppone ingenuamente che i dati di training rispecchino i dati reali
- [ ] Perchè fornisce un modo semplice ma preciso di calcolare la distribuzione congiunta di probabilità delle features
- [ ] Perchè suppone ingenuamente che la teoria possa avere applicazioni pratiche

### Soluzione
$P(x_1,\dots,x_n|c) = \prod_j P(x_j|c)$: indipendenza condizionale data la classe.

## [mcq 1] Che cosa si intende con apprendimento supervisionato?
- [ ] Apprendimento sotto la supervisione diretta di un esperto
- [ ] Apprendimento che tende a imitare il comportamento di un esperto
- [ ] Apprendimento che non fa uso di tecniche statistiche o probabilistiche
- [x] Apprendimento di funzioni basato su esempi di training composti da coppie input-output

### Soluzione
Dati etichettati (input, output atteso).

## [mcq 1] Quale delle seguenti affermazioni relative alla backpropagation è corretta?
- [x] Si effettua solo durante il "training"
- [ ] Viene fatta sia durante la fase di "inference" (calcolo in avanti) che in quella di "training"
- [ ] E' molto più costosa, in termini di tempo, del calcolo "in avanti" (inference) lungo la rete
- [ ] Viene effettuata unicamente lungo le skip connections delle reti residuali, per evitare perdita del gradiente

### Soluzione
Serve a calcolare i gradienti per aggiornare i pesi: solo in training; costo dello stesso ordine del forward.

## [mcq 1] Selezionare la sentenza corretta
- [ ] Il numero dei parametri di un neurone artificiale è quadratico nella dimensione dei suoi input
- [x] Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dalla applicazione di una funzione di attivazione non lineare
- [ ] Un neurone artificiale può apprendere qualunque funzione dei suoi input
- [ ] Un neurone artificiale può apprendere solo funzioni lineari

### Soluzione
$y = f(w\cdot x + b)$: n+1 parametri (lineare); con attivazione non lineare non è solo lineare, ma separa solo linearmente.

## [mcq 1] Il problema della scomparsa del gradiente (vanishing gradient) si riferisce a una progressiva diminuzione dell'intensità del gradiente, dovuta a
- [x] backpropagation in reti profonde
- [ ] dati troppo rumorosi o malamente preprocessati
- [ ] troppi pochi dati di training a disposizione
- [ ] training eccessivamente lungo

### Soluzione
La regola della catena moltiplica le derivate layer per layer: con molti layer (e sigmoidi, derivata ≤ 1/4) il gradiente si attenua esponenzialmente.
