#include <iostream>
using namespace std;
//scrivere una funzione ricorsiva che prende n e stampa n
//asterischi

void print_asterischi(int n){
    //printf("%d",n);
    if (n>0){
        printf("*");
        print_asterischi(n-1);
    } 
}

int main(){
    int n;
    printf("inserisci n ");
    cin >> n;
    print_asterischi(n);
    printf("\n");
}