#include <iostream>
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

plista crea_lista(int n) {
    plista h = NULL ;
    for (int i = 0 ; i<n ; i = i+1)
        h = head_insert(h, rand() %(3*n-1)) ;
    return(h) ;
}
int get_last(plista head){
    if (head == NULL)
        return(-1) ;
    else {
        while (head->next != NULL)
            head = head->next ;
        return(head->val) ;
    }
}

plista revert_recursive(plista head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    plista tmp = revert_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}



int main(){
    srand(time(0)) ;
    plista h = NULL ;
    h = crea_lista(10);
    // h = head_insert(head_insert(head_insert(h,1),2),3) ;
    stampa_lista(h) ;
    //printf("Somma interi lista: %d",sum_lista(h, 0));
    h = revert_recursive(h);
    stampa_lista(h);
    return(0) ;
}