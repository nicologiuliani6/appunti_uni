#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct list {
    char *name;
    struct list *next;
} list;

list *return_files(char *cwd) {
    list *head = NULL;
    list **L = &head;

    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        struct stat st;
        if (stat(entry->d_name, &st) == -1)
            continue;
        if (!S_ISREG(st.st_mode))
            continue;

        // Path assoluto: cwd + "/" + nome
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", cwd, entry->d_name);

        *L = malloc(sizeof(list));
        if (*L == NULL) { perror("malloc"); exit(1); }

        (*L)->name = malloc(strlen(fullpath) + 1);
        if ((*L)->name == NULL) { perror("malloc"); exit(1); }

        strcpy((*L)->name, fullpath);
        (*L)->next = NULL;
        L = &((*L)->next);
    }

    closedir(dir);
    return head;
}

int main(void) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }

    // Costruisce la lista di tutti i path assoluti dei file
    list *paths = return_files(cwd);

    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        struct stat st;
        if (stat(entry->d_name, &st) == -1)
            continue;
        if (!S_ISREG(st.st_mode))
            continue;

        // Apre e legge il file corrente
        FILE *f = fopen(entry->d_name, "rb");
        if (!f) { perror("fopen"); continue; }

        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        rewind(f);

        if (fsize <= 0) { fclose(f); continue; }

        char *buf = malloc(fsize);
        if (!buf) { perror("malloc"); fclose(f); continue; }

        fread(buf, 1, fsize, f);
        fclose(f);

        // Cerca tutti i path assoluti dentro il buffer
        list *p = paths;
        while (p != NULL) {
            if (memmem(buf, fsize, p->name, strlen(p->name)) != NULL) {
                printf("%s\n", entry->d_name);
                break;  // basta trovarne uno, è già dir-ricorsivo
            }
            p = p->next;
        }

        free(buf);
    }

    closedir(dir);
    return 0;
}