#include <iostream>

struct tree {
    int value;
    tree* left;
    tree* right;

    // Costruttore
    tree(int val) : value(val), left(nullptr), right(nullptr) {}
};


void visit(tree* T){
    std::cout << T->value << " ";
}
void pre_order(tree* T){
    if(T){
        visit(T);
        pre_order(T->left);
        pre_order(T->right);
    }
}
void post_order(tree* T){
    if(T){
        post_order(T->left);
        post_order(T->right);
        visit(T);
    }
}
void in_order(tree* T){
    if(T){
        in_order(T->left);
        visit(T);
        in_order(T->right);
    }
}

struct queue {
    struct node {
        tree* T;
        node* next;
        node(tree* t) : T(t), next(nullptr) {}
    };

    node* head = nullptr;  // testa della coda
    node* tail = nullptr;  // coda della coda
    int size = 0;

    void enqueue(tree* T) {
        node* newNode = new node(T);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    tree* dequeue() {
        if (!head) return nullptr; // coda vuota
        node* tmp = head;
        tree* ret = tmp->T;
        head = head->next;
        if (!head) tail = nullptr; // se coda ora vuota, resetta tail
        delete tmp;
        size--;
        return ret;
    }

    bool empty() {
        return size == 0;
    }
};
void BFS(tree* T){
    queue* Q = new queue();
    if(T){
        Q->enqueue(T); //metti in prima pos della cosa la radice
    }
    while(Q->size != 0){
        tree* x = Q->dequeue(); //togli e prendi il primo elemento della coda
        visit(x); //stampa quel elemento
        if(x->left){
            Q->enqueue(x->left); //metti in coda il figlio sinistro
        }
        if(x->right){
            Q->enqueue(x->right); //metti in coda il figlio destro
        }
        //continua finche' ci sono figli
    }
}

int countnodes(tree* T){
    if (!T) return 0;
    else return 1+countnodes(T->left)+countnodes(T->right);
}

bool is_the_same(tree* T1, tree* T2){
    if(!T1 && !T2) return true;
    else if ((T1 && !T2) || (!T1 && T2)) return false;
    return (T1->value==T2->value)&&(is_the_same(T1->left,T2->left))&&(is_the_same(T1->right,T2->right));
}

//ESERCIZIO 4
int node_at_k(tree* T, const int k){
    if(!T) return 0;
    if(k==0) return 1;
    int counter=0;
    counter+=node_at_k(T->left,k-1);
    counter+=node_at_k(T->right,k-1);
    return counter;
}
//ESERCIZIO 5
int leaf_meq_k(tree* T, const int k){
    if(!T) return 0;
    if(k<=0 && !T->left && !T->right) return 1;
    return leaf_meq_k(T->left, k-1)+leaf_meq_k(T->right, k-1);
}
//ESERCIZIO 10
bool is_perfect(tree* T){
    if(!T) return true;
    if(!T->left && !T->right) return true;
    if((!T->left && T->right) || (T->left && !T->right)) return false;
    if((!T->left->left || !T->left->right) && (T->right->left && T->right->right)) return false;
    if((T->left->left && T->left->right) && (!T->right->left || !T->right->right)) return false;
    return is_perfect(T->left)&&is_perfect(T->right);
}
//costo O(n)

int main(){
    printf("PARTE 1: \n");
    tree* T = new tree(1);
    T->left = new tree(2);
    T->right = new tree(3);
    T->left->left = new tree(4);
    T->left->right = new tree(5);
    T->left->left->left = new tree(6);

    std::cout << "Visita in pre_order: \n";
    pre_order(T);
    std::cout<<std::endl;

    std::cout << "Visita in post_order: \n";
    post_order(T);
    std::cout<<std::endl;

    std::cout << "Visita in in_order: \n";
    in_order(T);
    std::cout<<std::endl;

    std::cout << "Visita in ampiezza (livelli): \n";
    BFS(T);
    std::cout<<std::endl;

    std::cout << "Numero nodi: " << countnodes(T) << std::endl;

    printf("PARTE 2: \n");
    tree* T1 = new tree(1);
    T1->left = new tree(2);
    T1->right = new tree(3);
    T1->left->left = new tree(4);
    T1->left->right = new tree(5);
    T1->left->left->left = new tree(6);
    
    tree* T2 = new tree(1);
    T2->left = new tree(2);
    T2->right = new tree(6);
    T2->left->left = new tree(4);
    T2->left->right = new tree(5);
    //T2->left->left->left = new tree(6);

    std::cout << (is_the_same(T1,T2) ? "sono uguali" : "non sono uguali") << std::endl;

    printf("PARTE 3: \n");
    int k=2;
    std::cout << "Numero nodi a profondita' k=" << k << ": " << node_at_k(T,k) <<std::endl;
    std::cout << "Numero foglie a profondita' k=" << k << " e sopra: " << leaf_meq_k(T,k) <<std::endl;
    
    //es10
    printf("PARTE 4:\n");
    std::cout << (is_perfect(T) ? "E' perfetto" : "Non e' perfetto") << std::endl;
    return 0;
}