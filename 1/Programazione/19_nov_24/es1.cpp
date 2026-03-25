#include <iostream>
#include <ctime>
using namespace std;
struct lista {
    int val ;
    lista *next ;
} ;
typedef lista *plista ;
plista head_insert (plista head, int el){
    plista tmp ;
    tmp = new lista ;
    tmp->val = el ;
    tmp->next = head ;
    return(tmp) ;
}
void stampa_lista(plista head) {
    plista current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int last(plista head){
    plista current = head;
    while (current != NULL) {
        if (current-> next == NULL) {
            return current->val;
        }
        current = current->next;
    }
    printf("Lista vuota \n");
    return 0; 
}
void create(plista& h, int n){
    for(int i=0; i<n; i++){
        h = head_insert(h,rand()%30);
    }
}
int main(){
    plista h = NULL;
    //metodo 1
    //h = head_insert(h,1);
    //h = head_insert(h,2);
    //h = head_insert(h,3);
    //metodo 2
    //h = head_insert(head_insert(head_insert(h,1),2),3);
    //metodo 3
    srand(time(0));
    create(h,0);
    printf("LAST: %d \n",last(h));
    stampa_lista(h);
    
    return 0;
}