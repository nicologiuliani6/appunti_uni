#include <iostream>
#include <cmath>
using namespace std;

void soluzioni(double a, double b, double c, double& sol1, double& sol2){
  double temp=sqrt(pow(b,2)*4*a*c);
  sol1=(-b+temp)/(2*a);
  sol2=(+b-temp)/(2*a);
}

int main(){
  double x1, x2;
  soluzioni(5,28,16,x1, x2);
  cout << "X1: " << x1 << endl;
  cout << "X2: " << x2 << endl;

}
