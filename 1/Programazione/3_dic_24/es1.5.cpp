#include <iostream>
using namespace std;
//scrivere una funzione ricorsiva che prende una lista di interi e
//stampa gli interi nella lista
struct list{
    int val;
    list *next;
};
typedef list *plist;
// funzione che inserisce in testa alla lista
plist head_insert (plist head, int el){
    plist tmp ;
    tmp = new list ;
    tmp->val = el ;
    tmp->next = head ;
    return(tmp) ;
}
plist crea_lista(int n) {
    plist h = NULL ;
    for (int i = 0 ; i<n ; i = i+1)
        h = head_insert(h, rand() %(3*n-1)) ;
    return(h) ;
}

// funzione che stampa gli elementi di una lista
void stampa_lista(plist head) {
    while (head != NULL){
        cout << head->val << ' ';
        head = head->next ;
    }
    cout << endl ;
}
// codice che inverte una lista senza usare mai l'operazione new
plist revert(plist head){
    plist res = NULL ;
    plist tmp ;
    while (head != NULL) {
        tmp = head ;
        head = head->next;
        tmp->next = res;
        res = tmp;
    }
    return(res) ;
}

//funzione che stampa ricorsiva
void print_lista(plist lista){
    
    if(lista->next !=NULL){
        print_lista(lista->next);
    }
    printf("%d ",lista->val);
}
int main(){
    srand(time(0)) ;
    plist lista = NULL ;
    lista = crea_lista(20) ;
    stampa_lista(lista);
    print_lista(revert(lista));
    printf("\n");
}