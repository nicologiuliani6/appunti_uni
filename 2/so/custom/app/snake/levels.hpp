#ifndef LEVELS_HPP
#define LEVELS_HPP

#include <iostream>
#include <ctime>

#define N 5

using namespace std;

// struttura del livello
struct lvl {
    int id;     // numero livello
    int vel;    // velocità serpente
    int bonus;  // bonus completamento
    int time;   // tempo in minuti
    lvl* next;
    lvl* prev;
};
typedef lvl* plvl;

// Funzioni esterne da levels.cpp
plvl createNode(int i, int v, int b, int t);
plvl enqueue(plvl head, const int i, const int v, const int b, int t);
plvl createList(plvl head, const int n);
plvl elementFromList(plvl head, int id);

// Funzioni temporali pure (senza stato)
time_t getCurrentTime();
time_t getEndTime(int minutes);
bool isTimeExpired(time_t start_time, int duration_minutes);
int getRemainingSeconds(time_t start_time, int duration_minutes);

class Livelli {
protected:
    lvl l[N];     // array livelli
    lvl current;  // livello corrente (copia)
    plvl head;    // puntatore alla lista dei livelli
    time_t level_start_time; // tempo di inizio del livello corrente

public:
    // Costruttore
    Livelli() {
        head = nullptr;
        head = createList(head, N);

        // copia dei livelli dalla lista al vettore
        plvl tmp = nullptr;
        for (int i = 0; i < N; ++i) {
            tmp = elementFromList(head, i + 1);
            l[i].id    = tmp->id;
            l[i].vel   = tmp->vel;
            l[i].bonus = tmp->bonus;
            l[i].time  = tmp->time;
            l[i].next  = tmp->next;
            l[i].prev  = tmp->prev;
        }

        // inizializza current con il primo livello
        current = l[0];
        level_start_time = getCurrentTime();
    }

    // Distruttore per liberare la memoria della lista
    ~Livelli() {
        while (head) {
            plvl tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Verifica se il tempo del livello corrente è scaduto
    bool isCurrentLevelTimeUp() {
        return isTimeExpired(level_start_time, current.time);
    }

    // Ottiene il tempo rimanente del livello corrente in secondi
    int getRemainingTime() {
        return getRemainingSeconds(level_start_time, current.time);
    }

    // Ottiene la velocità del livello corrente (in millisecondi)
    int getCurrentLevelSpeed() {
        const int LEVEL_SPEEDS[] = {3000, 2000, 1500, 1000, 500};
        return LEVEL_SPEEDS[current.id - 1];
    }

    // Ottiene il bonus del livello corrente
    int getCurrentLevelBonus() {
        return current.bonus;
    }

    // Ottiene l'ID del livello corrente
    int getCurrentLevelId() {
        return current.id;
    }

    // Verifica se è l'ultimo livello
    bool isLastLevel() {
        return current.id >= N;
    }

    // Resetta il timer del livello corrente
    void resetLevelTimer() {
        level_start_time = getCurrentTime();
    }

    // stampa tutti i livelli
    void printLevels() {
        for (int j = 0; j < N; j++) {
            cout << "Livello " << l[j].id
                 << ": Velocità = " << l[j].vel
                 << ", Bonus = " << l[j].bonus
                 << ", Tempo = " << l[j].time << " minuti" << endl;
        }
    }

    // stampa il livello corrente
    void printCurrentLevel() {
        cout << "Livello " << current.id
             << ": Velocità = " << current.vel
             << ", Bonus = " << current.bonus
             << ", Tempo = " << current.time << " minuti" << endl;
    }

    // passa al livello successivo
    void nextLevel() {
        for (int j = 0; j < N; j++) {
            if (l[j].id == current.id) {
                int nextIndex = (j + 1) % N;
                current = l[nextIndex];
                resetLevelTimer();
                return;
            }
        }
    }

    // passa al livello precedente
    void prevLevel() {
        for (int j = 0; j < N; j++) {
            if (l[j].id == current.id) {
                int prevIndex = (j - 1 + N) % N;
                current = l[prevIndex];
                resetLevelTimer();
                return;
            }
        }
    }

    // restituisce il livello corrente
    lvl getCurrentLevel() const {
        return current;
    }

    // Ottiene un puntatore al livello corrente
    plvl getCurrentLevelPtr() {
        return elementFromList(head, current.id);
    }
};

#endif // LEVELS_HPP