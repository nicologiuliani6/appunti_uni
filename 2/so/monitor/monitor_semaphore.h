#ifndef MONITOR_SEMAPHORE_H
#define MONITOR_SEMAPHORE_H

#include <pthread.h>

typedef struct {
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t cond; //value > 0
} Semaphore;

void Semaphore_init(Semaphore* S, int initial_value) {
    S->value = initial_value;
    pthread_mutex_init(&S->mutex, NULL);
    pthread_cond_init(&S->cond, NULL);
}

void Semaphore_P(Semaphore* S) {
    pthread_mutex_lock(&S->mutex);

    while (S->value == 0) { //condizione
        pthread_cond_wait(&S->cond, &S->mutex);
    }

    S->value--;
    pthread_mutex_unlock(&S->mutex);
}

void Semaphore_V(Semaphore* S) {
    pthread_mutex_lock(&S->mutex);
    S->value++;
    pthread_cond_signal(&S->cond);  // sveglia un thread in attesa
    pthread_mutex_unlock(&S->mutex);
}

#endif

