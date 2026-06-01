#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char** argv){
    if(argc != 2){
        printf("usage: %s [path/to/pipe]\n", argv[0]);
        return EXIT_FAILURE;
    }
    mkfifo(argv[1], 0666);
    int fd = open(argv[1], O_RDONLY); // si blocca qui finché argsend scrive

    char buffer[PATH_MAX] = {0};
    int pos = 0;
    int n;
    while ((n = read(fd, buffer + pos, sizeof(buffer) - pos)) > 0) {
        pos += n;
    }
    
    char *args[128];
    int argc2 = 0;
    int i = 0;

    while (i < pos) {
        args[argc2++] = buffer + i;
        i += strlen(buffer + i) + 1;
    }
    args[argc2] = NULL;

    execvp(args[0], args);
    perror("execvp");
    return EXIT_SUCCESS;
}