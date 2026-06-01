#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc < 2){
        printf("usage %s [command] [arg]\n", argv[0]);
        return EXIT_FAILURE;
    }
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        putchar('\0');
    }
    return EXIT_SUCCESS;
}