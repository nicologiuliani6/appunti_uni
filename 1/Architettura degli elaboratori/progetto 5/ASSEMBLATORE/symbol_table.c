#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

// Funzione hash per calcolare l'indice nella tabella
unsigned int hash(const char* label) {
    unsigned int hash = 0;
    while (*label) {
        hash = (hash << 5) + *label++;
    }
    return hash % TABLE_SIZE;
}

// Inizializza la tabella dei simboli
SymbolTable* createSymbolTable() {
    SymbolTable* symbolTable = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (symbolTable == NULL) {
        fprintf(stderr, "Errore di allocazione memoria per la tabella dei simboli\n");
        exit(1);
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbolTable->table[i] = NULL;
    }
    return symbolTable;
}
// Funzione che verifica se una etichetta esiste nella tabella dei simboli
int symbolExists(SymbolTable* symbolTable, const char* label) {
    unsigned int index = hash(label);
    Symbol* current = symbolTable->table[index];
    while (current) {
        if (strcmp(current->label, label) == 0) {
            return 1;  // Etichetta trovata
        }
        current = current->next;
    }
    return 0;  // Etichetta non trovata
}
// Aggiunge una nuova etichetta alla tabella
void addSymbol(SymbolTable* symbolTable, const char* label, int address) {
    unsigned int index = hash(label);
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    if (newSymbol == NULL) {
        fprintf(stderr, "Errore di allocazione memoria per la nuova etichetta\n");
        exit(1);
    }
    
    // Verifica che la dimensione di label sia sufficiente
    if (strlen(label) >= sizeof(newSymbol->label)) {
        fprintf(stderr, "Nome etichetta troppo lungo: %s\n", label);
        exit(1);
    }

    strcpy(newSymbol->label, label);
    newSymbol->address = address;
    newSymbol->next = symbolTable->table[index];
    symbolTable->table[index] = newSymbol;
    //printf("%s\n",label);
    if(symbolExists(symbolTable, label)==0){
        printf("ERRORE: etichetta non allocata\n");
    }
    else{
        //printf("Etichetta %s allocata correttamente con valore %d\n",label,getSymbolAddress(symbolTable, label));
    }
}


// Cerca un'etichetta nella tabella e restituisce l'indirizzo
int getSymbolAddress(SymbolTable* symbolTable, const char* label) {
    unsigned int index = hash(label);
    Symbol* current = symbolTable->table[index];
    while (current) {
        if (current == NULL) {
            printf("current è NULL\n");
        }
        if (label == NULL) {
            printf("label è NULL\n");
        }

        if (strcmp(current->label, label) == 0) {
            return current->address;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("current è NULL\n");
    }

    if (current->label[0] == '\0') {    
        printf("current->label è NULL\n");
    }
    return -1; // Etichetta non trovata 
}

// Libera la memoria della tabella dei simboli
void freeSymbolTable(SymbolTable* symbolTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol* current = symbolTable->table[i];
        while (current) {
            Symbol* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(symbolTable);
}

// Funzione per verificare se una stringa è una etichetta valida
int add_to_symbol_table(SymbolTable* symbolTable, char* line, int riga_n) {
    //printf("%d\n",riga_n);
    // Stampa il contenuto della linea originale
    //printf("Linea originale: %s\n", line);
    //printf("%s\n",line);
    int len = strlen(line);



    // Rimuovi il ritorno a capo se presente
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';  // Rimuove il ritorno a capo
        len--;  // Aggiorna la lunghezza dopo aver rimosso il ritorno a capo
    }


    // Rimuovi la parentesi di apertura se presente
    if ((line[0] == '(' && len > 0 && line[len - 1] == ')') || (line[len - 2] == ')')) {    
        line[len-1] = '\0';  // Rimuove la parentesi di chiusura
        // Rimuove la parentesi di apertura
       line = line +1;  // sposta tutto a sinistra
    // Stampa l'etichetta dopo la rimozione delle parentesi
    //printf("Etichetta: %s\n", line);

    // Etichette predefinite
    const char* predefined_labels[] = {
        "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15",
        "SP", "LCL", "ARG", "THIS", "THAT", "SCREEN", "KBD"
    };

    int trovata=0;
    for (int i = 0; i < 22; i++) {
        // Controllo se la stringa in predefined_labels[i] è valida
        if (predefined_labels[i] == NULL) {
            printf("ERRORE: etichetta non valida nell'array\n");
            continue;
        }

        // Controllo se la stringa 'line' è valida
        if (line == NULL) {
            printf("ERRORE: la variabile 'line' è NULL\n");
            break;
        }

        if (strcmp(line, predefined_labels[i]) == 0) {
            printf("ERRORE: non puoi sovrascrivere una etichetta predefinita '%s'\n", line);
            trovata = 1;
            break;
        }
    }

    // Aggiungi l'etichetta alla tabella dei simboli se non è predefinita
    if (trovata == 0) {
        addSymbol(symbolTable, line, riga_n);
        //printf("Etichetta '%s' aggiunta con il valore %d\n", line, riga_n);
        return 1;
    }
    }
    else{
        //printf("etichetta non aggiunta: %s\n",line);
    }
    return 0;

}



