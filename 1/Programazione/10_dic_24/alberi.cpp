#include <iostream>
#include <ctime>
using namespace std;

struct btree {
    int val;
    btree* ltree;
    btree* rtree;
};
typedef btree* pbtree;
//FUNZIONE TREE
pbtree create_btree(int n) {
    if (n == 0) return(NULL) ;
    else {
        pbtree t = new btree ;
        t->val = rand()%50 ;
        t->ltree = create_btree(n-1) ;
        t->rtree = create_btree(n-1) ;
        return(t) ;
    }
}

struct stack {
    pbtree val ;
    stack* next ;
} ;
typedef stack* pstack ;
//FUNZIONI STACK
pstack push(pstack q, pbtree t){
    pstack tmp = new stack ;
    tmp->val = t ;
    tmp->next = q ;
    return(tmp) ;
}
pstack pop(pstack q) {
    if (q == NULL) return(NULL) ;
    else { 
        pstack tmp = q ;
        q = q->next ;
        delete(tmp) ;
        return(q) ; }
}
pbtree top(pstack q) {
    if (q == NULL) return(NULL) ;
    else return(q->val);
}
void visit_it(pbtree t){
    if (t != NULL){
            pbtree tmp ;
            pstack p ;
            p = push(NULL, t) ;
        while (p != NULL) {
            tmp = top(p) ;
            p = pop(p) ;
            printf("%d ",tmp->val);
            if (tmp->rtree != NULL) p = push(p, tmp->rtree) ;
            if (tmp->ltree != NULL) p = push(p, tmp->ltree) ;
        }
    }
}
int max_depth(pbtree t){
    if (t == NULL) return(0) ;
    else if ((t->ltree == NULL) && (t->rtree == NULL)) return(0) ;
    else return(1 + max(max_depth(t->ltree), max_depth(t->rtree))) ;
}

int n_nodi_ric(pbtree t){
    int sum=0;
    if (t != NULL){
        sum++;
        sum+=n_nodi_ric(t->ltree);
        sum+=n_nodi_ric(t->rtree);
    }
    return sum;
}

/* 
int n_nodi_it(pbtree t){
    if (t == NULL) return 0;
    int sum =0;
    pbtree tmp = t;
    while(t != NULL){
        pbtree tmp2;
        if(t->ltree != NULL){
            sum++;
            t=t->ltree;
        }
    }
    t = tmp;
    while(t != NULL){
        if(t->rtree != NULL){
            sum++;
            t=t->rtree;
        }
    }
    return sum;
}
*/
bool is_in(pbtree t, int n){
    if (t != NULL){
        if(t->val == n){
            return true;
        }
        return (is_in(t->ltree, n) || is_in(t->rtree, n));
    }
    return false;
}
pbtree t_insert_ric(pbtree t, int n) {
    if (t == NULL) { 
        t = new btree ;
        t->val = n ;
        t->ltree = NULL ;
        t->rtree = NULL ;
    } 
    else if (t->val == n) return(t) ;
    else if (t->val > n) t->ltree = t_insert_ric(t->ltree, n) ;
    else t->rtree = t_insert_ric(t->rtree, n) ;
    return(t) ;
}
pbtree t_insert_it(pbtree t, int n) {
    pbtree parent = NULL; // Mantiene il nodo genitore
    pbtree current = t;   // Puntatore per attraversare l'albero

    // Attraversamento dell'albero
    while (current != NULL) {
        if (current->val == n) {
            return t; // Il valore è già presente, nessuna modifica
        }
        parent = current;
        if (n < current->val) {
            current = current->ltree;
        } else {
            current = current->rtree;
        }
    }

    // Creazione del nuovo nodo
    pbtree new_node = new btree;
    new_node->val = n;
    new_node->ltree = NULL;
    new_node->rtree = NULL;

    // Collegamento al genitore
    if (parent == NULL) {
        // Se il genitore è NULL, l'albero era vuoto
        return new_node; // Il nuovo nodo diventa la radice
    } 
    else if (n < parent->val) {
        printf("messo a sinistra\n");
        parent->ltree = new_node;
    } 
    else {
        printf("messo a destra\n");
        parent->rtree = new_node;
    }

    return t; // Restituisce la radice originale
}


int main(){
    srand(time(0));
    pbtree t;
    pstack s;
    t = create_btree(4);
    push(s, t);
    visit_it(t);
    //printf("\nMax depth: %d\n",max_depth(t));
    //printf("N. nodi albero ricorsiva: %d\n",n_nodi_ric(t));
    //printf("N. nodi albero iterativa: %d\n",n_nodi_it(t));
    int n;
    n = rand()%50;
    //printf("Il numero %d è presente? %d\n",n,is_in(t,n));
    printf("\n");
    t_insert_it(t,100);
    visit_it(t);
    printf("\n");
    

}