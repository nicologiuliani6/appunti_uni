#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float base, altezza;
    printf("Inserisci base: ");
    cin >> base;
    printf("Inserisci altezza: ");
    cin >> altezza;
    printf("Area: %f \n", base*altezza*2); //%d indica il posto per l'intero & %f per i numeri decimali

    return 0;
}