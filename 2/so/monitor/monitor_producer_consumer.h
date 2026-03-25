#ifndef MONITOR_PRODOCER_CONSUMER_H
#define MONITOR_PRODOCER_CONSUMER_H

#include <pthread.h>
#include "queue.h"

typedef struct {
    pthread_cond_t cond;
} Condition;
void initCondition(Condition *c) {
    pthread_cond_init(&c->cond, NULL);
}

typedef struct {
    Queue* q;              // puntatore alla coda
    int maxsz;
    pthread_mutex_t mutex;  // mutex per la mutua esclusione
    Condition okRead;
    Condition okWrite;
} PCController;
void PCController_init(PCController *PCC, int size) {
    PCC->q = (Queue*)malloc(sizeof(Queue));   // supponendo una funzione che ritorna un Queue*
    Queue_init(PCC->q);
    PCC->maxsz = size;
    pthread_mutex_init(&PCC->mutex, NULL);
    initCondition(&PCC->okRead);
    initCondition(&PCC->okWrite);
}
void PCController_write(PCController *PCC, void* obj) {
    pthread_mutex_lock(&PCC->mutex);

    while (Queue_size(PCC->q) >= PCC->maxsz) { //superato il massimo di elementi, dobbiamo aspettare che qualcosa venga consuamto
        pthread_cond_wait(&PCC->okWrite.cond, &PCC->mutex); //aspetta finche la condizione non si è avverata, lo teniamo dentro il ciclo per non rischiare che esca per sbaglio da bug strani
    }

    Queue_enqueue(PCC->q, obj);
    pthread_cond_signal(&PCC->okRead.cond); //riattiviamo i thread in attesa che aspettavano di leggere

    pthread_mutex_unlock(&PCC->mutex);
}
void* PCController_read(PCController *PCC) {
    pthread_mutex_lock(&PCC->mutex);

    while (Queue_size(PCC->q) == 0) { //se abbiamo almeno un elemento da leggere
        pthread_cond_wait(&PCC->okRead.cond, &PCC->mutex); //lo teniamo dentro il ciclo per non rischiare che esca per sbaglio da bug strani
    }

    void* obj = Queue_dequeue(PCC->q);
    pthread_cond_signal(&PCC->okWrite.cond); //riattiviamo (se presenti) i thread in attesi per il write

    pthread_mutex_unlock(&PCC->mutex);
    return obj;
}

#endif



