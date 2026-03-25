#include "AppIndexMap.h"
#include <stdlib.h>

int map_add(AppIndexMap* map, const char* key) {
    if (!map || !key) return -1;
    // Cerca se la chiave esiste già
    for (int i = 0; i < map->n; i++) {
        if (strcmp(map->keys[i], key) == 0) {
            return map->values[i];
        }
    }

    // Nuova chiave
    if (map->n >= MAX_APP) {
        fprintf(stderr, "Error: map full\n");
        return -1;
    }

    // Alloca copia della stringa
    map->keys[map->n] = strdup(key);
    map->values[map->n] = map->n; // indice corrispondente nell'array di HardDisk
    map->n++;
    return map->values[map->n - 1];
}

int map_get(AppIndexMap* map, const char* key) {
    if (!map || !key) return -1;
    for (int i = 0; i < map->n; i++) {
        if (strcmp(map->keys[i], key) == 0) {
            return map->values[i];
        }
    }
    return -1; // non trovato
}
