#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(){
  int x = 6;
  int y = 7;
  swap(&x, &y);
  printf("x= %d, y=%d\n", x, y);
  return 0;
}
