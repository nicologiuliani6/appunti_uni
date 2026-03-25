#include <iostream>
using namespace std;
struct lista {
    int val ;
    lista *next ;
};
typedef lista *plista ;
int main(){
    p_lista p1, p2, p3 ;
    p1 = new lista ;
    p1->val = 1 ;
    p2 = new lista ;
    p2->val = 2 ;
    p3 = p2 ;
    p1->next = p2 ;
    return 0;
}