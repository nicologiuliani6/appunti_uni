#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdint.h>

#define L 10000000
#define THREADS 10

uint64_t cache[L];
_Atomic int counter = 2; // i primi due valori sono già calcolati

void* worker(void* arg) {
    int n = *(int*)arg;
    while (1) {
        int i = atomic_fetch_add(&counter, 1);
        if (i >= n) break;

        // calcolo Fibonacci sicuro: leggiamo cache[i-1] e cache[i-2]
        cache[i] = cache[i-1] + cache[i-2];
    }
    return NULL;
}

uint64_t fib(int n) {
    if (n == 0 || n == 1) return 1;

    cache[0] = 1;
    cache[1] = 1;

    pthread_t threads[THREADS];
    for (int t = 0; t < THREADS; t++) {
        pthread_create(&threads[t], NULL, worker, &n);
    }

    for (int t = 0; t < THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return cache[n-1] + cache[n-2];
}

int main() {
    printf("fib(%d) = %llu\n", L, fib(L));
    return 0;
}

