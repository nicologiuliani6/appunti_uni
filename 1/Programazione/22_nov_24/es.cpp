#include <iostream>
#include <ctime>
using namespace std;
typedef int Prt; //definizione per la lettura ottimale del codice
const int MAX = 10; //grandezza massima nodo
struct node {
    int value;
    Prt next;   
};
struct list
{
    node Nodo[MAX];
    Prt head; //inizio della lista
    Prt free; //posizione libera in poi
};

//funzioni
void init(list& L){
    L.head=-1;
    L.free=0;
    for (int i = 0; i < MAX-1; i++)
    {
        L.Nodo[i].value=0;
        L.Nodo[i].next=i+1;
    }
    L.Nodo[MAX-1].next=-1;
}
Ptr alloc(List& L, int elem, Ptr next) {
    const Prt Libero = L.free; //Libero= attuale free
    if(Libero == -1){
        printf("out of memory"); //ERRORE LISTA LIBERA VUOTA;
        return -1;
    }
    else{
        L.free = L.Nodo[Libero].next; //nuovo free = al next di Libero
        L.Nodo[Libero].value=elem;
        L.Nodo[Libero].next=next;
        return Libero; //ritorna la posizione del elemento aggiunto
    }
}
void free(List& L, Prt position){
    if(position =! -1){
        L.Nodo[position].value=0;
        //infiliamo in mezzo il nodo position in free
        L.Nodo[position].next=L.free; //inseriamo il next come l'attuale free
        L.free=p;                     //inseriamo il Nodo[position] come primo in free
    }
}
void push_front(List& L, int elem){
    const Prt p=alloc(L,elem,L.head);
    if(p!=-1){
        //se non è pieno
        L.head=p;
    }
    
}
void pop_front(List& L){
    if(L.head != -1){
        //se non è vuota la lista
        const Ptr p = l.head;
        L.head = L.Nodo[L.head].next; // il nuovo primo elemento in testa sarà il vecchio secondo elemento
        free(L, p); //elimina il primo in testa
    }
}
void push_back(List& L, int elem){
    Prt p = l.head;
    if(p==-1){
        push_front(L,elem);
        return;
    }
    // Trova l'ultimo nodo
    Ptr p = l.head;
    while (l.node[p].next != -1) {
        p = l.node[p].next;
    }
     // Alloca un nuovo nodo
     if(alloc(L,elem,-1)!=-1){
        L.Node[p]=alloc(L,elem,-1); //se non è pieno, alloca in lista l'elemento come ultimo
     }
}
int main(){
    list lista;
    init(lista);
    alloc(lista, 5, 1); //alloca alla lista il valore 5 nell primo nodo libero e imposta come nodo successivo il Nodo[1]
    free(lista, 0); //cancella il Nodo[0]
    push_front(lista, 8); //aggiungi 8 come value in un nuovo nodo che andrà come primo in Head
    pop_front(lista); //elimina il primo elemento in testa

    return 0;
}