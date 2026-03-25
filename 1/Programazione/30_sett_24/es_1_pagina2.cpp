#include <iostream>
using namespace std;

int main(){
  //3 numeri in input
  //se uno è divisore comune degli altri 2 dare 1 in input
  //se no 0
  printf("Avvio\n");
  int n1,n2,n3;
  cin >> n1 >> n2 >> n3;
  cout << ((!(n1%n2) && !(n3%n2)) || (!(n2%n1) && !(n3%n1)) || (!(n1%n3) && !(n2%n3))) << "\n";
}
