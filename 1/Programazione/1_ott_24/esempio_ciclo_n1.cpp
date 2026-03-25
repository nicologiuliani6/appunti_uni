#include <iostream>
#include <cmath>
#include <gmp.h> // se vuoi numeri oltre a 2^64

using namespace std;
#define MAX pow(2,64)

int main(){
    int i=0;
    while (i<MAX){
        cout << i << "\t" << pow(i,2) << "\n";
        i++;
    }
}