#include <iostream>
#include "queue.hpp"

struct list{
    int value;
    list* next;     
    list(int value) : value(value), next(nullptr) {}

    void print(){
        std::cout << this->value << " ";
        list* TMP = this->next;
        while(TMP){
            std::cout << TMP->value << " ";
            TMP = TMP->next;
        }
        std::cout << std::endl;
    }
};

struct double_linked_list{
    int value;
    list* next; 
    list* prev;    
};

//ESERCIZIO 6
void remove_from_first(list*& L1, list* L2){
    list* TMP1 = L1;
    list* TMP1_prec = nullptr;
    list* TMP2 = L2;
    while(TMP2){
        TMP1 = L1;
        while(TMP1){
            if(TMP2->value == TMP1->value){
                if(TMP1_prec){
                    TMP1_prec->next = TMP1->next;
                }
                else{
                    L1 = TMP1->next;
                    TMP1_prec = nullptr;
                }
            }
            else{
                TMP1_prec = TMP1;
            }
            TMP1=TMP1->next;
        }
        TMP2=TMP2->next;
    }
}
void test_remove_from_first()    {
    //esercizio 6
    list* L1 = new list(1);
    L1->next = new list(1);
    L1->next->next = new list(2);
    L1->next->next->next = new list(3);
    L1->next->next->next->next = new list(4);
    L1->next->next->next->next->next = new list(4);
    printf("LISTA 1: "); 
    L1->print();

    list* L2 = new list(1);
    L2->next = new list(3);
    L2->next->next = new list(3);
    L2->next->next->next = new list(5);
    printf("LISTA 2: "); 
    L2->print();

    printf("Rimozione...\n");
    remove_from_first(L1,L2);
    printf("LISTA 1: "); 
    L1->print();
    printf("LISTA 2: "); 
    L2->print();
}

//ESERCIZIO 13
void remove_middle_node(list*& L){
    queue<list*> Q;
    int counter=0;
    list* TMP = L;
    while(TMP){
        counter++;
        Q.enqueue(TMP);
        TMP=TMP->next;
    }
    if(counter%2==0){
        counter/=2;
    }
    else{
        counter=(counter/2)+1;
    }
    for(auto i=1; i<counter-1; i++){
        Q.dequeue();
    }
    TMP = Q.dequeue();
    TMP->next = TMP->next->next;
}
void test_remove_middle_node(){
    list* L1 = new list(1);
    L1->next = new list(1);
    L1->next->next = new list(2);
    L1->next->next->next = new list(3);
    L1->next->next->next->next = new list(4);
    L1->next->next->next->next->next = new list(4);
    printf("PRIMA: \n");
    L1->print();
    remove_middle_node(L1);
    printf("DOPO: \n");
    L1->print();
}

int main(){
    //test_remove_from_first(); //esercizio 6
    test_remove_middle_node(); //esercizio 13 (semi giusto eh)
    return 0;
}