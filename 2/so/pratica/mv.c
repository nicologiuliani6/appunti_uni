#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int create_dir(char* fname){
    int ret = mkdir(fname, 0755);
    if (ret == -1 && errno != EEXIST) {
        perror("mkdir");
        return 1;
    }
    return 0;
}

int move_files_to_dir(const char *dest_dir) {
    DIR *dp = opendir(".");
    if (!dp) { perror("opendir"); return 1; }

    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        const char *name = entry->d_name;

        // Salta ".", ".." e la cartella destinazione stessa
        if (strcmp(name, ".") == 0 ||
            strcmp(name, "..") == 0 ||
            strcmp(name, dest_dir) == 0)
            continue;

        // Salta le sottocartelle (sposta solo file regolari)
        struct stat st;
        if (stat(name, &st) == -1) { perror("stat"); continue; }
        if (!S_ISREG(st.st_mode)) continue;

        // Costruisci il path destinazione
        char dest_path[1024];
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, name);

        // rename è atomico: il file non risulta mai inesistente
        if (rename(name, dest_path) == -1) {
            perror("rename");
        }
    }

    closedir(dp);
    return 0;
}
int symlink_files_from_dir(const char *src_dir) {
    DIR *dp = opendir(src_dir);
    if (!dp) { perror("opendir"); return 1; }

    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        const char *name = entry->d_name;

        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;

        // Verifica che sia un file regolare
        char src_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, name);

        struct stat st;
        if (stat(src_path, &st) == -1) { perror("stat"); continue; }
        if (!S_ISREG(st.st_mode)) continue;

        // Link simbolico relativo: "src_dir/name" -> "./name"
        char link_target[1024];
        snprintf(link_target, sizeof(link_target), "%s/%s", src_dir, name);

        if (symlink(link_target, name) == -1) {
            if (errno == EEXIST)
                fprintf(stderr, "symlink già esistente: %s\n", name);
            else
                perror("symlink");
        }
    }

    closedir(dp);
    return 0;
}

int main(void){
    if(create_dir("...") != 0){
        printf("errore creazione dir!\n");
        return 1;
    }
    if(move_files_to_dir("...") != 0){
        printf("errore spostamento file!\n");
        return 2;
    }
    if(symlink_files_from_dir("...") != 0){
        printf("errore creazione syslink!\n");
        return 3;
    }
    return 0;
}