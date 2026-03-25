#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int* genera_array(int n){
  return calloc(n, sizeof(int)); //n elementi, dimensione di 1 elemento
}

int main(int argc, char** argv){
  uint16_t n;
  if (argc < 2) {
    printf("Errore: inserisci 1 parametro (numero)!\n");
    return -1;
  }
  else n = atoi(argv[1]);
  int* arr = NULL;
  arr = genera_array(n);
  if(!arr) {
    printf("Errore array init!\n");
    return 1;
  }
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
