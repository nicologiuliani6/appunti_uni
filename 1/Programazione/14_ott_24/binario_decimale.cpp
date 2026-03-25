#include <iostream>
#include <cmath>
using namespace std;

int decimal(int n){
  int k=0,val=0;
  while(n>0){
    val+=(n%10)*pow(2,k);
    n=n/10;
    k++;
  }
  return val;
}

int main(){
  printf("Inserisci binario: ");
  int b;
  cin >> b;
  cout << "Decimale: "<< decimal(b)<<endl;
}
