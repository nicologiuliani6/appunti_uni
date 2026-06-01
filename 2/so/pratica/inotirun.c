#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> //DIR*
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/inotify.h>
#include <sys/wait.h>

int exec_prog(char* fpath){
    FILE *f = fopen(fpath, "r");
    if (!f) { perror("fopen"); return EXIT_FAILURE; }

    char **argv = NULL;
    int argc = 0;
    char line[256];

    while (fgets(line, sizeof(line), f)) {
        // Rimuovi il newline
        line[strcspn(line, "\n")] = '\0';
        
        argv = realloc(argv, (argc + 1) * sizeof(char *));
        argv[argc++] = strdup(line);
    }
    fclose(f);

    // execv vuole NULL come ultimo elemento
    argv = realloc(argv, (argc + 1) * sizeof(char *));
    argv[argc] = NULL;

    printf("Eseguo: %s ", argv[0]);

    for(int i=1; i<argc; i++) printf("%s ", argv[i]);
    printf("\n");

    pid_t pid = fork();
    if (pid == 0) {
        // figlio: esegue il programma
        execv(argv[0], argv+1);
        perror("execv");
        exit(EXIT_FAILURE);
    } else {
        // padre: aspetta che il figlio finisca
        wait(NULL);
    }
    
    // Cleanup (solo se execv fallisce, altrimenti non torna mai)
    for (int i = 0; i < argc; i++) free(argv[i]);
    free(argv);
    return EXIT_SUCCESS;
}

int delate_prog(char* fpath){
    return unlink(fpath);
}

int scan_dir(char* dpath){
    DIR *dir = opendir(dpath);
    if (!dir) return EXIT_FAILURE;

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dpath, entry->d_name);

        struct stat st;
        lstat(fullpath, &st);


        if (S_ISDIR(st.st_mode)) {
            //ricorsione
            scan_dir(fullpath);
        }
        else {
            if (exec_prog(fullpath) != EXIT_SUCCESS){
                printf("Errore esecuzione processo dal file %s\n", fullpath);
            }
            if(delate_prog(fullpath) != EXIT_SUCCESS){
                printf("Errore nella cancellazione del file %s", fullpath);
            }
        }
    }
    return EXIT_SUCCESS;
}
#define MASK (IN_CLOSE_WRITE | IN_MOVED_TO)
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s [dir]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = inotify_init();
    if (fd == -1) {
        perror("inotify_init");
        return EXIT_FAILURE;
    }

    if (inotify_add_watch(fd, argv[1], MASK) == -1) {
        perror("inotify_add_watch");
        return EXIT_FAILURE;
    }



    char buf[4096];
    while (1) {
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n == -1) {
            perror("read");
            return EXIT_FAILURE;
        }

        struct inotify_event *ev = (struct inotify_event *) buf;
        while ((char*)ev < buf + n) {
            if (ev->mask & (MASK)) {
                char path[4096];
                snprintf(path, sizeof(path), "%s/%s", argv[1], ev->name);
                if (scan_dir(argv[1]) != EXIT_SUCCESS) {
                    printf("Errore scansione directory\n");
                }
            }
            ev = (struct inotify_event *)((char*)ev + sizeof(struct inotify_event) + ev->len);
        }
    }

    return EXIT_SUCCESS;
}