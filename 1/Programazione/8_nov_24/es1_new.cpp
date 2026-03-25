#include <iostream>
#include <cstring>
using namespace std;

void longest(const char A[], const char B[], const char C[]){
  if(strlen(A)>strlen(B) && strlen(A)>strlen(C)){
    cout << A<< endl;
  }
  else if(strlen(B)>strlen(A) && strlen(B)>strlen(C)){
    cout << B<< endl;
  }
  else{
    cout << C<< endl;
  }
}

void alfabetic_order(const char A[], const char B[]){
  int length;
  if(strlen(A)<strlen(B)){
    length=strlen(A);
  }
  else {
    length=strlen(B);
  }
  for (int i = 0; i < length; i++) {
      if(A[i]<B[i]){
      cout << A << endl;
      break;
    }
    else if (B[i]<A[i]) {
      cout << B << endl;
      break;
    }
  }
}

int main(){
  char A[]="gaia";
  char B[]="nicolò";
  char C[]="hi";
  //longest(A,B,C);
  alfabetic_order(A,B);
}
