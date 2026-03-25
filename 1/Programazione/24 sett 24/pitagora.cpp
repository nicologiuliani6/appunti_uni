#include <iostream>
#include <cmath>
using namespace std;

int main(){
  cout << "avvio" << endl;
  double x,y;
  cin >> x>>y;
  double ipotenusa = sqrt(pow(x,2)+pow(y,2));
  cout << "Ipotenusa: "<< ipotenusa << endl;
}
