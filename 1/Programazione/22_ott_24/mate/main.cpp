#include <iostream>
#include "library.h"
using namespace std;

int main(){
  printf("Avvio... \n");
  int bin=0, dec=0;
  printf("Inserisci numero in binario: ");
  cin >> bin;
  bin2dec(bin, dec);
  cout << dec <<endl;
  dec2bin(dec, bin);
  cout << bin << endl;
}
