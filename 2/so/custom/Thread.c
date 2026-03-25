#include "Thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

_Atomic(ThreadNode *) thread_queue_head = NULL;
_Atomic(ThreadNode *) thread_queue_tail = NULL;
BinarySemaphore* console_mutex = NULL;
BinarySemaphore* thread_mutex = NULL;
atomic_int thread_count = 0;

// ===================== Creazione ThreadArg =====================
ThreadArg* create_thread_arg(function_type func_type, void **args) {
    //printf("entro create_thread_arg\n");
    ThreadArg *t = malloc(sizeof(ThreadArg));
    if (!t) {
        printf("ERRORE create_thread_arg: IMPOSSIBILE ALLOCARE MEMORIA\n");
        exit(1);
    }
    //printf("PRE FASE BLOCCO CS create_thread_arg\n");
    
    BinarySemaphore_P(thread_mutex);
    //printf("ENTRATO CS create_thread_arg\n");
    t->id = atomic_fetch_add(&thread_count, 1);
    BinarySemaphore_V(thread_mutex);
    //printf("USCITO CS create_thread_arg\n");

    //scriviamo il numero di argomenti della funzione
    t->func_type = func_type;
    switch(func_type){
        case WRITE:
            t->n_args = 2;
            break;
        case FOPEN:
            t->n_args = 2;
            break;
        case FDELETE:
            t->n_args = 1;
            break;
        case FWRITE:
            t->n_args = 4;
            break;
        case INPUT:
            t->n_args = 1;
            break;
        default:
            break;
    }
    //allochiamo memoria per gli elementi!
    t->args = malloc(sizeof(void*) * t->n_args);
    if (!t->args) {
        free(t);
        return NULL;
    }
    //memorizziamo dentro la struttura gli argomenti
       switch(func_type){
        case WRITE:
            t->args[0] = strdup((char*)args[0]); //str
            t->args[1] = ((args[1] == (void*)true) ? (void*)true : (void*)false); //debug
            break;
        case FOPEN:
            t->args[0] = strdup((char*)args[0]); //path
            t->args[1] = strdup((char*)args[1]); //mode
            //printf("%s, %d, %s\n", t->args[0], t->args[1], t->args[2]);
            break;
        case FDELETE:
            t->args[0] = strdup((char*)args[0]); //path
            break;
        case FWRITE:
            t->args[0] = strdup((char*)args[0]); //path
            t->args[1] = (void*)args[1]; //buffer
            t->args[2] = (void*)(uintptr_t)args[2]; //buffer_size
            t->args[3] = strdup((char*)args[3]); //mode
            break;
        case INPUT:
            //niente come parametri in input da funzione, solo args0 conterra l input utente
            break;
        default:
            break;
    }  
    //printf("THREAD ARGS CREATO CON SUCCESSO! (ID=%d)\n", t->id);
    return t;
    
}

// ===================== Libera ThreadArg =====================
void free_thread_arg(ThreadArg *t) {
    if (!t) return;
    switch(t->func_type){
        case WRITE:
            free(t->args[0]);
            #ifdef __linux__
            free(t->args);
            #endif
            break;
        case FOPEN:
            free(t->args[0]); //path
            free(t->args[1]); //mode 
            //free(t->args[2]); //output of the function
            free(t->args);
            #ifdef __linux__
            free(t);
            #endif
            break;
        case FDELETE:
            free(t->args[0]);
            free(t->args);
            free(t);
            break;
        case FWRITE:
            free(t->args[0]); //path
            //free(t->args[1]); //buffer //non cancellare perche il buffer e' da struttura
            free(t->args[3]); //mode
            free(t->args);
            free(t);
            break;
        case INPUT:
            #ifdef __linux__
            free(t->args[0]);
            #endif
            //cancelliamo free(t->args); gia a parte (in generale)
            free(t);
            break;
        default:
            break;
    }
}

