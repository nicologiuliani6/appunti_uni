#include <iostream>
using namespace std;
void asterischi(int n){
    if (n>0){
        for(int j=0; j<n; j++){
            printf("* ");
        }
        printf("\n");
        asterischi(n-1);
    }
}

int main(){
    int n;
    cin >> n;
    asterischi(n);
}