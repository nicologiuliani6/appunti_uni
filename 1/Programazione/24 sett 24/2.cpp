#include <iostream>
using namespace std;

int main(){
  double x,y,z;
  cin >> x>>y>>z;
  x=y+x;
  y=x-y;
  x=x-y;
  x=x+z;
  z=x-z;
  x=x-z;
  cout << x << endl << y << endl<<z;
  return 0;
}
