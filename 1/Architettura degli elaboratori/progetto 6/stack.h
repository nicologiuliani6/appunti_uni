#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"
#define MAX_SIZE BUFFER_SIZE  // Dimensione massima per ogni segmento (può essere adattato)

typedef struct {
    int local[MAX_SIZE];      // Stack per variabili locali
    int argument[MAX_SIZE];   // Stack per gli argomenti della funzione
    int this[MAX_SIZE];       // Stack per variabili membro di un oggetto
    int that[MAX_SIZE];       // Stack per altre variabili membro
    int static_var[MAX_SIZE]; // Stack per variabili statiche
    int temp[8];              // Stack per variabili temporanee
    int pointer[2];           // Stack per 'this' e 'that'
    
    int localTop;             // Top del segmento 'local'
    int argumentTop;          // Top del segmento 'argument'
    int thisTop;              // Top del segmento 'this'
    int thatTop;              // Top del segmento 'that'
    int staticTop;            // Top del segmento 'static'
    int tempTop;              // Top del segmento 'temp'
    int pointerTop;           // Top del segmento 'pointer'
} VMStack;

void initialize(VMStack *stack);
void push(VMStack *stack, const char* segment, int value);
int pop(VMStack *stack, const char* segment);
int peek(VMStack *stack, const char* segment);
void printStack(VMStack *stack, const char* segment);


void emulate_STACK(VMStack *stack, const char* command, const char* segment, int index);
char* ASM(char *line, VMStack *stack, char *path_file_input);
#endif