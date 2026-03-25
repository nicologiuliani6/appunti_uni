// file working.cpp
#include <iostream>
#include "library.h"
using namespace std;
using namespace two;
int main (){
int a=2, b=1;
one::min(a,b) ;
cout << a << "\t" << b ;
 min(a,b) ;
cout << a << "\t" << b ;
return(0) ;
}
