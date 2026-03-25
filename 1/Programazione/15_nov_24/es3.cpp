#include <iostream>
using namespace std;
const int MAX= 1024;
struct stack {
  int data[MAX];
  int size; // numero di elementi nella pila
};

void init(stack& A){
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

void sum(stack& A){
    //somma penultimo e ultimo
    A.data[A.size-2]+=A.data[A.size-1];
    //cancellazione ultimo
    pop(A);
}
void sub(stack& A){
    //sottrazione penultimo e ultimo
    A.data[A.size-2]=A.data[A.size-2]-A.data[A.size-1];
    //cancellazione ultimo
    pop(A);
}
void div(stack& A){
    if(A.data[A.size-1]==0){
        printf("ERRORE: impossibile dividere per 0 \n");
    }
    else{
        //divisione penultimo e ultimo
        A.data[A.size-2]/=A.data[A.size-1];
        //cancellazione ultimo
        pop(A);
    }
    
}
void mult(stack& A){
    //moltiplicazione penultimo e ultimo
    A.data[A.size-2]*=A.data[A.size-1];
    //cancellazione ultimo
    pop(A);
}

void input(stack& A){
    int var_int;
    cin >> var_int; 
    if(cin.fail()){
        //se l'input è un char
        cin.clear();
        string var_char=" ";
        cin >> var_char;
        if(var_char=="sum") sum(A);
        else if(var_char=="sub") sub(A);
        else if(var_char=="div") div(A);
        else if(var_char=="mult") mult(A);
        //se carattere estraneo stampa stack
        else print_stack(A);
    }
    else{ //se l'input è un int
        //aggiungi il numero allo stack
         push(A, var_int);
    } 
}

int main(){
    //inizializza
    stack A;
    init(A);
    //put data into stack
    while(true){   
        input(A);
        }
    return 0;
}