#include <iostream>
#include <cmath>

using namespace std;

int main(){
    printf("Avvio\n");
    int n, somma=0;
    cin >> n;
    while(n>0){
        somma = somma + n;
        n--;
    }
    cout << somma << "\n";
    return 0;
}