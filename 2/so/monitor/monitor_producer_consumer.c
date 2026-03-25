#include "monitor_producer_consumer.h"

// ----- Thread produttore -----
void* producer(void* arg) {
    PCController* pc = (PCController*)arg;
    for (int i = 1; i <= 10; i++) {
        int* val = malloc(sizeof(int));
        *val = i;
        PCController_write(pc, val);
        printf("Produttore ha scritto: %d\n", *val);
        sleep(1);
    }
    return NULL;
}

// ----- Thread consumatore -----
void* consumer(void* arg) {
    PCController* pc = (PCController*)arg;
    for (int i = 1; i <= 10; i++) {
        int* val = (int*)PCController_read(pc);
        printf("Consumatore ha letto: %d\n", *val);
        free(val);
        sleep(2);
    }
    return NULL;
}
int main(){
  PCController pc;
  PCController_init(&pc, 1); // buffer massimo 5

  pthread_t prod, cons;
  pthread_create(&prod, NULL, producer, &pc);
  pthread_create(&cons, NULL, consumer, &pc);

  pthread_join(prod, NULL);
  pthread_join(cons, NULL);
  return 0;
}
