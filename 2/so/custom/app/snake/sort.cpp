#include "sort.hpp"

//SWAP TRA DUE ELEMENTI (USATO NEL BUBBLESORT)
void swap(int &a, int &b) {
    int temp = a;   //memorizziamo temporaneamente il valore di 'a'
    a = b;          //assegniamo a 'a' il valore di 'b'
    b = temp;       //assegniamo a 'b' il valore memorizzato di 'a'
}

//BUBBLESORT PER ORDINARE I PLAYER IN ORDINE DECRESCENTE PER I PUNTI
void bubbleSort(ptr_player arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; //variabile per verificare se è avvenuto uno scambio
        for (int j = 0; j < n - i - 1; ++j) {
            // confrontiamo i punti per ordinarli in ordine decrescente
            if (arr[j]->points < arr[j + 1]->points) { 
                ptr_player temp = arr[j]; //salviamo il puntatore del player corrente
                arr[j] = arr[j + 1];      //scambiamo il player corrente con il successivo
                arr[j + 1] = temp;        //posizioniamo il player salvato nella posizione successiva
                swapped = true;           //segniamo che è avvenuto uno scambio
            }
        }
        if (!swapped) break; //se non ci sono stati scambi, l'array è già ordinato
    }
}


