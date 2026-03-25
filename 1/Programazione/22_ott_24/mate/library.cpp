#include "library.h"
#include <cmath>
#include <iostream>
using namespace std;

void bin2dec(int& bin, int& dec){
  int k=0;
  while(bin>0){
    dec+=(bin%10)*pow(2,k);
    bin/=10;
    k++;
  }
}

void dec2bin(int& dec, int& bin) {
    int place = 1;  // Per tenere traccia della posizione delle cifre binarie
    bin = 0;  // Inizializza bin a zero
    while (dec > 0) {
        int remainder = dec % 2;  // Ottieni il bit meno significativo
        bin += remainder * place;  // Aggiungi il bit alla posizione corretta
        dec /= 2;  // Dividi dec per 2 per continuare la conversione
        place *= 10;  // Sposta la posizione a sinistra
    }
}
