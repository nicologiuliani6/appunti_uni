#include <iostream>
#include <string>
#include <ctime> //per ilk random dei numeri primi

bool check_prime(const int num){
    for(auto i=2; i<num; i++){
        if(num%i==0) return false;
    }
    return true;
}
int get_prime(const int MAX){
    srand(time(0));
    int prime;
    for(auto i=0; i<MAX; i++){
        prime=rand()%100;
        if(check_prime(prime)) return prime;
    }
    return get_prime(MAX);
}

typedef struct list{
public:
    int first;
    std::string second;
    //costruttore
    list(const int first, const std::string second){
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
    static const int TABLE_SIZE = 100;
    plist table[TABLE_SIZE] = {nullptr};
    int prime[2]; //2 perche ci sono due funzioni di hash
    //funzioni hash
    int hash_first(const std::string& key){
        int HashValue = 0;
        for (char cr : key){
            HashValue=HashValue*(prime[0])+cr;
        }
        return HashValue % TABLE_SIZE;
    }
    int hash_second(const std::string& key){
        int HashValue = 0;
        for (char cr : key){
            HashValue=HashValue*(prime[1])+cr;
        }
        return 1 + (HashValue % (TABLE_SIZE-1));
    }
public:
    //costruttore
    HashTable(){
        prime[0] = get_prime(TABLE_SIZE);
        do{
            prime[1] = get_prime(TABLE_SIZE);
        }
        while(prime[0]==prime[1]);
        //printf("0: %d, 1: %d\n",prime[0],prime[1]);
    }
    void insert(const std::string& key, const int value, int i=0){
        int index = (hash_first(key)) % TABLE_SIZE;
        if (this->table[index] == nullptr){
            this->table[index] = new list(value, key);
        }
        else {
            while(this->table[index] != nullptr){
                i++;
                if (i>=TABLE_SIZE) {
                    std::cerr << "Overflow error" << std::endl;
                    exit(EXIT_FAILURE);
                }
                index = (hash_first(key) + i*hash_second(key)) % TABLE_SIZE;
            }
            this->table[index] = new list(value, key);
        }
    }
    int search(const std::string& key, int pair_number=0){
        for(int i=pair_number; i<TABLE_SIZE; i++){
            int index= (hash_first(key) + i*hash_second(key)) % TABLE_SIZE;
            if (this->table[index]!=nullptr && this->table[index]->second == key) return this->table[index]->first;
        }
        return -1;
    }
    void eliminate(const std::string& key, int pair_number=0){
        for(int i=pair_number; i<TABLE_SIZE; i++){
                int index= (hash_first(key) + i*hash_second(key)) % TABLE_SIZE;
                if (this->table[index]!=nullptr && this->table[index]->second == key) {
                    this->table[index] = nullptr;
                    return;
                }
            }
    }
    void print(){
        for(auto i=0; i<TABLE_SIZE; i++){
            if (this->table[i] != nullptr){
                std::cout << "I: " << i << "; " << this->table[i]->second << " " << this->table[i]->first << std::endl;
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
    ht.insert("David", 35);
    ht.insert("Eve", 40);
    ht.insert("Frank", 45);
    ht.insert("Grace", 50);
    ht.insert("Hannah", 55);
    ht.insert("Isaac", 60);
    ht.insert("Eve", 12);
    ht.print();
    std::cout << ht.search("Eve") << std::endl;
    

    return EXIT_SUCCESS;
}

