
#include <unordered_map>

template <typename T>
struct union_find {
private:
    std::unordered_map<T, T> parent;
public:
    // Crea un nuovo insieme contenente solo elem
    void makeset(const T& elem) {
        parent[elem] = elem; // Il rappresentante di se stesso
    }
    // Trova il rappresentante dell’insieme contenente elem
    T find(const T& elem) {
        if (parent[elem] == elem) {
            return elem;
        }
        return find(parent[elem]); // Senza path compression
    }
    // Unisce i due insiemi con rappresentanti elem1 e elem2
    void unite(const T& elem1, const T& elem2) {
        T rep1 = find(elem1);
        T rep2 = find(elem2);
        if (rep1 != rep2) {
            parent[rep2] = rep1; // rep1 diventa il rappresentante
        }
    }
};
