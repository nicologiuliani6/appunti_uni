#include <iostream>
#include <cstring>
using namespace std;

bool check(const char arr[], const int lenght){
    for (int i = 1; i <lenght; i++)
    {
        if((arr[i-1]=='g' && arr[i]=='h') || (arr[i-1]=='c' && arr[i]=='h')) return true;
    }
    return false;
}
int main(){
    int length=20;
    char s[length]="sono cjghad";
    cout << check(s, length) << endl;
    return 0;
}