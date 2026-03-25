#include <iostream>
#include <algorithm>

struct AVL {
private:
    int val;
    AVL* ltree;
    AVL* rtree;
    int bilanciamento;
public:
    AVL(int v) : val(v), ltree(nullptr), rtree(nullptr), bilanciamento(0) {}
private:
    int height() const {
        int hl = ltree ? ltree->height() : 0;
        int hr = rtree ? rtree->height() : 0;
        return 1 + std::max(hl, hr);
    }
    void update_bilanciamento() {
        int hl = ltree ? ltree->height() : 0;
        int hr = rtree ? rtree->height() : 0;
        bilanciamento = hl - hr;
    }
    AVL* rotateLeft() {
        AVL* newRoot = rtree;
        rtree = newRoot->ltree;
        newRoot->ltree = this;
        this->update_bilanciamento();
        newRoot->update_bilanciamento();
        return newRoot;
    }
    AVL* rotateRight() {
        AVL* newRoot = ltree;
        ltree = newRoot->rtree;
        newRoot->rtree = this;
        this->update_bilanciamento();
        newRoot->update_bilanciamento();
        return newRoot;
    }
    AVL* balance() {
        update_bilanciamento();

        if (bilanciamento > 1) {
            if (ltree && ltree->bilanciamento < 0)
                ltree = ltree->rotateLeft();
            return rotateRight();
        }

        if (bilanciamento < -1) {
            if (rtree && rtree->bilanciamento > 0)
                rtree = rtree->rotateRight();
            return rotateLeft();
        }

        return this;
    }
    AVL* minValueNode() {
        AVL* current = this;
        while (current->ltree)
            current = current->ltree;
        return current;
    }
public:
    AVL* insert(int newVal) {
        if (newVal <= val) {
            if (!ltree) ltree = new AVL(newVal);
            else ltree = ltree->insert(newVal);
        } else {
            if (!rtree) rtree = new AVL(newVal);
            else rtree = rtree->insert(newVal);
        }
        return balance();
    }
    AVL* deleteNode(int key) {
        if (key < val) {
            if (ltree) ltree = ltree->deleteNode(key);
        }
        else if (key > val) {
            if (rtree) rtree = rtree->deleteNode(key);
        }
        else {
            if (!ltree || !rtree) {
                AVL* tmp = ltree ? ltree : rtree;
                delete this;
                return tmp;
            }
            AVL* tmp = rtree->minValueNode();
            val = tmp->val;
            rtree = rtree->deleteNode(tmp->val);
        }
        return balance();
    }
    bool search(int x) const {
        if (x == val) return true;
        if (x < val) return ltree ? ltree->search(x) : false;
        return rtree ? rtree->search(x) : false;
    }
};



int main(){
    AVL* T = new AVL(10);

    return 0;
}