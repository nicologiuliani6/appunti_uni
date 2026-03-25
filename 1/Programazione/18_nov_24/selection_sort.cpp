#include <iostream>
#include <ctime>
using namespace std;
void initialize(int A[], const int length){
    srand( time(0) ) ;
    for (int i = 0; i < length ; i=i+1){
        A[i] = rand()%(3*length +1);
        }
    }
void print_Aay(const int A[], const int length){
    for (int i = 0; i < length ; i=i+1){
        cout << A[i] << ' ' ;
        }
    cout << endl ;
    }

void scambia(int& x, int& y){
  int temp=x;
  x=y;
  y=temp;
}

void selection_sort(int A[], int length){
    int i, j, min ; // si puo` anche fare evitando di usare min ...  
    int *p, *q ;
    for (i = 0 ; i < length-1 ; i = i+1){
        min = i ;
        p = &(A[i]) ;
        for (j = i+1 ; j < length ; j = j+1){
            q = &(A[j]) ;
            if (*p > *q) {
                min = j ; p = &(A[min]) ;
            }
        }
        q = &(A[i]) ;
        int tmp = *p ;
        *p = *q ;
        *q = tmp ;
    }
}


int main(){

    int length=20;
    int A[length];
    initialize(A, length);
    print_Aay(A, length);
    selection_sort(A, length);
    print_Aay(A, length);

}
