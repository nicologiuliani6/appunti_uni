#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y>> z;
  cout << "\t" << x << "\t" << y << "\t" << z << endl;
  cout << x << "\t" <<x-x << "\t" << x-y << "\t" << x-z << endl;
  cout << y << "\t" << y-x << "\t" << y-y << "\t" << y-z << endl;
  cout << z << "\t" <<z-x << "\t" << z-y << "\t" << z-z << endl;

  return 0;
}
