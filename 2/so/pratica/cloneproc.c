#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

/*
Scrivi un programma C cloneproc che dato il PID di un processo come unico parametro, lo clona — cioè riesegue lo stesso programma con gli stessi argomenti.
*/

int main(int argc, char ** argv){
    if (argc < 2){
        printf("Uso: cloneproc [PID]\n");
        return 1;
    }
    char path[256];
    char buf[1024];

    snprintf(path, sizeof(path), "/proc/%s/exe", argv[1]);

    ssize_t len = readlink(path, buf, sizeof(buf) - 1);

    if (len == -1) {
        perror("readlink");
        return 1;
    }

    buf[len] = '\0';  // IMPORTANTISSIMO

    printf("Path: %s\n", buf);
    char cmdline[4096];
    char cmdpath[256];
    snprintf(cmdpath, sizeof(cmdpath), "/proc/%s/cmdline", argv[1]);
    int fd = open(cmdpath, O_RDONLY);
    if (fd < 0) {
        perror("open cmdline");
        return 1;
    }
    int n = read(fd, cmdline, sizeof(cmdline) - 1);
    close(fd);
    cmdline[n] = '\0';

    int count = 0;
    // supponiamo massimo n argomenti
    char **param = malloc(sizeof(char*) * 100);
    int out = 0;
    int i = 0;
    while (i < n) {
        char *arg = cmdline + i;
        param[out] = arg;
        out++;
        i += strlen(arg) + 1;
    }
    param[out] = NULL;  // ← FONDAMENTALE: execv vuole NULL alla fine

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // sono il figlio — eseguo il clone
        execv(buf, param);
        perror("execv");  // se arriviamo qui, execv ha fallito
        exit(1);
    } else {
        // sono il padre — aspetto che il figlio finisca
        int status;
        waitpid(pid, &status, 0);
        printf("Clone terminato con codice %d\n", WEXITSTATUS(status));
    }
}