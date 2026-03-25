#include <iostream>
using namespace std;
struct btree {
    int val;
    btree* ltree;
    btree* rtree ;
} ;
typedef btree* pbtree ;
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
void visit(pbtree t){
    if (t != NULL) { cout << t->val ;
    visit(t->ltree) ;
    visit(t->rtree) ; }
}
// scrivere una funzione che stampa i valori dei nodi a
// profondità 3
void print3(pbtree t, int d){
    if (t != NULL && d == 3){ 
        printf("%d ",t->val);
        print3(t->ltree,d);
        print3(t->rtree,d);
    }
    if(d<3){
        d++;
        print3(t,d);
    }
    
}
int main(){
    pbtree t = NULL;
    t = create_btree(2);
    visit(t);
    printf("\n");
    print3(t,1);
}