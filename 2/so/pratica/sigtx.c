#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pack(const char *buf, int index) {
    int val = 0;
    val |= (unsigned char)buf[(index*4) + 0];
    val |= (unsigned char)buf[(index*4) + 1] <<  8;
    val |= (unsigned char)buf[(index*4) + 2] << 16;
    val |= (unsigned char)buf[(index*4) + 3] << 24;
    return val;
}

int main(int argc, char** argv){
    if (argc != 3){
        printf("sigtx: [PID] [msg]\n");
        return 1;
    }
    int len = strlen(argv[2]);
    int chunks = (len + 3) / 4;

    char buf[chunks*4];
    memset(buf, 0, chunks*4);
    memcpy(buf, argv[2], len);

    union sigval sv;

    // manda prima i chunk (numeri bassi = arrivano dopo)
    for (int i = chunks - 1; i >= 0; i--) {
        sv.sival_int = pack(buf, i);
        sigqueue(atoi(argv[1]), SIGRTMIN + i, sv);
    }

    // manda la lunghezza per ultima (SIGRTMAX = numero più alto = arriva prima)
    sv.sival_int = len;
    sigqueue(atoi(argv[1]), SIGRTMAX, sv);

    return 0;
}