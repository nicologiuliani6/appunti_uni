#include <iostream>
using namespace std;

int main(){
  int n;
  printf("Inserisci n: ");
  cin >> n;
  for (int i = 1; i<=n; i++) {
    int j=1;
    while (j<=i) {
      printf("*");
      j++;
    }
    printf("\n");   
  }
}
