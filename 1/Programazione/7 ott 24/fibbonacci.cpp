#include <iostream>
#include <cmath>
using namespace std;

int fib(int n){
    if (n<=1){
        return 1;
    }
    int f0=1,f1=1,fn;
    int i=2; //indice 

    while (i<=n){
        fn=f1+f0;
        f0=f1;
        f1=fn;
        i++;
    }
    return fn;

}

int main(){
    int n;
    printf("Inserisci n: \n");
    cin >> n;
    cout << "Valore di fibbonacci: " << fib(n) <<endl;
}