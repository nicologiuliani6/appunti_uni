# progetto-programmazione

# README - Progetto Programmazione

## Descrizione del Progetto
Questo progetto consiste in Snake implementato in C++. Utilizza la libreria `ncurses` per la gestione dell'interfaccia utente nel terminale. Il gioco permette ai giocatori di controllare un serpente che aumenta di punteggio mangiando mele, evitando di colpire se stesso.

## Struttura del Progetto
Il progetto è composto da diversi file sorgente e intestazioni, ognuno con una specifica funzionalità:

- **main.cpp**: Punto di ingresso, menu principale e loop di gioco.
- **gamemanager.hpp**: Gestione del gioco.
- **classifica.hpp / classifica.cpp**: Gestione della classifica dei giocatori, inclusa la lettura e scrittura su file.
- **sort.hpp / sort.cpp**: Funzioni di ordinamento per la classifica dei giocatori.
- **menu.hpp**: Interfaccia del menu principale
- **griglia.hpp / griglia.cpp**: Gestione della griglia di gioco.
- **levels.hpp / levels.cpp**: Definizione e gestione dei livelli di gioco.
- **snake.hpp / snake.cpp**: Implementazione della logica del serpente e delle sue interazioni.
- **points.hpp**: Gestione del punteggio e bonus

## Requisiti
- C++17 o superiore
- Terminale con dimensioni minime 24 righe × 14 colonne, supporto caratteri: ASCII standard
- Libreria `ncurses` installata

## Compilazione
Per compilare il progetto, utilizzare il seguente comando nel terminale:

```bash
make
```

Questo comando utilizza il `Makefile` fornito per compilare tutti i file sorgente e generare l'eseguibile del gioco.

## Esecuzione
Dopo la compilazione, eseguire il gioco con il seguente comando:

```bash
make run 
```

## Controlli
- Utilizzare WASD o le freccette per controllare il serpente.
- Mangiare le mele per guadagnare punti.
- Evitare di colpire il corpo del serpente.
- Usare + o - per passare da un livello all'altro, o digitare direttamente il numero del livello (1-5)

## Classifica
Alla fine di ogni partita, i giocatori possono inserire il proprio nome per registrare il punteggio nella classifica. La classifica viene visualizzata attraverso il menu principale.

## Livelli 
Ogni livello ha una durata specifica e una velocità del serpente, l'obiettivo è sopravvivere ai livelli di gioco e ottenere più punti possibili! Si può passare liberamente da un livelo all'altro.