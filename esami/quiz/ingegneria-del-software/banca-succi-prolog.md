---
titolo: Banca esercitazioni · Introduzione a Prolog (Succi, L05 bis)
durata: 25
fonte: Domande scritte da Claude sulle slide L05 bis «Introduction to Prolog» di Succi (Modulo 2). Non sono domande ufficiali del docente; Prolog non compare negli scritti 2015-2025.
---

## [mcq 1] Quale di queste inferenze NON è valida?
- [ ] Da A → B e A si conclude B (modus ponens).
- [ ] Da A → B e ¬B si conclude ¬A (modus tollens).
- [x] Da A → B e B si conclude A.
- [ ] Da A → B e B → C e A si conclude C.

### Soluzione
Affermare il conseguente è una fallacia: la strada bagnata non implica che piova. Modus ponens e tollens sono validi e si possono concatenare.

## [mcq 1] In Prolog, la risposta `false.` alla query `?- parent(tom, ann).` significa:
- [ ] che è dimostrato che tom non è genitore di ann
- [x] che dal programma non si riesce a dimostrare il goal
- [ ] che la query contiene un errore di sintassi
- [ ] che il goal va in ciclo infinito

### Soluzione
`false` vuol dire «non dimostrabile dal programma», non «falso nel mondo». Prolog applica solo il modus ponens all'indietro su clausole di Horn: non confuta, quindi non va letto come un modus tollens.

## [mcq 1] Quale risultato dà Prolog per `?- f(X, X) = f(a, Y).`?
- [ ] false
- [ ] X = a, Y libera
- [x] X = a, Y = a
- [ ] errore: Y non è legata

### Soluzione
Unificazione argomento per argomento: X = a dalla prima coppia, poi la seconda diventa a = Y, quindi Y = a. I legami si propagano.

## [mcq 1] Quale risultato dà Prolog per `?- X = 2 + 3.`?
- [ ] X = 5
- [x] X = 2+3
- [ ] false
- [ ] errore di tipo

### Soluzione
`=` è unificazione, non valutazione: `2 + 3` è il termine composto `+(2,3)`. Per calcolare serve `X is 2 + 3` (X = 5); `=:=` confronta due espressioni valutate.

## [mcq 1] In Prolog, con le clausole `app([], L, L).` e `app([H|T], L, [H|R]) :- app(T, L, R).`, quante soluzioni dà `?- app(X, Y, [1, 2]).`?
- [ ] 1
- [ ] 2
- [x] 3
- [ ] infinite

### Soluzione
X = [], Y = [1,2]; X = [1], Y = [2]; X = [1,2], Y = []. La stessa relazione concatena e spezza le liste, perché l'unificazione funziona in entrambe le direzioni.

## [aperta 3] In Prolog, le clausole `ancestor2(X,Y) :- parent(X,Y).` e `ancestor2(X,Y) :- ancestor2(Z,Y), parent(X,Z).` hanno lo stesso significato logico di `ancestor` con la chiamata ricorsiva in fondo, ma `?- ancestor2(tom, X).` dopo le risposte va in stack overflow. Perché?

### Soluzione
Prolog risolve i goal da sinistra a destra e le clausole dall'alto in basso, con una ricerca in profondità. Esaurite le risposte, chiama `ancestor2(Z, Y)` con entrambi gli argomenti liberi, e questa richiama sé stessa prima che un `parent` possa restringere la ricerca: discesa infinita. La lettura dichiarativa è identica, quella procedurale no. Regola: caso base per primo e ricorsione dopo un goal che restringe.

### Griglia
- 1 | strategia di Prolog: goal da sinistra, clausole dall'alto, in profondità con backtracking
- 1 | ricorsione sinistra con argomenti liberi, quindi nessun goal che fermi la discesa
- 1 | distinzione tra lettura dichiarativa e procedurale, e il rimedio
