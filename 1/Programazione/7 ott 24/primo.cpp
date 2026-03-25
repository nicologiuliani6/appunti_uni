#include <iostream>
using namespace std;

int main(){
  int n,i;
  printf("Inserisci n: \n");
  cin >>n;
  i=n-1;
  while (i>1) {
    if(n%i==0){
      printf("Non primo\n");
      return 0;
    }
    i--;
  }
  printf("Primo \n");
}
