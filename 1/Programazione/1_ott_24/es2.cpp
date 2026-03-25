#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, f=1;
    cin >> n;
    while(n>0){
        f=f*(n);
        n--;
    }
    cout << f << endl;
    return 0;
}