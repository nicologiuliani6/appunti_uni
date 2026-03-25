#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
void initialize(int A[], const int length){    
    srand( time(0) ) ;    
    for (int i = 0; i < length ; i=i+1){
        A[i] = rand()%(3*length +1);
        }
    }

void print_array(int A[], const int length){    
    for (int i = 0; i < length ; i=i+1){        
        cout << A[i] << ' ' ;
        }    
    cout << endl ;
    }

int get_min(int A[], const int lenght){
    int best=A[0];
    for(int i=0; i<=lenght; i++){
        if(A[i]<best){
            best=i;
        }
    }
    return best;
}

bool is_palindrome(int A[], int length){
    int B[length];
    for(int i=0; i<length; i++){
        B[(i)]=A[(length-i-1)];
    }
     for(int i=0; i<length; i++){
        if(A[i]!=B[i]){
            return false;
        }
     }
     return true;
}

const int lunghezza = 20 ;
int main(){
    printf("Avvio... \n");
    int n;
    int A[lunghezza];//= {1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1};
    initialize(A, lunghezza);
    print_array(A, lunghezza);
    cout <<"MIN: "<<get_min(A, lunghezza) << endl;
    if(is_palindrome(A, lunghezza)){
        cout << "è palindromo"<<endl;
    }
    else{
        cout << "non è palindromo"<<endl;
    }


}