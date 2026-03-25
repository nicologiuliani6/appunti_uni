#include <vector>
#include <list>

template <typename K, typename V> //tipo key & tipo data
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<K, V>>> table;

    int hash(const K& key) const { //funzione/i di hashing
        return std::hash<K>{}(key) % TABLE_SIZE;
    }

public:
    //costruttore
    HashTable() : table(TABLE_SIZE) {} //massimo TABLE_SIZE liste
    //funzioni basiche
    void insert(const K& key, const V& value) {
        int index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }
    bool remove(const K& key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true; // rimozione avvenuta
            }
        }
        return false; // chiave non trovata
    }
    bool search(const K& key, V& value) const {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }
};


int hash1(const int key){
    //mcd(ABLE_SIZE, key) 
    return key % TABLE_SIZE; 
}
// funzione hash con probing: i è l'indice di tentativi (0, 1, 2, ...)
int hash(const int key, int i){
    //mcd(TABLE_SIZE, h1(k)+3i)
    return (hash1(key) + 3 * i) % TABLE_SIZE;
}