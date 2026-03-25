#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "BinarySemaphore.h"

// Nodo della coda di semafori privati
typedef struct Node {
    BinarySemaphore *sem;
    struct Node *next;
} Node;

// Semaforo generale costruito con semafori binari
typedef struct {
    int value;
    BinarySemaphore *mutex;  // protezione mutua esclusione
    Node *queue_head;
    Node *queue_tail;
} Semaphore;

Semaphore* Semaphore_create(int v);
void Semaphore_destroy(Semaphore *s);
void Semaphore_P(Semaphore *s);
void Semaphore_V(Semaphore *s);

#endif

