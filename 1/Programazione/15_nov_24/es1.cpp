#include <iostream>
using namespace std;
const int MAX= 1024;
struct stack {
  int data[MAX];
  int size; // numero di elementi nella pila
};

void init(stack A){
  A.size=0;
  for(int i=0; i<MAX; i++){
    A.data[i]=0;
  }
}
int push(stack& A, int elem){
  //ERROR: if arr size is MAX size
  if (A.size==MAX){
    printf("ERRORE: impossibile eseguire il push perchè pila già piena");
    return -1;
  }
  else{
    //put elem in A[size-1 +1]
    A.data[A.size]=elem;
    //modifica per riferimento size
    A.size++;
    //ritorna il nuovo numero di elementi
    return A.size;
  }
}
int pop(stack& A){
  //La funzione emette un messaggio di errore e restituisce -1 se la pila è vuota
  if(A.size==0){
    return -1;
  }
  else{
    //rimozione ultimo elemento
    A.size--;
    A.data[A.size]=0;
    return A.size;
  }
}
int top(stack A){
  if(A.size==0){
    //La funzione emette un messaggio di errore e restituisce -1 se la pila è vuota
    return -1;
  }
  else{
    return A.data[A.size-1];
  }
}
void print_stack(stack A){
  for(int i=0; i<A.size; i++){
    printf("%d ",A.data[i]);
  }
  printf("\n");
}


int main(){
  //inizializza
  stack A;
  init(A);
  //put data into stack
  A.data[0]=2;
  A.data[1]=5;
  A.data[2]=3;
  A.data[3]=10;
  A.data[4]=7;
  A.size=5;
  
  //funct
  push(A, 8);
  pop(A);
  print_stack(A);
  return 0;
}
