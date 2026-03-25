#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <time.h>

typedef enum TURN {
    Q = 0,
    P = 1
} TURN;

_Atomic bool needp = false;
_Atomic bool needq = false;
_Atomic TURN turn = Q;
int x = 0;
#define ITER 1000

void *p(void *arg) {
		for (int i=0; i<ITER; i++){
			needp = true;
			turn = Q;
			while (needq && turn != P)
					usleep(rand() % 1000);  // piccola pausa per non saturare la CPU
			printf("P IN\n");
			x++;                   // simulazione sezione critica
			printf("P OUT\n");
			needp = false;
		}
    return NULL;
}

void *q(void *arg) {
		for (int i=0; i<ITER; i++){
			needq = true;
			turn = P;
			while (needp && turn != Q)
					usleep(rand() % 1000);
			printf("Q IN\n");
			x++;
			printf("Q OUT\n");
			needq = false;
		}
    return NULL;
}

int main(void) {
    srandom(time(NULL));
    pthread_t pp, pq;
    pthread_create(&pp, NULL, p, NULL);
    pthread_create(&pq, NULL, q, NULL);
    pthread_join(pp, NULL);
    pthread_join(pq, NULL);
    printf("X= %d\n",x);
    return 0;
}

