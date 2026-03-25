#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  std::cout << rand()%90<<endl; //il %90 regola che escono i numeri dal 0 a 89
  return 0;
}
