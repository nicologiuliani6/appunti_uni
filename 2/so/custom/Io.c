#include "Io.h"

void* print(void* str){
    while (!str || ((char*)str)[0] == '\0') {
        // sleep breve per evitare di saturare la CPU
        usleep(1000); // 1 ms
    }
    ThreadArg *t = create_thread_arg(WRITE, (void*[]){ str, (void*)(intptr_t)false});
    if (t == NULL){
        printf("ERRORE: impossibile creare thread!\n");
        exit(1);
    }
    add_Runqueue(t);
    return NULL;
}

bool* f_open(char* filename, char* mode){
    ThreadArg *t = create_thread_arg(FOPEN, (void*[]){ filename, mode});
    if (t == NULL){
        printf("ERRORE: impossibile creare thread!\n");
        exit(1);
    }
    add_Runqueue(t);
    return (bool*)t->args[2]; //output della funzione
}
void* f_delete(char* filename){
    ThreadArg *t = create_thread_arg(FDELETE, (void*[]){ filename });
    if (t == NULL){
        printf("ERRORE: impossibile creare thread!\n");
        exit(1);
    }
    pthread_t tid_fdelete;
    pthread_create(&tid_fdelete, NULL, (void* (*)(void*))add_Runqueue, t);
    return NULL;
}
void* f_write(char* filename, void* buffer, int buffer_size, char* mode){
    ThreadArg *t = create_thread_arg(FWRITE, (void*[]){ filename, buffer, (void*)(uintptr_t)(buffer_size), mode });
    if (t == NULL){
        printf("ERRORE: impossibile creare thread!\n");
        exit(1);
    }
    add_Runqueue(t);
    return NULL;
}

char* input(){
    ThreadArg *t = create_thread_arg(INPUT, NULL);
    if (t == NULL){
        printf("ERRORE: impossibile creare thread!\n");
        exit(1);
    }
    add_Runqueue(t);
    return (char*)t->args[0]; //dentro args0 troviamo l input utente
}

void run_app(char* filename){
    int idx = find_app_index(HDD, filename);
    if (idx >= 0)
        run(&HDD->applications[idx]); // applications[idx] è app*
    else print("App not installed!\n");
    return;
}
