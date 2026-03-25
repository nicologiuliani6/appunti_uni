#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define TABLE_SIZE 10000

typedef struct Symbol {
    char label[50];
    int address;
    struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
    Symbol* table[TABLE_SIZE];
} SymbolTable;

// Funzioni della tabella dei simboli
SymbolTable* createSymbolTable();
void addSymbol(SymbolTable* symbolTable, const char* label, int address);
int symbolExists(SymbolTable* symbolTable, const char* label);
int getSymbolAddress(SymbolTable* symbolTable, const char* label);
void freeSymbolTable(SymbolTable* symbolTable);
int add_to_symbol_table(SymbolTable* symbolTable, char* line, int riga_n);

#endif // SYMBOL_TABLE_H
