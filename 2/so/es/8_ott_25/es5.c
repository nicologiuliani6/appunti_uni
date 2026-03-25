#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {
    READ = 1 << 0, //0001
    WRITE = 1 << 1, //0010
    EXEC = 1 << 2 //0100 
  } Permission;

void print_bit(const int number){
  for(int i=7; i > -1; i--){
    printf("%d", (number >> i) & 1); //stampiamo bit meno significativo
  }
  printf("\n");
}

int main(){
  Permission p = READ | WRITE; // 0001 or 0010 = 0011
  print_bit(p);
  p = p & ~(READ | WRITE);
  print_bit(p);
  p = p | EXEC;
  print_bit(p);
  return 0;
}
