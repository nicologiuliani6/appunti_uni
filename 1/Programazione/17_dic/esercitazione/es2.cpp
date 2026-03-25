#include <iostream>
#include <cstring>
using namespace std;

struct attivita {
    char nome[50];
    int durata;
    char intensita;
    attivita* next;
};
typedef attivita *plist;

plist insert_attivita(plist A, const char nome[], int durata, const char intensita){
    //
    plist add = (plist)malloc(sizeof(attivita));
    if(add==NULL){
        cerr << "ERRORE MEMORIA\n";
    }
    strcpy(add->nome, nome);
    add->durata = durata;
    add->intensita = intensita;
    add->next = nullptr;
    
    //
    if (A == nullptr || A->durata > durata) {
        add->next = A;
        A = add;
        return A;
    }
    
    plist tmp = A;
    while((tmp->next != nullptr) && (tmp->next->durata <= durata)){
        //printf("iterazione\n");
        tmp=tmp->next;
    }
    //qui siamo al tmp con al successivo quello da inserire
    //printf("Aggiunta lenta\n");
    add->next=tmp->next;
    tmp->next=add;
    
    return A;
    //esce con l'ultimo NON null
}
plist rimuovi_attivita(plist l, const char nome[]){
    
    if (l == nullptr || strcmp(l->nome,nome)==0){
        //se è vuota o se è l'attuale
        //printf("SKIPPATO veloce\n");
        return l->next;
    }
    plist tmp = l;
    while(tmp->next != nullptr){
        if(strcmp(tmp->next->nome,nome)==0){
            //se il prossimo è found skippa
            //printf("SKIPPATO lento\n");
            tmp->next=tmp->next->next;
        }
        tmp=tmp->next; //vai avanti
    }
    return l;
}
int main(){
    plist A = NULL;
    A = insert_attivita(A, "gag", 10, 'm');
    A = insert_attivita(A, "pilates", 15, 'f');
    printf("1: %s \n2: %s \n",A->nome,A->next->nome);
    A = rimuovi_attivita(A, "gag");
    printf("1: %s \n2: %s \n",A->nome,A->next->nome);

    return 0;
}