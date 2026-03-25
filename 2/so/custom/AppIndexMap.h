#ifndef APPINDEXMAP_H
#define APPINDEXMAP_H

#include <string.h>
#include <stdio.h>

#ifndef MAX_APP
#define MAX_APP 20
#endif

typedef struct {
    char* keys[MAX_APP];   // nomi delle app
    int values[MAX_APP];   // indice nell'array di HardDisk
    int n;                 // numero di app presenti
} AppIndexMap;

// Inizializza la mappa
static inline void map_init(AppIndexMap* map) {
    for (int i = 0; i < MAX_APP; i++) {
        map->keys[i] = NULL;
        map->values[i] = -1;
    }
    map->n = 0;
}

// Aggiunge una chiave e ritorna l'indice assegnato
int map_add(AppIndexMap* map, const char* key);

// Ritorna l'indice di una chiave, -1 se non esiste
int map_get(AppIndexMap* map, const char* key);

#endif
