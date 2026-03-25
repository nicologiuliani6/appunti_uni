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

int binario(int n){
  cout << "test";
  int j, val=n;
  cout << val;
  while(val>=0){
    cout << val;
    if(val==0){j++; break;}
    else{
      j++;
      val/=10;
    }
  }
  cout << "test1";
  int sum=0;
  for(int i=j; i>=0; i/=10){
    if(n%10==1){
      sum+=sum*pow(2,i);
      n/=10;
    }
  }
  return sum;
}

int sum(int n, int m){
  return (n+m);
}

int main(){
  cout << binario(3);
  printf("Inserisci numeri da sommare: ");
  int a,b,somma;
  cin >> a >> b;
  cout << "DECIMALE A: " << decimal(a) << endl;
  cout << "DECIMALE B: " << decimal(b) << endl;
  cout << "sum: " << sum(decimal(a),decimal(b))<<endl;
  somma=decimal(a)+decimal(b);
  cout << "BINARIO FINALE: "<< binario(somma) << endl;
}