// ===================== Rimuove un thread dalla coda =====================
void remove_thread(ThreadNode *node) {
    if (!node) return;

    ThreadNode *prev = NULL;
    ThreadNode *current = atomic_load(&thread_queue_head);

    while (current) {
        if (current == node) {
            ThreadNode *next = current->next;

            if (prev) {
                prev->next = next;
            } else {
                atomic_store(&thread_queue_head, next);
            }

            ThreadNode *tail = atomic_load(&thread_queue_tail);
            if (current == tail) {
                atomic_store(&thread_queue_tail, prev);
            }

            free_thread_arg(current->thread.arg);
            free(current);
            atomic_fetch_sub(&thread_count, 1);

            return;
        }
        prev = current;
        current = current->next;
    }
}

// ===================== Creazione Thread nella coda =====================
void create_thread(void (*func)(void *), ThreadArg *arg) {
    ThreadNode *node = malloc(sizeof(ThreadNode));
    if (!node) return;

    node->thread.func = func;
    node->thread.arg = arg;
    node->thread.status = READY;
    switch (arg->func_type){
        case WRITE:
            node->thread.priority = LOW;
            break;
        case FOPEN:
            node->thread.priority = LOW;
            break;
        case FDELETE:
            node->thread.priority = LOW;
            break;
        case FWRITE:
            node->thread.priority = LOW;
            break;
        case INPUT:
            node->thread.priority = HIGHT;
            break;
        default:
            break;
    }

    node->next = NULL;
    BinarySemaphore_P(thread_mutex);
    ThreadNode *tail = atomic_load(&thread_queue_tail);
    ThreadNode *head = atomic_load(&thread_queue_head);

    if (head == NULL) {
        atomic_store(&thread_queue_head, node);
        atomic_store(&thread_queue_tail, node);
    } else {
        tail->next = node;
        atomic_store(&thread_queue_tail, node);
    }

    atomic_fetch_add(&thread_count, 1);
    
    BinarySemaphore_V(thread_mutex);
    if (node->thread.priority == HIGHT){
        while(node->thread.status != EXITED){
            //do nothing
            continue;
        }
    }    
   //printf("THREAD CREATO CON SUCCESSO! (%d)\n", arg->id);
}

// ===================== Scheduling =====================
void schedule(void) {
    BinarySemaphore_P(thread_mutex);
    //printf("ENTRATO schedule\n");
    // Acquire lock properly
    //printf("ENTRO CS schedule\n");
    
    ThreadNode *head = atomic_load(&thread_queue_head);

    if (head == NULL) {
        BinarySemaphore_V(thread_mutex);
        //printf("ESCO CS schedule (lista vuota)\n");
        return;
    }

    ThreadNode *current = head;
    while (current) {
        if (current->thread.status == READY) {
            
            current->thread.status = RUNNING;
            // Execute thread function while holding the lock
            // (you may want to release lock during execution depending on requirements)
            current->thread.func(current->thread.arg); //eseguiamo direttamente la funzione del thread
            current->thread.status = EXITED;
        }
        current = current->next;
    }  
    BinarySemaphore_V(thread_mutex);
    //printf("ESCO  schedule\n");
}

// ===================== Inizializzazione e distruzione =====================
void thread_library_init(void) {
    atomic_store(&thread_queue_head, NULL);
    atomic_store(&thread_queue_tail, NULL);
    atomic_store(&thread_count, 0);
    console_mutex = BinarySemaphore_create(1);
    thread_mutex = BinarySemaphore_create(1);
}

void thread_library_destroy(void) {
    BinarySemaphore_destroy(console_mutex);
    BinarySemaphore_destroy(thread_mutex);

    ThreadNode *current = atomic_load(&thread_queue_head);
    while (current) {
        ThreadNode *tmp = current;
        current = current->next;
        free_thread_arg(tmp->thread.arg);
        free(tmp);
    }
    atomic_store(&thread_queue_head, NULL);
    atomic_store(&thread_queue_tail, NULL);
    atomic_store(&thread_count, 0);
}
