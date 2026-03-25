#include "Syscall.h"
#include <unistd.h>

void thread_write(void *arg) {
    //print(str, debug)
    ThreadArg *t = (ThreadArg*)arg;
    BinarySemaphore_P(console_mutex);
    if ((bool)(intptr_t)t->args[1])
        printf("Thread %d: ", t->id);
    printf("%s", (char*)t->args[0]);
    BinarySemaphore_V(console_mutex);
}

void thread_fopen(void* arg){
    //printf("ENTRATO FOPEN\n");
    ThreadArg *t = (ThreadArg*)arg;
    if (!(char*)t->args[0] || strlen((char*)t->args[0]) == 0) {
        perror("NOME FILE VUOTO");
        exit(1);
    }
    if (!(char*)t->args[1] || strlen((char*)t->args[1]) == 0) {
        perror("MODE FILE VUOTO");
        exit(1);
    }
    //printf("%s, %s\n",(char*)t->args[0], (char*)t->args[1]   );
    FILE *f = fopen(t->args[0], t->args[1]);
    if (!f) {
        //perror("fopen fallita");
        t->args[2] = (void*)false;
        return;
    }
    fclose(f);
    t->args[2] = (void*)true;
}
void thread_fdelete(void* arg){
    //printf("ENTRATO FDELETE\n");
    ThreadArg *t = (ThreadArg*)arg;
    if (!(char*)t->args[0] || strlen((char*)t->args[0]) == 0) {
        perror("NOME FILE VUOTO");
    }
    if (remove((char*)t->args[0]) == 0){
        //printf("\nf_delete: cancellato correttamente file!\n");
    }
    else{
        perror("Errore nell'eliminazione del file");
    }
}
void thread_fwrite(void* arg){
    //f_write('path', 'buffer', buffer_size, 'mode')
    ThreadArg *t = (ThreadArg*)arg;

    // Controllo file e modalità
    if (!(char*)t->args[0] || strlen((char*)t->args[0]) == 0) {
        perror("NOME FILE VUOTO");
        exit(1);
    }
    if (!(char*)t->args[3] || strlen((char*)t->args[3]) == 0) {
        perror("MODE FILE VUOTO");
        exit(1);
    }

    // Apertura file
    FILE *f = fopen((char*)t->args[0], (char*)t->args[3]);
    if (!f) {
        perror("fwrite fallita");
        return;
    }

    // Scrittura
    fwrite(t->args[1], 1, (size_t)(uintptr_t)t->args[2], f);

    fclose(f);

    // Liberazione buffer se allocato dinamicamente
    //free(t->args[1]);  // solo se l'hai allocato tu, cancelliamolo dopo in free(t->args[0]);
    //printf("FWRITE: (%s) scritto correttamente\n", (char*)t->args[0]);

}
void thread_input(void* arg){
    ThreadArg *t = (ThreadArg*)arg;
    size_t size = 16; // dimensione iniziale
    size_t len = 0;
    char *str = malloc(size);
    if (!str) {
        perror("ERRORE: impossibile allocare memoria per la stringa");
        exit(1);
    }
    BinarySemaphore_P(console_mutex);
    int c;
    
    while ((c = getchar()) != '\n' && c != EOF) {
        str[len++] = (char)c;
        if (len >= size - 1) {  // Leave room for null terminator
            size *= 2;
            char *tmp = realloc(str, size);
            if (!tmp) {
                free(str);
                perror("ERRORE: realloc fallita");
                exit(1);
            }
            str = tmp;
        }
    }

    str[len] = '\0'; // termina la stringa dopo che l'utente preme Invio
    t->args[0] = str; // salva la stringa dinamica in args[0]
    BinarySemaphore_V(console_mutex);

}



