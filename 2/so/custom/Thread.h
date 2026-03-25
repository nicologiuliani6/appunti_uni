#ifndef THREAD_H
#define THREAD_H

#include "BinarySemaphore.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>   // per bool, true, false
#include <stdatomic.h>

// ===================== Tipo funzione del thread =====================
typedef enum {
    WRITE, //print()
    FOPEN, //f_open()
    FDELETE, //f_delete()
    FWRITE, //f_write() --no-console
    INPUT, //input() --only-console
    RUN, //run(app_name)
    UNKNOWN
} function_type;

// ===================== Argomenti di un thread =====================
typedef struct {
    function_type func_type; // tipo di funzione (WRITE/READ)
    atomic_int id;                  // id del thread
    int n_args;              // numero di argomenti
    void **args;             // array di puntatori ai parametri
} ThreadArg;

// ===================== Stato di un thread =====================
typedef enum {
    WAIT,
    READY,
    RUNNING,
    EXITED
} thread_status;
// ===================== Priorita di un thread =====================
typedef enum{
    HIGHT = 0,
    LOW = 1
} thread_priority;
// ===================== Struttura di un thread =====================
typedef struct {
    void (*func)(void*); // funzione da eseguire
    void *arg;           // puntatore agli argomenti
    thread_status status;
    thread_priority priority;
} Thread;

// ===================== Nodo della coda dei thread =====================
typedef struct ThreadNode {
    Thread thread;
    struct ThreadNode* next;
} ThreadNode;

// ===================== Variabili globali della libreria =====================
// Variabili globali atomiche
extern _Atomic(ThreadNode *) thread_queue_head;
extern _Atomic(ThreadNode *) thread_queue_tail;
extern BinarySemaphore *console_mutex;
extern BinarySemaphore* thread_mutex;
extern _Atomic bool thread_lock;
extern atomic_int thread_count;

// ===================== Funzioni principali della libreria =====================
void thread_library_init(void);                              // inizializza la libreria
void thread_library_destroy(void);                           // libera tutta la memoria
ThreadArg* create_thread_arg(function_type type, void **args); // crea ThreadArg dinamico
void free_thread_arg(ThreadArg *t);                          // libera un ThreadArg
void remove_thread(ThreadNode *node);
void create_thread(void (*func)(void*), ThreadArg *arg);    // aggiunge un thread alla coda
void schedule(void);                                        // esegue tutti i thread READY

#endif // THREAD_H

