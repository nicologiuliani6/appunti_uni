#ifndef IO_H
#define IO_H
#include <stdio.h>
#include "Thread.h"
#include "Runqueue.h"
#include <ctype.h>
#include "AppIndexMap.h"
#include "Application.h"

void* print(void* str); //stampa una stringa

bool* f_open(char* filename, char* mode); //ritorna se un file binario e' presente
void* f_delete(char* filename); //cancella un file
void* f_write(char* filename, void* buffer, int buffer_size, char* mode); //scrivi un file binario uguale al buffer

char* input(); //ritorna la stringa data in input

void run_app(char* filename);

//parsing input command 

#endif