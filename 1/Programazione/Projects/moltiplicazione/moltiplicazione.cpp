#include <iostream>
#include <string> //server per lenght()
#include <cmath> //server per pow()
using namespace std;

int prodotto_complesso(int n1,int n2){
    int cifra_n1;
    int cifra_n2;
    int n1_orig = n1;
    int n2_orig = n2;
    int prodotto = 0;
    for(int i=0; i<(to_string(n1_orig)).length(); i++){
    cifra_n1=n1%10;
    for(int j=0; j<(to_string(n2_orig)).length(); j++){
        cifra_n2=n2%10;
        prodotto=prodotto+(cifra_n1*cifra_n2)*pow(10, j+i);
        n2=n2/10;
        }
    n2=n2_orig;
    n1=n1/10;
  }
    return prodotto;
}


int main() {
    int n;
    cout << "Inserisci un numero n: ";
    cin >> n;
    int m;
    cout << "Insesirsci numero m: ";
    cin >> m;
    int prodotto_easy = n*m;
    cout << "Prodotto semplice: " << prodotto_easy << endl;
    cout << "Prodotto complesso: " << prodotto_complesso(m,n) << endl;
    return 0;
}
