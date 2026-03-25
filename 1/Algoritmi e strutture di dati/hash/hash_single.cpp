#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct list{
public:
    int first;
    string second;
    list* next = nullptr;
    //costruttore
    list(const int first, const string second){
        this->first = first;
        this->second = second;
    }
    void print(){
        std::cout << "First: " << this->first << std::endl;
        std::cout << "Second: " << this->second << std::endl;
    }
} *plist;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    plist table[TABLE_SIZE] = {nullptr};
    //funzione hash
    int hash(const string& key){
        int HashValue = 0;
        for (char cr : key){
            HashValue+=cr;
        }
        return HashValue % TABLE_SIZE;
    }
public:
    void insert(const string& key, const int value){
        int index = hash(key);
        if (this->table[index] == nullptr){
            this->table[index] = new list(value, key);
        }
        else {
            if (this->table[index]->next == nullptr){
                this->table[index]->next = new list(value, key);

            }
            else{
                plist TMP = this->table[index]->next;
                while (TMP->next != nullptr){
                    TMP = TMP->next;
                }
                this->table[index]->first = value;
                this->table[index]->second = key;
            }
        }
    }
    void print(){
        for(auto i=0; i<TABLE_SIZE; i++){
            if (this->table[i] != nullptr){
                std::cout << "I: " << i << "; " << this->table[i]->second << " " << this->table[i]->first << std::endl;
                if (this->table[i]->next != nullptr){
                    plist TMP = this->table[i]->next;
                    while (TMP){
                        std::cout << "I: " << i << "; " << TMP->second << " " << TMP->first << std::endl;
                        TMP = TMP->next;
                    }
                }
            }
        }
    }
};


int main() {
    HashTable ht;

    // Inserimento di alcune coppie chiave-valore
    ht.insert("Marco", 25);
    ht.insert("Alice", 30);
    ht.insert("Bob", 22);
    ht.insert("Charlie", 28);
    ht.print();
    

    return EXIT_SUCCESS;
}

