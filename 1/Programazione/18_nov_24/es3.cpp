#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int A[10];
    srand(time(0));
    int *p;
    for(int i=0; i<10; i++){
        p=&(A[i]);
        *p=rand()%31;
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}