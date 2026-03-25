#include <iostream>
#include <string>

#define K 10
struct NTree {
    int value;
    NTree* child[K];

    // Costruttore
    NTree(int val) : value(val) {
        for (int i = 0; i < K; ++i)
            child[i] = nullptr;
    }
};

struct NTree {
    int value;
    NTree* firstChild;   // Puntatore al primo figlio
    NTree* nextSibling;  // Puntatore al fratello successivo
    NTree* father;

    // Costruttore
    NTree(int val) : value(val), firstChild(nullptr), nextSibling(nullptr), father(nullptr) {}
};
void add_child(NTree* parent, NTree* child) {
    child->father = parent;  // Imposta il padre del figlio

    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        NTree* current = parent->firstChild;
        while (current->nextSibling) {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

//ESERCIZIO 2
int livelli_pari(NTree* T){
    if(!T) return 0;
    int piani_pari=0;
    //contiamo se l'attuale piano e' pari
    int counter=0;
    NTree* TMP = T;
    if(!T->father || T == T->father->firstChild){
        //se e' il primo figlio si conta il livello
        while(TMP){
            counter++;
            TMP=TMP->nextSibling;
        }
        if(counter%2==0) piani_pari++;
    }

    //aggiungiamo i piani pari dei figli dei fratelli del primo nodo
    TMP = T;
    if(!T->father || T == T->father->firstChild){
        while(TMP){
            piani_pari+=livelli_pari(T->nextSibling);
            TMP=TMP->nextSibling;
        }
    }

    //aggiungiamo dai figli in giu i piani pari
    if(T->firstChild) piani_pari+=livelli_pari(T->firstChild);
    return piani_pari;
}

int main() {
    // Albero 1
    NTree* root1 = new NTree(1);
    NTree* n2 = new NTree(2);
    NTree* n3 = new NTree(3);
    NTree* n4 = new NTree(4);
    NTree* n5 = new NTree(5);
    add_child(root1, n2);
    add_child(root1, n3);
    add_child(n2, n4);
    add_child(n3, n5);

    int res1 = livelli_pari(root1);
    std::cout << "Test 1 (expected 1): " << (res1 == 1 ? "PASS" : "FAIL, got " + std::to_string(res1)) << std::endl;

    // Albero 2
    NTree* root2 = new NTree(10);
    NTree* n20 = new NTree(20);
    NTree* n30 = new NTree(30);
    add_child(root2, n20);
    add_child(n20, n30);

    int res2 = livelli_pari(root2);
    std::cout << "Test 2 (expected 0): " << (res2 == 0 ? "PASS" : "FAIL, got " + std::to_string(res2)) << std::endl;

    // Albero 3 (solo radice)
    NTree* root3 = new NTree(100);

    int res3 = livelli_pari(root3);
    std::cout << "Test 3 (expected 0): " << (res3 == 0 ? "PASS" : "FAIL, got " + std::to_string(res3)) << std::endl;

    // Albero 4 (null)
    NTree* root4 = nullptr;

    int res4 = livelli_pari(root4);
    std::cout << "Test 4 (expected 0): " << (res4 == 0 ? "PASS" : "FAIL, got " + std::to_string(res4)) << std::endl;

    return 0;
}

