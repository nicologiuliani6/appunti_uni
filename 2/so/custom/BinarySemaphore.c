#include "BinarySemaphore.h"
#include <stdlib.h>
#include <stdio.h> //printf errore

BinarySemaphore* BinarySemaphore_create(int initialValue) {
    BinarySemaphore* sem = malloc(sizeof(BinarySemaphore));
    if (!sem) return NULL;
    if (initialValue != 0 && initialValue != 1){
        printf("ERRORE: valore di inizializzazione del semaforo binario\n");
        exit(1);
    }
    sem->value = initialValue;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);

    return sem;
}

void BinarySemaphore_destroy(BinarySemaphore* sem) {
    pthread_mutex_destroy(&sem->mutex);
    pthread_cond_destroy(&sem->cond);
    #ifdef __linux__
    free(sem);
    #else 
    //free(sem)
    #endif
}

void BinarySemaphore_P(BinarySemaphore* sem) {
    pthread_mutex_lock(&sem->mutex);
    while (sem->value == 0) {
        pthread_cond_wait(&sem->cond, &sem->mutex); // sospende qui
    }
    sem->value = 0; // prende il semaforo
    pthread_mutex_unlock(&sem->mutex);
}

void BinarySemaphore_V(BinarySemaphore* sem) {
    pthread_mutex_lock(&sem->mutex);
    sem->value = 1; // rilascia il semaforo
    pthread_cond_signal(&sem->cond); // risveglia 1 thread sospeso
    pthread_mutex_unlock(&sem->mutex);
}
