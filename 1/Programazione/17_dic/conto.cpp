#include <iostream>
using namespace std;
class contoBanca{
    protected:
        double saldo;
    public:
        contoBanca(double temp_saldo=0){
            saldo=temp_saldo;
        }
        void print_conto(){
            cout << "SALDO: " << saldo << endl;
        }
        void versa(int tmp=0){
            saldo+=tmp;
        }
        void preleva(int tmp=0){
            saldo-=tmp;
        }
};
class contoInteressi : public contoBanca{
    public:
        contoInteressi(double temp_saldo=0) : contoBanca(temp_saldo){}
        void interessi(){
            saldo+=saldo*0.02;
        }
};

int main(){
    contoBanca test(500);
    test.print_conto();
    test.versa(400);
    test.preleva(500);
    test.print_conto();

    contoInteressi test_interessi(500);
    test_interessi.interessi();
    test_interessi.print_conto();

    return 0;
}