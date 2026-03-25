#include <iostream>
using namespace std;
void write_vertical(int n) {
    if (n <= 9) cout << n << endl;
    else { write_vertical (n/10) ;
    cout << n%10 << endl ;
}
}
int main(){
    int n;
    printf("Inserisci un numero: ");
    cin >> n;
    if(n>=0){
        write_vertical(n);
    }
}