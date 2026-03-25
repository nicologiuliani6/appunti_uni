#include <iostream>
#include <cmath>
using namespace std;
//scrivere una funzione ricorsiva che prende n e stampa un
//numero di asterischi uguale alla somma dei quadrati dei primi n
//numeri naturali

void print_asterischi_somma_quadriati_n(int n){
    //CALCOLO SOMMA DEI QUADRATI FINO AD N
    int somma=0;
    for(int i =1; i<=n; i++){
        somma+=i*i;
    }
    printf("SOMMA: %d\n", somma);
     if (somma>0){
        printf("*");
        print_asterischi_somma_quadriati_n(somma-1);
    } 

}

int main(){
    int n;
    printf("inserisci n ");
    cin >> n;
    print_asterischi_somma_quadriati_n(n);
    printf("\n");
}