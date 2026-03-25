#include "Application.h"

// definizione globale
HardDisk* HDD = NULL;
AppIndexMap* app_map = NULL;

void* load_file_to_buffer(const char* path, size_t* size_out) {
    FILE* f = fopen(path, "rb");
    if (!f) { perror("Applicazione (.so) non esistente!"); return NULL; }

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    void* buffer = malloc(size);
    if (!buffer) { perror("malloc"); fclose(f); return NULL; }

    fread(buffer, 1, size, f);
    fclose(f);

    if (size_out) *size_out = size;
    return buffer;
}

int run(app *a) {
    int fd = -1;
    char tmpname[128];

#ifdef __linux__
    fd = syscall(SYS_memfd_create, a->app_name, 0);
    if (fd < 0) { perror("memfd_create"); return -1; }
#else
    snprintf(tmpname, sizeof(tmpname), "/tmp/%sXXXXXX", a->app_name);
    fd = mkstemp(tmpname);
    if (fd < 0) { perror("mkstemp"); return -1; }

    // rinomina con .so per dlopen
    char tmpname_so[128];
    snprintf(tmpname_so, sizeof(tmpname_so), "%s.so", tmpname);
    rename(tmpname, tmpname_so);
    strcpy(tmpname, tmpname_so);
#endif

    // scrive il buffer ELF nel file
    if (ftruncate(fd, a->binary_size) < 0) { perror("ftruncate"); goto cleanup; }
    if (write(fd, a->binary_executable, a->binary_size) != (ssize_t)a->binary_size) { perror("write"); goto cleanup; }
#ifdef __linux__
    char path[128];
    snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);
#else
    char *path = tmpname;
#endif

    void *h = dlopen(path, RTLD_NOW | RTLD_LOCAL);
    if (!h) { fprintf(stderr, "dlopen: %s\n", dlerror()); goto cleanup; }

    typedef int (*plugin_main_t)(int, char **);
    plugin_main_t plugin_main = (plugin_main_t)dlsym(h, "plugin_main");
    if (!plugin_main) { fprintf(stderr, "dlsym: %s\n", dlerror()); dlclose(h); goto cleanup; }

    char *argv[] = { a->app_name, NULL };
    int ret = plugin_main(1, argv);

    dlclose(h);

cleanup:
    close(fd);
#ifndef __linux__
    unlink(tmpname);
#endif
    return ret;
}



app* add_app(HardDisk* HDD, char* executable_name, char* executable_path) {
    if (!HDD || !app_map) return NULL;

    if (HDD->n_apps >= MAX_APP) {
        print("Errore: massimo numero di app raggiunto\n");
        return NULL;
    }

    size_t binary_size = 0;
    void* binary_data = load_file_to_buffer(executable_path, &binary_size);
    if (!binary_data) return NULL;

    int index = map_add(app_map, executable_name);

    // Copia direttamente nella struct concreta
    strncpy(HDD->applications[index].app_name, executable_name, sizeof(HDD->applications[index].app_name)-1);
    HDD->applications[index].app_name[sizeof(HDD->applications[index].app_name)-1] = '\0';

    if (binary_size > MAX_BINARY_SIZE) binary_size = MAX_BINARY_SIZE;
    memcpy(HDD->applications[index].binary_executable, binary_data, binary_size);
    HDD->applications[index].binary_size = binary_size;

    free(binary_data);

    HDD->n_apps++;

    print("Applicazione aggiunta: ");
    print(HDD->applications[index].app_name);
    print("\n");

    return &HDD->applications[index];
}


int find_app_index(HardDisk* HDD, const char* app_name) {
    if (!HDD || !app_name) return -1;
    for (int i = 0; i < HDD->n_apps; i++) {
        if (strcmp(HDD->applications[i].app_name, app_name) == 0) {
            return i;
        }
    }
    return -1; // non trovata
}
