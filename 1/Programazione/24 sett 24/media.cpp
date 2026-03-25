#include <iostream>
using namespace std;

int main(){
  cout << "avvio: "<<endl;
  int x,y,z;
  cin >> x>>y>>z;
  double media = (x+y+z)/(double)3; //si può anche scrivere (x+y+z)/3.0
  cout << media << endl;
  return 0;
}
