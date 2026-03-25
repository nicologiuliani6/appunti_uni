#include <iostream>
#include <cstring>
using namespace std;
class persona{
    protected:
        char nome[50];
        int eta;
    public:
        persona(const char name[]="", int years=0){
            strcpy(nome,name);
            eta=years;
        }
        void presentati(){
            printf("Sono %s e ho %d anni ",nome,eta);
        }
};
class impiegato : public persona{
    protected:
        char reparto[50];
        int stipendio;
    public:
        impiegato(const char name[]="",int years=0,const char repartoTMP[]="", int stipendioTMP=0) : persona(name,years){
            strcpy(reparto,repartoTMP);
            stipendio=stipendioTMP;
        }
        void presentati(){
            persona::presentati();
            printf("lavoro al reparto %s e guadagno %d€ al mese",reparto,stipendio);
        }
};
int main(){
    impiegato test("Nico", 19, "Informatica", 1500);
    test.presentati();
    printf("\n");
    return 0;
}