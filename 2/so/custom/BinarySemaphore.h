#ifndef BINARY_SEMAPHORE_H
#define BINARY_SEMAPHORE_H

#include <pthread.h>

typedef struct {
    int value;                  // 0 o 1
    pthread_mutex_t mutex;       // protegge il semaforo
    pthread_cond_t cond;         // per sospendere e risvegliare
} BinarySemaphore;

BinarySemaphore* BinarySemaphore_create(int initialValue);
void BinarySemaphore_destroy(BinarySemaphore* sem);
void BinarySemaphore_P(BinarySemaphore* sem);
void BinarySemaphore_V(BinarySemaphore* sem);

#endif
