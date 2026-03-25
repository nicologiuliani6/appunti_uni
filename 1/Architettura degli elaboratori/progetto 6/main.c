#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"
#include "stack.h"


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Errore: argomenti mancanti.\n");
        exit(1);
    }

    char path_file_input[BUFFER_SIZE];

    if (strlen(argv[1]) >= BUFFER_SIZE) {
        printf("Errore: il percorso è troppo lungo.\n");
        exit(1);
    }

    strncpy(path_file_input, argv[1], BUFFER_SIZE - 1);
    path_file_input[BUFFER_SIZE - 1] = '\0';

    FILE *file_input = fopen(path_file_input, "r");

    if (file_input == NULL) {
        printf("Errore: impossibile aprire il file %s\n", path_file_input);
        exit(1);
    }

    printf("File %s aperto correttamente.\n", path_file_input);

    int lineCount = 0;
    char **file = create_char(file_input, &lineCount);
    fclose(file_input);

    // Pulisce il file
    file = cleanFile(file, &lineCount);
    // Stampa il contenuto ripulito
    //print_char(file, lineCount);
    // Stack della VM Hack
    VMStack stack;
    initialize(&stack);

    // Creazione istruzioni ASM
    char* file_output[BUFFER_SIZE];
    int riga_n = 0;  // Indice della riga
    int posizione = 0;
    char path_file_input_copy[BUFFER_SIZE];
    strcpy(path_file_input_copy, path_file_input);
    removeSubstring(path_file_input_copy, ".vm");
	removeSubstring(path_file_input_copy, "/");


    while (riga_n < lineCount) {
        if (strstr(file[riga_n], "(") == NULL) {
            // Allocazione dinamica per la stringa di output
           	file_output[posizione] = ASM(file[riga_n], &stack, path_file_input_copy);

			// Aggiungi un \0 alla fine della stringa se necessario
			size_t len = strlen(file_output[posizione]);
			file_output[posizione][len] = '\0';

            // Verifica che l'allocazione della stringa di output sia riuscita
            if (!file_output[posizione]) {
                printf("Errore nell'allocazione della stringa ASM per la riga %d.\n", riga_n);
                break; // Uscita dal ciclo in caso di errore
            }

            // Incremento della posizione
            posizione++;
        }
        riga_n++;
    }


    // Libera la memoria per il vecchio char
    free_char_array(file, lineCount);
    // Stampa le istruzioni in asm
    //printf("ISTRUZIONI ASM:\n");
    //print_char(file_output, posizione); //TODO RIMUOVERE

    // Nome del file di output
    char path_file_output[BUFFER_SIZE];
    const char *new_extension = ".asm";
    // Trova l'ultimo punto nella stringa
    char *dot_position = strrchr(path_file_input, '.');
    if (dot_position != NULL) {
        // Sostituisci il contenuto dopo l'ultimo punto
        size_t base_length = dot_position - path_file_input;
        strncpy(path_file_output, path_file_input, base_length);
        path_file_output[base_length] = '\0'; // Assicurati che la stringa sia terminata
    } else {
        // Nessun punto trovato, copia l'intera stringa
        strncpy(path_file_output, path_file_input, BUFFER_SIZE);
    }

    // Aggiungi la nuova estensione
    strncat(path_file_output, new_extension, BUFFER_SIZE - strlen(path_file_output) - 1);

    const char *filename_out = path_file_output;
    // Apri il file in modalità di scrittura
    FILE *file_out = fopen(filename_out, "w");
    if (file_out == NULL) {
        perror("Errore durante l'apertura del file");
        exit(1);
    }

    // Scrivi il contenuto del buffer nel file
    for (int i = 0; i < posizione && file_output[i] != NULL; i++) {
        fprintf(file_out, "%s\n", file_output[i]);  // Scrivi ogni stringa del buffer su una nuova riga
    }

    // Chiudi il file
    fclose(file_out);
    printf("Creato: %s\n",filename_out);

    // Liberazione della memoria dopo l'uso
    for (int i = 0; i < posizione; i++) {
        free(file_output[i]); // Liberiamo la memoria allocata da bin()
    }
    // Libera la memoria di file_output
    //free_char_array(file_output, posizione); //TODO DA SISTEMARE DA ERRORE POINTER FREE
    return 0;
}

