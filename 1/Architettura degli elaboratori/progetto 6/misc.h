#ifndef MISC_H
#define MISC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 102400
#define MAX_LINES 100
#define MAX_LENGTH 256
char **create_char(FILE *file, int *lineCount); 
void print_char(char **file, int lineCount);
void free_char_array(char **file, int lineCount);

char **cleanFile(char **file, int *lineCount);

void removeSubstring(char *str, const char *substr);
#endif