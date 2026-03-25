#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
  int n = 5;
  int* pn = &n;
  printf("val=%d \naddr=%p \n", n, &n);
  printf("val p=%d \naddr p=%p \n",*pn, &pn);
  return 0;  
}
