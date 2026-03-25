#include <iostream>
using namespace std;

int main(){
  int num=1;
  int *p1, *p2;
  
  p1=&num;
  *p1+=2;
  
  p2=&num;
  *p2+=3;
  cout << num <<endl;
  
  return 0;
}
