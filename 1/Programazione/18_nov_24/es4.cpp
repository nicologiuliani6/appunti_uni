#include <iostream>
#include <ctime>
using namespace std;

struct five{
    int num;
};

int main(){
    int *p=new int;
    five B;
    p1 = &(B.uno);
    *p1=rand()%30;
    p1 = &(B.due);
    *p1=rand()%30;
    p1 = &(B.tre);
    *p1=rand()%30;
    p1 = &(B.quattro);
    *p1=rand()%30;
    p1 = &(B.cinque);
    *p1=rand()%30;

    printf("%d %d %d %d %d",B.uno,B.due,B.tre,B.quattro,B.cinque);
    return 0;
}