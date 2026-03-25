#include <iostream>
using namespace std;

int main(){
    int x=0;
    int *p,*q;
    p=&x;
    *p=*p+1;
    q=p;
    *q=*q+1;
    printf("x=%d \n",x);
    return 0;
}