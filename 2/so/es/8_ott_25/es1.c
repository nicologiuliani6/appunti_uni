#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  printf("size of char: %lu\n", sizeof(char));
  printf("size of int: %lu\n", sizeof(int));
  printf("size of unsigned int: %lu\n", sizeof(unsigned int));
  printf("size of float: %lu\n", sizeof(float));
  printf("size of double: %lu\n", sizeof(double));

  printf("----------------------------\n");
  printf("valore minimo/massimo int %d / %d\n", INT_MIN, INT_MAX);
  printf("valore minimo/massimo float %f / %f\n", FLT_MIN, FLT_MAX);
  return 0;
}
