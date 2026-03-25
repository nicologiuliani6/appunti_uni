#include <iostream>
using namespace std;

int main(){
    int *p; //p ha il valore del suo indirizzo di memoria
    printf("%d \t %d \n",p,*p); //p=*p=address
    //PRIMO MODO (variabile dinamica)
    p = new int; //p assume il valore di un altro indirizzo
                 //p si trova nello stack, l'indirizzo in p si trova nel head
                 // p=[__x__]; x=[____]
    printf("%d \t %d \n",p,*p); //p=new address1 *p=0
    *p=1;         //p=[__x__] ; x=[__1__] //p=new address1 *p=1
    printf("%d \t %d \n",p,*p);

    //SECONDO MODO
    int z;
    z=7;
    printf("%d \n",z);
    p=&z; //p=address of z; *p=z
    printf("%d \t %d \n",p);

    //
    p=NULL;
    printf("%d \n",p);
    delete p; //non fa nulla perchè p=NULL

    p = new int; //p=[_Y_]; Y=[__]
    *p=34;       //p=[_Y_]; Y=34
    printf("%d \t %d \n",p,*p);
    delete p;    //p=[_Y_]; Y=[__] 
    printf("%d \t %d \n",p,*p);

    p=&z;
    //delete p;

    //alias
    int *q;
    p= new int;
    printf("%d \t %d \n",p,q);
    q=p;
    *q=1;
    printf("%d \n",*p);

    return 0;
}