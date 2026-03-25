#include "Semaphore.h"
#include <stdlib.h>
#include <stdio.h>

// Funzioni di supporto per la coda
static void enqueue(Semaphore *s, BinarySemaphore *b) {
    Node *n = malloc(sizeof(Node));
    n->sem = b;
    n->next = NULL;
    if (s->queue_tail)
        s->queue_tail->next = n;
    else
        s->queue_head = n;
    s->queue_tail = n;
}

static BinarySemaphore* dequeue(Semaphore *s) {
    if (s->queue_head == NULL) return NULL;
    Node *n = s->queue_head;
    BinarySemaphore *b = n->sem;
    s->queue_head = n->next;
    if (s->queue_head == NULL)
        s->queue_tail = NULL;
    free(n);
    return b;
}

// Costruttore
Semaphore* Semaphore_create(int v) {
    if (v < 0) {
        fprintf(stderr, "Errore: valore semaforo negativo\n");
        return NULL;
    }

    Semaphore *s = malloc(sizeof(Semaphore));
    if (!s) return NULL;

    s->value = v;
    s->mutex = BinarySemaphore_create(1);
    s->queue_head = s->queue_tail = NULL;

    return s;
}

// Distruttore
void Semaphore_destroy(Semaphore *s) {
    if (!s) return;
    BinarySemaphore_destroy(s->mutex);

    // svuota eventuale coda
    while (s->queue_head) {
        Node *tmp = s->queue_head;
        s->queue_head = tmp->next;
        free(tmp);
    }

    free(s);
}

// Operazione P (wait)
void Semaphore_P(Semaphore *s) {
    BinarySemaphore_P(s->mutex);
    s->value--;

    if (s->value < 0) {
        BinarySemaphore *priv = BinarySemaphore_create(0);
        enqueue(s, priv);
        BinarySemaphore_V(s->mutex);  // lascia entrare altri thread
        BinarySemaphore_P(priv);      // blocca questo thread
        BinarySemaphore_destroy(priv);
    } else {
        BinarySemaphore_V(s->mutex);
    }
}

// Operazione V (signal)
void Semaphore_V(Semaphore *s) {
    BinarySemaphore_P(s->mutex);
    s->value++;

    if (s->value <= 0) {
        BinarySemaphore *priv = dequeue(s);
        if (priv != NULL)
            BinarySemaphore_V(priv);  // risveglia un thread
    }

    BinarySemaphore_V(s->mutex);
}

