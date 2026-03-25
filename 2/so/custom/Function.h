#ifndef FUNCITON_H
#define FUNCITON_H
#include "Io.h"

typedef struct {
    function_type func_type;
    int n_args;
    void **args; 
} function_tree;
char* trim(char* str);
function_tree* parse_function(char* cmd);
void* exec_function(function_tree* F);
void* delete_function(function_tree* F);

#endif 