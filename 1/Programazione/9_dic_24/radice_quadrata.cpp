#include <iostream>
using namespace std;
int radice_quadrata_ric(int n, int guess){
    if(n == 1){
        return 1;
    }
    if (guess*guess <= n){
        return radice_quadrata_ric(n, guess+1);
    }
    return guess-1;
}


int main(){
    int n;
    cin >> n;
    cout << radice_quadrata_ric(n, 1)<<endl;
    return 0;
}