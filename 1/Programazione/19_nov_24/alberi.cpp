#include <iostream>
using namespace std;
struct btree {
    int val;          // Valore contenuto nel nodo dell'albero
    btree* ltree;     // Puntatore al sottoalbero sinistro
    btree* rtree;     // Puntatore al sottoalbero destro
};
typedef btree* pbtree ; // posso utilizzare pbtree al posto di btree*

pbtree create_btree(int n) {
    if (n == 0) return NULL;  // Caso base: se n è 0, restituisce un albero vuoto (NULL)
    else {
        pbtree t = new btree;           // Alloca dinamicamente un nuovo nodo
        t->val = rand() % 50;          // Genera un valore casuale tra 0 e 49
        t->ltree = create_btree(n - 1); // Crea ricorsivamente il sottoalbero sinistro
        t->rtree = create_btree(n - 1); // Crea ricorsivamente il sottoalbero destro
        return t;                       // Restituisce il nodo creato
    }
}

void visit(pbtree t){
    if (t != NULL) { 
        cout << t->val << "\t";
        visit(t->ltree) ;
        visit(t->rtree) ; 
    }
}


int main() {
    srand(time(0)); // Inizializza il generatore di numeri casuali

    pbtree t;
    int n = 3; // Profondità dell'albero

    t = create_btree(n); // Crea un albero binario e assegna il risultato a t
    cout << "Visita in pre-order dell'albero:\n";
    visit(t); // Visita l'albero
    cout << endl;

    return 0;
}