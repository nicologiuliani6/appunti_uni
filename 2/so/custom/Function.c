#include "Function.h"

// funzione di utilità per rimuovere spazi iniziali/finali
char* trim(char* str) {
    while (isspace(*str)) str++;
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) *end-- = '\0';
    return str;
}

// --- split args considerando parentesi annidate ---
char** split_args(const char* args_str, int* out_count) {
    int len = strlen(args_str);
    char** args = NULL;
    int count = 0;
    int start = 0;
    int level = 0;

    for (int i = 0; i <= len; i++) {
        char c = args_str[i];
        if (c == '(') level++;
        else if (c == ')') level--;
        else if ((c == ',' && level == 0) || c == '\0') {
            int arg_len = i - start;
            char* arg = malloc(arg_len + 1);
            strncpy(arg, args_str + start, arg_len);
            arg[arg_len] = '\0';
            arg = trim(arg);

            args = realloc(args, sizeof(void*) * (count + 1));
            args[count++] = arg;

            start = i + 1;
        }
    }

    *out_count = count;
    return args;
}

// --- parsing della funzione ---
function_tree* parse_function(char* cmd) {
    function_tree* F = malloc(sizeof(*F));
    if (!F) return NULL;

    F->func_type = UNKNOWN;
    F->n_args = 0;
    F->args = NULL;

    // trova parentesi
    char *open = strchr(cmd, '(');
    char *close = strrchr(cmd, ')'); // usa strrchr per la parentesi finale
    if (!open || !close || close < open) {
        free(F);
        return NULL;
    }

    // nome del comando
    *open = '\0';
    char* command_name = trim(cmd);

    if (strcmp(command_name, "print") == 0) F->func_type = WRITE;
    else if (strcmp(command_name, "f_open") == 0) F->func_type = FOPEN;
    else if (strcmp(command_name, "f_delete") == 0) F->func_type = FDELETE;
    else if (strcmp(command_name, "f_write") == 0) F->func_type = FWRITE;
    else if (strcmp(command_name, "input") == 0) F->func_type = INPUT;
    else if (strcmp(command_name, "run") == 0) F->func_type = RUN;
    else {
        free(F);
        return NULL;
    }

    // estrai contenuto tra parentesi
    *close = '\0';
    char* args_str = open + 1;

    if (args_str[0] == '\0') {
        F->n_args = 0;
        F->args = NULL;
        return F;
    }

    int n_args = 0;
    char** args = split_args(args_str, &n_args);
    F->args = (void**)args;
    F->n_args = n_args;

    return F;
}

// --- esecuzione funzione (ricorsiva) ---
void* exec_function(function_tree* F) {
    if (!F) {
        fprintf(stderr, "ALBERO FUNZIONE NULLO\n");
        exit(1);
    }

    // esegui eventuali sottofunzioni negli argomenti
    for (int i = 0; i < F->n_args; i++) {
        char* arg_str = (char*)F->args[i];
        function_tree* subfunc = parse_function(arg_str);
        if (subfunc) {
            void* result = exec_function(subfunc);
            // pulizia struttura sottofunzione
            for (int j = 0; j < subfunc->n_args; j++) free(subfunc->args[j]);
            free(subfunc->args);
            free(subfunc);
            F->args[i] = result; // sostituisci con il risultato
        }
    }
    switch (F->func_type) {
        case WRITE:
            if (F->n_args >= 1){
                print((char*)F->args[0] );
                print("\n");
            } //todo sistema
            else print("Syntax error: print([text])\n");
            break;

        case FOPEN:
            if (F->n_args >= 1) {
                // arg0 = filename, arg1 = size, arg2 = mode
                char* filename = (char*)F->args[0];
                char* mode = "rb";
                if (F->n_args == 2) {
                    mode = (char*)F->args[1];
                    if (strcmp(mode, "rb") != 0){
                        print("Syntax error: thread_fopen([path], rb)\n");
                    }
                }
                f_open(filename, mode);
            }
            else print("Syntax error: f_open([path], [mode])\n");
            break;

        case FDELETE:
            if (F->n_args >= 1) {
                char* filename = (char*)F->args[0];
                return f_delete(filename);
            } 
            else print("Syntax error: f_delete([path])\n");
            break;

        case FWRITE:
            print("f_write() non disponibile in modalita' console!\n");
            /*
            if (F->n_args >= 4) {
                char* filename = (char*)F->args[0];
                void* buffer = F->args[1];
                int buffer_size = atoi((char*)F->args[2]);
                char* mode = (char*)F->args[3];
                return f_write(filename, buffer, buffer_size, mode);
            }
            else print("Syntax error: f_write([path], [buffer_file], [buffer_size_byte], [mode])\n"); */
            break;

        case INPUT: 
            return input();
            break;
        case RUN: 
              if (F->n_args >= 1){
                run_app((char*)F->args[0]);
            } //todo sistema
            else print("Syntax error: run([application_name])\n");
            break;
        
        default:
            break;
    }
    return NULL;
}

void* delete_function(function_tree* F){
        // libera memoria della funzione
        switch(F->func_type){
            case WRITE:
                if (F->n_args >= 1) free(F->args[0]);
                break;
            case FOPEN:
                free(F->args[0]);
                //free(F->args[2]);
                break;
            case FDELETE:
                free(F->args[0]);
                break;
            case FWRITE:
                //free(F->args[0]);
                //free(F->args[1]);
                //free(F->args[3]);
                break;
            case INPUT:
                //free(F->args[0]);
                break;
            default:
                break;
        }
        free(F->args);
        free(F);
        return NULL;
}