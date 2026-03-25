#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <time.h>
#include <stdint.h>

#define L 10000000

typedef enum TURN {
    Q = 0,
    P = 1
} TURN;

_Atomic bool needp = false;
_Atomic bool needq = false;
_Atomic TURN turn = Q;
_Atomic uint64_t cache[L];

void *p(void *arg) {
		needp = true;
		turn = Q;
		while (needq && turn != P)
				usleep(1000);  // piccola pausa per non saturare la CPU
		//cs		
		_Atomic int *ptr = (_Atomic int*)arg;   // ptr punta al contatore condiviso
    int i = *ptr;                           // prendi il valore

    if (i > 1) {
        cache[i] = cache[i-1] + cache[i-2]; // aggiorna cache
    }

    //printf("Q: %d, at step=%llu\n", i, cache[i]);

    atomic_fetch_add(ptr, 1);  // incrementa in modo atomico il contatore
		//cs
		needp = false;
		
    return NULL;
}

void *q(void *arg) {
    needq = true;
    turn = P;
    while (needp && turn != Q)
        usleep(1000);
		 //cs
    _Atomic int *ptr = (_Atomic int*)arg;   // ptr punta al contatore condiviso
    int i = *ptr;                           // prendi il valore

    if (i > 1) {
        atomic_store(&cache[i], cache[i-1] + cache[i-2]); // aggiorna cache
    }

    //printf("Q: %d, at step=%llu\n", i, cache[i]);

    atomic_fetch_add(ptr, 1);  // incrementa in modo atomico il contatore
		//cs
    needq = false;
    return NULL;
}



uint64_t fib(int n){
		if (n == 0) return 1;
		for (int i = 0; i < L; i++) {
				cache[i] = 1;
		}
		pthread_t pp, pq;
		_Atomic int i = 0;
		while(i < n){
			pthread_create(&pp, NULL, p, &i);
			if (n-i > 1) pthread_create(&pq, NULL, q, &i);
			pthread_join(pp, NULL);
			if (n-i > 1) pthread_join(pq, NULL);
		}
		return cache[n-1] + cache[n-2];
}

uint64_t orig_fib(int n) {
    if (n == 0 || n == 1) return 1;

    uint64_t* cache = malloc((n+1) * sizeof(uint64_t));
    cache[0] = 1;
    cache[1] = 1;

    for (int i = 2; i <= n; i++) {
        cache[i] = cache[i-1] + cache[i-2];
    }

    uint64_t result = cache[n];
    free(cache);
    return result;
}


int main(void) {
		printf("FIB (%d) = %llu\n",L , fib(L));
    return 0;
}

