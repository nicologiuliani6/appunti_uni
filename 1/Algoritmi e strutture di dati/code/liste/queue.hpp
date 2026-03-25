template <typename T>
struct queue {
    struct node {
        T value;
        node* next;
        node(T v) : value(v), next(nullptr) {}
    };

    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;

    void enqueue(T v) {
        node* newNode = new node(v);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (!head) return T(); // oppure throw eccezione
        node* tmp = head;
        T ret = tmp->value;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
        size--;
        return ret;
    }

    bool empty() const {
        return size == 0;
    }
};
