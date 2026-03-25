//Una coda è un contenitore di elementi tale per cui il primo elemento inserito
//è anche il primo che viene rimosso. Le operazioni caratteristiche supportate
//da una coda sono front e back (lettura del primo e dell’ultimo elemento della
//coda), enqueue (inserimento di un elemento in coda) e dequeue (rimozione
//dell’elemento in testa). Implementare una coda che sia in grado di contenere
//elementi di tipo int utilizzando la seguente struttura
#include <iostream>
using namespace std;
const int MAX = 20;
struct Queue {
    int data[MAX];
    int head; // indice del primo elemento della coda
    int size; // numero di elementi nella coda
};
void init(Queue& q){
    q.size=0;
    q.head=0;
    for (int i = 0; i < MAX; i++)
    {
        q.data[i]=0;
    }
}
void put_in(Queue& q){
    //FUNZIONE FACOLTATIVA
    srand(time(NULL));
    for (int i=0; i < MAX; i++)
    {
        q.size=i+1;
        q.data[i]=rand()%100; //numeri casuali da 0 a 100
    }  
}
bool empty(Queue q){
    if(q.size==0){
        return true;
    }
    else{
        return false;
    }
}
bool full(Queue q){
    if(q.size==MAX){
        return true;
    }
    else{
        return false;
    }
}
int front(Queue q){
    if(q.size==0){
        return -1;
    }
    else{
        return q.data[q.head];
    }
}
int  back(Queue q){
    if(q.size==0){
        return -1;
    }
    else{
        return q.data[q.head+q.size-1];
    }
}
void enqueue(Queue& q, int elem){
    if(q.size==MAX){
        printf("ERRORE: coda piena\n");
    }
    else{
        q.data[q.head+q.size]=elem;
    }
}
void dequeue(Queue& q){
    q.data[q.head]=0;
    q.size--;
    q.head++;
}
void print_queue(Queue q){
    for (int i = q.head; i < MAX; i++)
    {
        printf("%d ",q.data[i]);
    }
    printf("\n");
}
int main(){
    Queue q;
    init(q);
    put_in(q);
    printf("La coda è vuota: %s \n", empty(q)?"vero":"falso");
    printf("La coda è piena: %s \n", full(q)?"vero":"falso");
    printf("Primo elemento in coda: %d \n",front(q));
    printf("Ultimo elemento in coda: %d \n",back(q));
    int elem=5;
    enqueue(q, elem);
    dequeue(q);
    print_queue(q);
    return 0;
}