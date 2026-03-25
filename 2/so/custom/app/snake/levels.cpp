#include "levels.hpp"

// Crea un nuovo nodo livello
plvl createNode(int i, int v, int b, int t) {
    plvl newNode = new lvl;
    newNode->id = i;
    newNode->vel = v;
    newNode->bonus = b;
    newNode->time = t;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Aggiunge un nodo in coda alla lista
plvl enqueue(plvl head, const int i, const int v, const int b, const int t) {
    plvl newNode = createNode(i, v, b, t);

    if (head == nullptr) {
        return newNode;
    }

    plvl p = head;
    while (p->next != nullptr) {
        p = p->next;
    }

    p->next = newNode;
    newNode->prev = p;

    return head;
}

// Crea la lista dei livelli con durata variabile
plvl createList(plvl head, const int n) {
    for (int j = 1; j <= n; j++) {
        int t;
        if(j == 1 || j== 2) t = 1;
        else if (j == 3 || j == 4) t = 2;
        else t = 3;
        head = enqueue(head, j, j, j * 50, t);
    }
    return head;
}

// Restituisce il nodo di livello con ID specificato
plvl elementFromList(plvl head, int id) {
    plvl current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // non trovato
}

// Funzioni temporali pure (senza stato)
time_t getCurrentTime() {
    return time(nullptr);
}

time_t getEndTime(int minutes) {
    return getCurrentTime() + minutes * 60;
}

bool isTimeExpired(time_t start_time, int duration_minutes) {
    return getCurrentTime() >= (start_time + duration_minutes * 60);
}

int getRemainingSeconds(time_t start_time, int duration_minutes) {
    time_t end_time = start_time + duration_minutes * 60;
    time_t current_time = getCurrentTime();
    return (current_time >= end_time) ? 0 : static_cast<int>(end_time - current_time);
}