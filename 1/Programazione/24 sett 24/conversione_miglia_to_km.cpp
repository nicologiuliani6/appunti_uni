#include <iostream>
using namespace std;

#define KMS_TO_MILE 1.609 //la "variabile" viene sostituita dal valore quindi non occupa byte


int main(){
  double kms, miles;
  cout << "distanza in miglia? ";
  cin >> miles;
  kms = KMS_TO_MILE*miles;
  cout << "la corrispondente distanza in km è: ";
  cout << kms << endl;
  return 0;
}
//Quanto spazio di memoria occorre?
//dato che ci sono 2 double
//e che un double sono 8 byte
//saranno 16 byte totali (al netto di c++)
//
