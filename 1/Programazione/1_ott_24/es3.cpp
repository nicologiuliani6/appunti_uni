#include <iostream>
#include <cmath>
using namespace std;

int main(){
    printf("Avvio\n");
    int n,i=0;
    cin >> n;
    while(i*i<=n){
        i++;
    }
    cout << i-1 << endl;
}