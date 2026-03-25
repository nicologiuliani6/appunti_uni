
#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h> // per intptr_t
#include "queue.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
  int val;
  atomic_bool mutex; //false se non è bloccato da un altro processo
  Queue* q0;
  Queue* q1;
} BinarySemaphore;

void init_BinarySemaphore(BinarySemaphore* BS){
  BS->val = 1;
  atomic_store(&BS->mutex, false);
  // Alloca le code
  BS->q0 = malloc(sizeof(Queue));
  BS->q1 = malloc(sizeof(Queue));
  Queue_init(BS->q0);
  Queue_init(BS->q1);
}
void BinarySemaphore_P(BinarySemaphore* BS, int pid){
    bool expected;
    // wait and enter CS atomico
    do {
        expected = false;
    } while (!atomic_compare_exchange_weak(&BS->mutex, &expected, true));

    // ENTER CS
    if (BS->val == 0){
        Queue_enqueue(BS->q0, (void*)(intptr_t)pid);
        while ((int)(intptr_t)Queue_get_head(BS->q0) != pid)
            continue;
    }
    else if (BS->q1->size > 0){
        pid = (int)(intptr_t)Queue_dequeue(BS->q1);
        while ((int)(intptr_t)Queue_get_head(BS->q1) != pid)
            continue;
    }
    else{
        BS->val--;
    }

    atomic_store(&BS->mutex, false); // exit CS
}


void BinarySemaphore_V(BinarySemaphore* BS, int pid){
    // wait CS usando CAS
    bool expected;
    do {
        expected = false;
    } while (!atomic_compare_exchange_weak(&BS->mutex, &expected, true));

    // sezione critica
    if (BS->val == 1){
        // sospendi pid nella coda q1
        Queue_enqueue(BS->q1, (void*)(intptr_t)pid);
        while ((int)(intptr_t)Queue_get_head(BS->q1) != pid)
            continue;
    }
    else if (BS->q0->size > 0){
        // preleva pid dalla coda q0 per risvegliare
        pid = (int)(intptr_t)Queue_dequeue(BS->q0);
        while ((int)(intptr_t)Queue_get_head(BS->q0) != pid)
            continue;
    }
    else{
        BS->val--;
    }

    // exit CS
    atomic_store(&BS->mutex, false);
}



// ====== funzione eseguita dai thread ======
void* worker(void* arg) {

    int pid = *(int*)arg;
    extern BinarySemaphore sem; // dichiarazione esterna del semaforo
    for (int i = 0; i < 1; i++) {
        BinarySemaphore_P(&sem, pid);
        printf("→ Thread %d entra in CS...\n", pid);
        sleep(1); // simula sezione critica
        printf("→ Thread %d esce in CS...\n", pid);
        BinarySemaphore_V(&sem, pid);
        sleep(1); // simula sezione non critica
    }

    return NULL;
}


BinarySemaphore sem;
int main(){
  pthread_t t1, t2;
  int id1 = 1, id2 = 2;
  init_BinarySemaphore(&sem);
  pthread_create(&t1, NULL, worker, &id1);
  pthread_create(&t2, NULL, worker, &id2);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
