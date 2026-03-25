#define _DEFAULT_SOURCE
#include "Runqueue.h"

Runqueue* Rq = NULL;

void init_Runqueue(){
    Rq = (Runqueue*)malloc(sizeof(Runqueue));
    atomic_store(&Rq->counter, 0);
    Rq->q = (ThreadArg*)malloc(PREDEFINED_START_SIZE * sizeof(ThreadArg));
    //avvio separato del runner dei thread
    pthread_t tid_run;
    pthread_create(&tid_run, NULL, (void* (*)(void*))run_Runqueue, NULL);
}

void* run_Runqueue(void* arg) {
    (void)arg; // Suppress unused parameter warning
    //printf("AVVIO DI TUTTI I THREAD!\n");
    int i = 0;
    while(true){
        i++;
        //printf("Iteration %d\n", i);
        
        // Simply call schedule - it handles its own locking
        schedule();
        
        // Small delay to allow other threads to work
        usleep(1000); // 1ms
    }
    return NULL;
}

void* add_Runqueue(ThreadArg *t) {
    //printf("ENTRATO add_Runqueue %d\n", t->id);
    
    // Add thread to queue
    BinarySemaphore_P(thread_mutex);
    atomic_fetch_add(&Rq->counter, 1);
    BinarySemaphore_V(thread_mutex);

    //printf("ENTRATO CS add_Runqueue\n");
    switch(t->func_type){
        case WRITE:
            create_thread(thread_write, t);
            break;
        case FOPEN:
            create_thread(thread_fopen, t);
            break;
        case FDELETE:
            create_thread(thread_fdelete, t);
            break;
        case FWRITE:
            create_thread(thread_fwrite, t);
            break;
        case INPUT:
            create_thread(thread_input, t);
            break;
        default:
            break;
    }
    //printf("USCITO CS add_Runqueue\n");
    
    //printf("AVVIO RICERCA ELIMINAZIONE THREAD ARGS\n");
    // Wait for thread to complete and remove it
    while (true) {
        BinarySemaphore_P(thread_mutex);
        //printf("ENTRO CS ELIMINAZIONE add_Runqueue\n");
        
        ThreadNode *current = atomic_load(&thread_queue_head);
        
        if (!current) {
            printf("ERRORE Runqueue: LISTA THREAD NULL!\n");
            BinarySemaphore_V(thread_mutex);
            break;
        }
        
        // Search for our thread
        bool found = false;
        while (current) {
            if (current->thread.arg == t) {
                //TODO CANCELLARE ANCHE GLI HIGHT
                if (current->thread.status == EXITED) {
                    if (current->thread.priority == LOW) //non cancellare se HIGHT //TODO SISTEMA
                        remove_thread(current);
                    found = true;
                    //printf("THREAD RIMOSSO CON SUCCESSO\n");
                    break;
                }
                // Thread exists but not yet exited
                break;
            }
            current = current->next;
        }
        
        BinarySemaphore_V(thread_mutex);
        //printf("ESCO CS ELIMINAZIONE add_Runqueue\n");
        if (found) {
            break;
        }
        // Thread not yet executed, wait a bit
        usleep(10000);
    }
    
    return NULL;
}

