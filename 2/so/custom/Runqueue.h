#ifndef RUNQUEUE_H
#define RUNQUEUE_H

#define _POSIX_C_SOURCE 200809L

#include "Thread.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "Syscall.h"

#define PREDEFINED_START_SIZE 1000
typedef struct { 
    atomic_int counter;
    ThreadArg* q;
} Runqueue;

void init_Runqueue();
void* run_Runqueue(void* arg);
void* add_Runqueue(ThreadArg *t);

void thread_write(void *arg);
void* print(void* str);

#endif