#ifndef APPLICATION_H
#define APPLICATION_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#ifdef __linux__
    // Su Linux memfd_create è disponibile tramite syscall
    #include <sys/syscall.h>
    #include <linux/memfd.h>
#else
    // Su BSD non c'è memfd.h, ma servono questi per shm_open o mkstemp
    #include <sys/mman.h>
    #include <sys/stat.h>

    // --- workaround per conflitto FREAD/FWRITE ---
    #define FREAD   __SYS_FREAD
    #define FWRITE  __SYS_FWRITE
    #include <fcntl.h>
    #undef FREAD
    #undef FWRITE
    // ---------------------------------------------
#endif


#include "AppIndexMap.h"
#include "Io.h" // se usi print()

#define MAX_BINARY_SIZE 65536   // dimensione massima per il binario di un'app
#define HDD_PATH "os/system_memory"

// struttura dell'app
typedef struct {
    char app_name[32];
    unsigned char binary_executable[MAX_BINARY_SIZE];
    size_t binary_size;
} app;

// struttura HardDisk
typedef struct {
    char user_name[32];
    char user_passwd[32];
    app applications[MAX_APP];  // array concreto di app
    int n_apps;
} HardDisk;

// puntatore globale alla memoria e alla mappa
extern HardDisk* HDD;
extern AppIndexMap* app_map;

// funzioni
void* load_file_to_buffer(const char* path, size_t* size_out);
int run(app* a);
app* add_app(HardDisk* HDD, char* executable_name, char* executable_path);

// funzione per trovare l'indice di un'app
int find_app_index(HardDisk* HDD, const char* app_name);

#endif
