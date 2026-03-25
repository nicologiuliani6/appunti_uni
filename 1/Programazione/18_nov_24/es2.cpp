#include <iostream>
using namespace std;

int main(){
    int *p= new int; 
    (*p)++;
    printf("%d \n",*p);
    delete p;
    return 0;
}