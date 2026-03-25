#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

// Nodo della coda generica
typedef struct Node {
    void* value;          // valore generico
    struct Node* next;    // puntatore al prossimo nodo
} Node;

// Struttura della coda
typedef struct {
    Node* head;
    Node* tail;
    int size;
} Queue;

// Inizializza la coda
static inline void Queue_init(Queue* q) {
    q->head = q->tail = NULL;
    q->size = 0;
}

// Inserisce in coda (enqueue)
static inline void Queue_enqueue(Queue* q, void* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (!q->tail) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

// Estrae dalla testa (dequeue)
static inline void* Queue_dequeue(Queue* q) {
    if (!q->head) return NULL;

    Node* tmp = q->head;
    void* ret = tmp->value;
    q->head = q->head->next;

    if (!q->head)
        q->tail = NULL;

    free(tmp);
    q->size--;
    return ret;
}

// Controlla se è vuota
static inline bool Queue_empty(const Queue* q) {
    return q->size == 0;
}

#endif // QUEUE_H
