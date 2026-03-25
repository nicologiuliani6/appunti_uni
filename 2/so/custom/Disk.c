#include "Disk.h"

void create_HDD(){
    // Alloca la struttura globale HDD
    HDD = malloc(sizeof(HardDisk));
    if (!HDD) {
        perror("malloc HDD failed");
        return;
    }

    // Inizializza user/pass e azzera le app
    strncpy(HDD->user_name, "nico", sizeof(HDD->user_name));
    strncpy(HDD->user_passwd, "1712", sizeof(HDD->user_passwd));
    memset(HDD->applications, 0, sizeof(HDD->applications));
    HDD->n_apps = 0;

    // Aggiunge un'app
    add_app(HDD, "snake", "app/snake_game.so");

    // Salva su disco
    f_write(HDD_PATH, HDD, sizeof(HardDisk), "wb");
    if (!f_open(HDD_PATH, "rb")) {
        fprintf(stderr, "Errore scrittura HDD!\n");
    }
    return;
}
void load_HDD(){
    // Legge HDD dal disco
    FILE* fp = fopen(HDD_PATH, "rb");
    if (!fp) {
        perror("Errore apertura file");
        exit(1);
    }

    if (!HDD) {
        HDD = malloc(sizeof(HardDisk));
        if (!HDD) {
            perror("malloc HDD");
            fclose(fp);
            exit(1);
        }
    }

    // Legge l'intera struct HDD dal file
    size_t read_bytes = fread(HDD, 1, sizeof(HardDisk), fp);
    fclose(fp);

    if (read_bytes != sizeof(HardDisk)) {
        fprintf(stderr, "Attenzione: lettura incompleta (%zu bytes)\n", read_bytes);
        exit(1);
    }
}