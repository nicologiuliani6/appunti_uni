#ifndef SYSCALL_H
#define SYSCALL_H
#include <stdio.h>
#include <string.h>
#include "Thread.h"
//importo per per avvio da memoria delle app


void thread_write(void *arg);

void thread_fopen(void* arg);
void thread_fdelete(void* arg);
void thread_fwrite(void* arg);

void thread_input(void* arg);


#endif