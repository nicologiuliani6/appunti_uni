// Funzione Bubble Sort generica
template <typename T>
void bubbleSort(T arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j + 1] < arr[j]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Se non ci sono stati scambi, l'array è già ordinato
    }
}