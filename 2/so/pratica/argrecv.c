#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char** argv){
    char buffer[PATH_MAX] = {0};
    int pos = 0;
    int c;

    // legge byte da stdin fino a EOF
    while ((c = getchar()) != EOF) {
        buffer[pos++] = (char)c;
    }
    buffer[pos] = '\0';

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