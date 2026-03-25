#include <iostream>
using namespace std;

int main(){
  int n, sum=0;
  printf("Inserisci n: \n");
  cin >> n;
  do{
    sum+=n%10;
    n=n/10;
  }
  while (n>0);
  cout << "Somma n: "<<sum<<endl;
}
