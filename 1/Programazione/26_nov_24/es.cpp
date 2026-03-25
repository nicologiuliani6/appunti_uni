#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct lista {
    int val ;
    lista *next ;
};
typedef lista *plista ;
// funzione che inserisce in testa alla lista
plista head_insert (plista head, int el){
    plista tmp ;
    tmp = new lista ;
    tmp->val = el ;
    tmp->next = head ;
    return(tmp) ;
}
plista crea_lista(int n) {
    plista h = NULL ;
    for (int i = 0 ; i<n ; i = i+1)
        h = head_insert(h, rand() %(3*n-1)) ;
    return(h) ;
}
// funzione che stampa gli elementi di una lista
void stampa_lista(plista head) {
    while (head != NULL){
        cout << head->val << ' ';
        head = head->next ;
    }
    cout << endl ;
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
//scrivere una funzione che prende in input una lista di interi ed un
//valore e e ritorna la lista senza il nodo che contiene quel valore 
 void remove_element(plista &head, const int elem) {
    //CASE ELEMENTO IN TESTA
    while (head != NULL && head->val == elem) {
        plista temp = head;
        head = head->next;
        delete temp;
    }
    plista current = head;
    // Scansionare la lista per rimuovere l'elemento
    while (current != NULL && current->next != NULL) {
        if (current->next->val == elem) {
            plista temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}


int main(){
    srand(time(0)) ;
    plista lista = NULL ;
    lista = crea_lista(10) ;
    stampa_lista(lista);
    remove_element(lista, 5);
    stampa_lista(lista);
}