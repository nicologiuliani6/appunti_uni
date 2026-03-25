// file library.cpp
#include "library.h"
namespace one {
 void min(int& a, int& b){
int tmp ;
if (a>b) { tmp = a ; a = b ; b = tmp ; } ;
 }
}
namespace two {
 void min(int& a, int& b){
int tmp ;
if (a>b) { tmp = 2*a ; a = 2*b ; b = tmp ; } ;
 }
}
