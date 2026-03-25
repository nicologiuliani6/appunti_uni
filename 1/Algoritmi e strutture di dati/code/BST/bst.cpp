#include <iostream>
#include <queue>
#include "bubbleSort.hpp"

struct BST{
    int key;
    int value; //questo e' il tipo di dato che memorizziamo
    BST* left;
    BST* right;
    //costruttore
    BST(const int key, const int value) : key(key), value(value), left(nullptr), right(nullptr) {}
    public:
        BST* insert(const int key, const int value) {
            if (key <= this->key) {
                if (this->left)
                    this->left->insert(key, value);
                else
                    this->left = new BST(key, value);
            }
            else {
                if (this->right)
                    this->right->insert(key, value);
                else
                    this->right = new BST(key, value);
            }
            return this;  // restituisci sempre il puntatore corrente
        }
        BST* delete_val(int key) {
            if (key < this->key) {
                if (this->left) {
                    this->left = this->left->delete_val(key);
                }
            } else if (key > this->key) {
                if (this->right) {
                    this->right = this->right->delete_val(key);
                }
            } else {
                // Nodo trovato

                // Caso 1: nessun figlio
                if (!this->left && !this->right) {
                    delete this;
                    return nullptr;
                }
                // Caso 2: un figlio solo
                else if (!this->left) {
                    BST* temp = this->right;
                    delete this;
                    return temp;
                }
                else if (!this->right) {
                    BST* temp = this->left;
                    delete this;
                    return temp;
                }
                // Caso 3: due figli
                else {
                    BST* succ = this->right;
                    while (succ->left) succ = succ->left;
                    this->key = succ->key;
                    this->right = this->right->delete_val(succ->key);
                }
            }
            return this;
        }
        BST* search(const int key){
            if(this->key == key) return this;

            if(key<=this->key){
                if(this->left) return this->left->search(key);
            }
            else if(key>this->key) {
                if(this->right) return this->right->search(key);
            }
            return nullptr;
        }
};
void print_breadth_first_levels(BST* root) {
    if (!root) return;

    std::queue<BST*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Numero di nodi nel livello corrente

        for (int i = 0; i < levelSize; ++i) {
            BST* current = q.front();
            q.pop();

            std::cout << current->value << " ";

            if (current->left)  q.push(current->left);
            if (current->right) q.push(current->right);
        }

        std::cout << std::endl;  // Vai a capo alla fine del livello
    }
}

//ESERCIZIO 9
template <typename TYPE>
struct list{
    TYPE val;
    list<TYPE>* next;
    list(const TYPE val) : val(val), next(nullptr) {}
    void sort(){
        if(this->next && this->next->val < this->val){
            TYPE tmp = this->next->val;
            this->next->val = this->val;
            this->val = tmp;
        }
        if(this->next) this->next->sort();
        list<TYPE>* TMP = this;
        while(TMP->next){
            if(TMP->val > TMP->next->val) this->sort();
            TMP=TMP->next;
        }
    }
    //costo: O(n^2)
    void print(){
        std::cout<< this->val << " ";
        if(this->next) this->next->print();
    }
};
list<int>* insert_bst_in_list(BST* T){
    if (!T) return nullptr;
    list<int>* L = new list<int>(T->value);
    L->next = insert_bst_in_list(T->left);
    list<int>* TMP = L;
    while(TMP->next){
        TMP=TMP->next;
    }
    TMP->next = insert_bst_in_list(T->right);
    return L;
}
//costo O(n)
int count_nodes(BST* T){
    if(!T) return 0;
    return 1+count_nodes(T->left)+count_nodes(T->right);
}
//costo O(n)
#define NA -1 //settiamo la costante NA
int k_esimimo_min(BST* T, const int k){
    if(!T && k<=0) return NA;
    if (k>count_nodes(T->left)+count_nodes(T->right)+1) return NA;
    auto L = insert_bst_in_list(T);
    L->sort();
    for(auto i=1; i<k; i++){
        L = L->next;
    }
    return L->val;
}
//costo O(n^2)

int main() {
    BST* root = new BST(10, 10);
    root->insert(5, 5);
    root->insert(15,15);
    root->insert(3,3);
    root->insert(7,7);
    root->insert(6,6);
    root->insert(12,12);
    root->insert(18,18);

    std::cout << "Stampa in ampiezza dell'albero BST:\n";
    print_breadth_first_levels(root);
    
    //esercizio 9
    int k = 8;
    printf("Valore minore k=%d: %d\n",k,k_esimimo_min(root,k));
    return 0;
}