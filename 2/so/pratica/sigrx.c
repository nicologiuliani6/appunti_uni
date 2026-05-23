#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* buffer = NULL;
int total_chunks = 0;
int round = 0;

void unpack(int val, char *buf, int index) {
    buf[(index*4) + 0] = (char)( val        & 0xFF);
    buf[(index*4) + 1] = (char)((val >>  8) & 0xFF);
    buf[(index*4) + 2] = (char)((val >> 16) & 0xFF);
    buf[(index*4) + 3] = (char)((val >> 24) & 0xFF);
}

void handler(int sig, siginfo_t *info, void *ctx) {
    if (sig == SIGRTMAX) {
        int len = info->si_value.sival_int;
        total_chunks = (len + 3) / 4;
        buffer = malloc(total_chunks * 4 + 1);
        buffer[total_chunks * 4] = '\0';
        round = 0;
    } else {
        if (buffer == NULL) return;
        int index = sig - SIGRTMIN;  // ← indice dal numero segnale
        unpack(info->si_value.sival_int, buffer, index);
        round++;
        if (round == total_chunks) {
            printf("%s\n", buffer);
            fflush(stdout);
            free(buffer);
            buffer = NULL;
        }
    }
}

int main(){
    __pid_t pid = getpid();
    printf("[sigrx] PID = %d\n", pid);
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMAX, &sa, NULL);
    for (int i = 0; i <= SIGRTMAX - SIGRTMIN; i++)
        sigaction(SIGRTMIN + i, &sa, NULL);
    while(1){
        pause();
    }
    return 0;
}