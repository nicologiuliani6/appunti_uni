#include <iostream>
#include <cmath>
using namespace std;

int log(int n){
    int i=1;
    while (pow(2,i)<=n) {
        i++;
    }
    return i-1;
}

int main(){
    int n;
    printf("Inserisci n: ");
    cin >> n;
    if(n>=1){
        cout << "Log_2 (n)= " << log(n) << endl;
    }
    else{
        printf("log_2 (n)= Impossibile\n");
    }
}