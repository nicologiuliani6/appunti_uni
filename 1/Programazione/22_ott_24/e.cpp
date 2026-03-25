#include <iostream>
using namespace std;

void assign(int &x, int e){
  x=e;
}

int main () {
  int x;
  assign(x,32);
  cout << x << endl;

  return 0;
}
