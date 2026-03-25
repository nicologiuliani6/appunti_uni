#include "Semaphore.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

Semaphore *sem;

void* worker(void *arg) {
    long id = (long)arg;
    printf("Thread %ld prova ad entrare\n", id);
    Semaphore_P(sem);
    printf("Thread %ld entra nella sezione critica\n", id);
    //CS
    sleep(1);
    //CS
    printf("Thread %ld esce\n", id);
    Semaphore_V(sem);
    return NULL;
}

int main() {
    sem = Semaphore_create(2); // 2 thread alla volta
    #define L 100
    pthread_t t[L];
    for (long i = 0; i < L; i++)
        pthread_create(&t[i], NULL, worker, (void*)i);
    for (int i = 0; i < L; i++)
        pthread_join(t[i], NULL);
    Semaphore_destroy(sem);
    return 0;
}

