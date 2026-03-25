#include <iostream>

using namespace std;

int main(){
  int *p= new int();
  *p=1;
  (*p)++;
  cout << *p << endl;
  delete p;
  p= NULL;
  return 0;
}
