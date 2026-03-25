#include <iostream>
#include <cmath>
#include <ctime>

using namespace std ;
const int length = 30;

struct nodo {
    int val ;
    int next ;
};

void crea_lista(nodo A[], const int length){
    int i ;
    for (i = 0 ; i < length/2 ; i=i+2) {
        A[i].val = rand()%(2*length) ;
        A[i].next = length - i - 1;
        A[length-i-1].val = rand()%(2*length) ;
        A[length-i-1].next = i+2 ;
    }
    // l'ultimo elemento si trova immediatamente dopo il centro...
    if (i == length/2) A[i-2].next = -1 ;
    else A[i+1].next = -1 ;
}

void stampa_lista(nodo A[]){
    int i = 0 ;
    while (i != -1) {
        cout << A[i].val << ' ' ;
        i = A[i].next ;
    }
    cout << endl ;
}
int get_last (nodo A[], const int length) {
  int last=0;
  int i=0; 
  while(true){
    if(A[i].next==-1){
      last=A[i].val;
      break;
    }
    i=A[i].next;
  }
  return last;
  
}
void revert (nodo A[], const int length){
  int tmp=0;
  cout << "length="<<length<<endl;
  cout << A[29].val<<endl;
  for (int i=0; i<length/2; i+=2) {
    tmp=A[i].val;
    cout << tmp << " ";
    //A[i].val=A[length-i-1].val;
    //cout << "A[i].val="<<A[i].val << " ";
    //A[length-i-1].val=tmp;
    //cout << "A[length-i-1].val=" << A[length-i-1].val <<endl;
    
    //tmp=A[length-i-1].next;
    //cout << "TMP= "<<A[i].next<< " ";
    //A[i].next=A[length-i-1].next;
    //cout << "A[i].next="<< A[i].next<< " ";
    //A[i].next=tmp;
    //cout << "A[length-i-1].next="<< A[length-i-1].next << endl;
    //break;
  }
}
int main(){
    srand(time(0)) ;
    nodo Lista[length] ;
    crea_lista(Lista, length) ;
    stampa_lista(Lista) ;
    //cout << get_last(Lista, length) << endl;
    revert(Lista, length);
    stampa_lista(Lista);
    return(0) ;
}


