#include <iostream>
using namespace std;

//scrivere write_vertical in maniera che le cifre sono
//stampate dalla più significativa alla meno significativa
void write_vertical_1(int n){
    if((n/10)>=9){
        write_vertical_1(n/10);
    }
    printf("%d\n",n%10);
}
//scrivere write_vertical in maniera che le cifre sono
//stampate dalla meno significativa alla più significativa
void write_vertical_2(int n){
    if((n/10)<9){
        printf("%d\n",n);
    }
    else{
        printf("%d\n",n%10);
        write_vertical_2(n/10);
    }
}

int main(){
    int n;
    printf("inserisci n ");
    cin >> n;
    write_vertical_2(n);
}