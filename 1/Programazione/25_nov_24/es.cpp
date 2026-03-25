//
// Created by Cosimo Laneve on 19/11/24.
//
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std ;

struct lista {
    int val ;
    lista *next ;
} ;
typedef lista *plista ;

// funzione che inserisce in testa alla lista
plista head_insert (plista head, int el){
    plista tmp ;
    tmp = new lista ;
    tmp->val = el ;
    tmp->next = head ;
    return(tmp) ;
}

// funzione che stampa gli elementi di una lista
void stampa_lista(plista head) {
    while (head != NULL){
        cout << head->val << ' ';
        head = head->next ;
    }
    cout << endl ;
}

// funzione che ritorna il campo val dell'ultimo nodo della lista
// PreCondition: i nodi della lista contengono valori positivi
// PostCondition: la funzione ritorna -1 se la lista e` vuota
int get_last(plista head){
    if (head == NULL)
        return(-1) ;
    else {
        while (head->next != NULL)
            head = head->next ;
        return(head->val) ;
    }
}

// scrivere una funzione che crea una lista di lunghezza n (presa in input)
// i cui elementi sono numeri generati casualmente e ritorna il puntatore alla testa.

plista crea_lista(int n) {
    plista h = NULL ;
    for (int i = 0 ; i<n ; i = i+1)
        h = head_insert(h, rand() %(3*n-1)) ;
    return(h) ;
}

plista revert(plista head){
    plista res = NULL ;
    plista tmp ;
    while (head != NULL) {
        tmp = head ;
        head = head->next;
        tmp->next = res;
        res = tmp;
    }
    return(res) ;
}
int avg(plista L){
    plista tmp;
    int media=0, i=0;
    tmp = L;
    while(tmp!=nullptr){
        //calcolo somma dei valori
        media+=tmp->val;
        tmp=tmp->next;
        i++; //calcolo lunghezza lista
    }
    tmp=L; //reset temp
    media=media/i;
    int best=tmp->val;
    int resto=abs(media-best); //calcolo resto assoluto
    while(tmp!=nullptr){
        if (abs(tmp->val-media)<abs(resto)){ //se il resto relativo assoluto è meglio
            best=tmp->val;
            resto=abs(tmp->val-media);
        }
        tmp=tmp->next;
    }
    return best;
}

plista dequeue(plista head){
 if (head->next == NULL) {
    delete head ;
    head = NULL ;
 } 
 else {
    plista p, p_before ;
    p_before = head ;
    p = p_before;
    while(p->next != NULL && p_before != NULL){
        p_before=p;
        p=p->next;
    }
    if(p==p_before) return NULL;
    else{
        delete p ;
        p_before->next = NULL ;
        return head;
    }
 }
}
int main(){
    srand(time(0)) ;
    plista h = NULL ;
    h = crea_lista(10) ;
    // h = head_insert(head_insert(head_insert(h,1),2),3) ;
    //stampa_lista(h) ;
    h = revert(h) ;
    stampa_lista(h) ;
    dequeue(h);
    stampa_lista(h);
    printf("Numero più vicino alla media: %d \n",avg(h));
    return(0) ;
}