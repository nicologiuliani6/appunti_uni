#include <iostream>
#include <cmath>
using namespace std;


int main(){
  const double pi_greco = 3.14;
  double raggio;
  cout << "Inserisci raggio:" << endl;
  cin>>raggio;
  cout << pi_greco*pow(raggio, 2)<<endl;

  return 0;
}
