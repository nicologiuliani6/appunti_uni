#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include "Thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Runqueue.h"
#include <ctype.h>
#include "Io.h"
#include "Application.h"
#include "AppIndexMap.h"
#include "Disk.h"
#include "Function.h"

void user_space() {
    while(true){
        bool login;
        print("User: ");
        if (strcmp(input(), HDD->user_name) == 0){
            login = true;
        }
        print("Password: ");
        if (strcmp(input(), HDD->user_passwd) == 0){
            login &= true;
        }
        else login = false;
        if (login) break;
    }
    // ciclo comandi
    while (true) {
        print("> ");
        char *cmd = input(); // input() deve restituire stringa allocata dinamicamente
        if (!cmd) continue;

        char *trimmed_cmd = trim(cmd); // rimuove spazi iniziali/finali
        if (!trimmed_cmd) {
            free(cmd);
            continue;
        }

        if (strcmp(trimmed_cmd, "exit") == 0) {
            free(cmd);
            break;
        }
        function_tree* F = parse_function(trimmed_cmd);
        if (!F) {
            print("Comando non valido\n");
            free(cmd);
            continue;
        }

        exec_function(F);
        delete_function(F);
        free(cmd);
    }
    print("Exiting...\n");
}

void vkernel() {
    // Inizializza la libreria dei thread e la runqueue
    thread_library_init();
    init_Runqueue();

    // Inizializza la mappa globale delle app
    static AppIndexMap map;
    map_init(&map);
    app_map = &map;

    // Controlla se il disco esiste
    print("Searching HDD...\n");
    bool HDD_founded = f_open(HDD_PATH, "rb");
    print(HDD_founded ? "HDD founded!\n" : "HDD not found.\n");

    if (!HDD_founded) {
        print("Creating system memory...\n");
        create_HDD();   // ora HDD esiste già in memoria
        print("System memory successfully created!\n");
    }

    // Leggi HDD dal disco
    load_HDD();  // sicuro, HDD è già allocato

    print("System memory successfully read!\n");
    printf("Disk size: %.3lf Mbyte\n", sizeof(HardDisk)/1000000.0);

    // Esegue lo user space
    user_space();

    // Pulizia finale
    //print("\nDeleting system memory...\n");
    //f_delete(HDD_PATH);
    // Non serve liberare le singole app, sono struct concrete
    // Basta solo liberare HDD
    free(HDD);
    HDD = NULL;
    //print("System memory successfully deleted!\n");
}


int main() {
    // Avviamo il kernel virtuale
    vkernel();

    // Attende la terminazione di tutti i thread
    bool all_exited;
    do {
        all_exited = true;
        ThreadNode *current = thread_queue_head;
        while (current) {
            if (current->thread.status != EXITED) {
                all_exited = false;
                break;  // almeno un thread non è ancora uscito
            }
            current = current->next;
        }
        usleep(1000); // piccola pausa per non fare busy-wait pesante
    } while (!all_exited);

    // Terminazione controllata da utente
    print("\nPremi 'q' per terminare e liberare i thread...\n");
    int c;
    do {
        c = getchar();
        if (c == EOF) continue; // salta eventuali EOF
    } while (tolower(c) != 'q');

    // Pulizia della libreria thread
    thread_library_destroy();

    print("Programma terminato correttamente.\n");
    return 0;
}
