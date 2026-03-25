#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //programma che chieda in input l'eta e il sesso M/F e li stampi a video
    int eta;
    char genere;
    printf("Inserisci l'età: \n");
    cin >> eta;
    printf("Inserisci sesso M/F: \n");
    cin >> genere;
    cout << "Età: " << eta << "\nSesso: " << genere << "\n";
}