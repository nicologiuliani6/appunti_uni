#include "misc.h"

// Funzione per leggere un file e salvarlo in un array di stringhe
char **create_char(FILE *file, int *lineCount) {
    char **lines = NULL;
    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        // Rimuovi il carattere di newline '\n' se presente
        buffer[strcspn(buffer, "\n")] = 0;

        // Rimuovi anche il carattere di ritorno a capo '\r' (Windows line endings)
        if (buffer[strlen(buffer) - 1] == '\r') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        // Rimuovi gli spazi e le tabulazioni iniziali
        char *line = buffer;
        while (*line == ' ' || *line == '\t') line++;

        // Se la riga è vuota (solo spazi o tabulazioni), la saltiamo
        if (*line == '\0') continue;

        // Altrimenti, aggiungi la riga all'array
        lines = realloc(lines, (count + 1) * sizeof(char *));
        if (lines == NULL) {
            perror("Errore di allocazione memoria");
            exit(1);
        }

        lines[count] = strdup(line);
        if (lines[count] == NULL) {
            perror("Errore di duplicazione stringa");
            exit(1);
        }

        count++;
    }

    *lineCount = count;
    return lines;
}

// Funzione per stampare le righe di un array di stringhe
void print_char(char **file, int lineCount) {
    //printf("Contenuto del file ripulito:\n");
    for (int i = 0; i < lineCount; i++) {
        if (file[i] != NULL) {
            printf("%s\n", file[i]);
        }
    }
}
// Funzione per liberare la memoria dell'array di stringhe
void free_char_array(char **file, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        if (file[i] != NULL) {
            free(file[i]);  // Libera ogni stringa
            //printf("Liberata stringa %d\n", i);
        }
    }
    //free(file);  // Libera l'array principale
}
// Funzione per rimuovere caratteri di formattazione come '\r' e '\n'
void trimLine(char *line) {
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\r' || line[len - 1] == '\n')) {
        line[--len] = '\0';
    }
}

// Funzione per verificare se una stringa è vuota o contiene solo spazi
int isBlank(const char *line) {
    while (*line) {
        if (*line != ' ' && *line != '\t') {
            return 0; // Non è vuota
        }
        line++;
    }
    return 1; // È vuota
}

char **cleanFile(char **file, int *lineCount) {
    char **cleanedFile = NULL;
    int cleanedCount = 0;

    for (int i = 0; i < *lineCount; i++) {
        if (file[i] == NULL) {
            continue;
        }

        char *line = file[i];

        // Rimuove spazi iniziali e finali
        while (*line == ' ' || *line == '\t') line++;

        // Se la riga è vuota o inizia con un commento, ignora la riga
        if (*line == '\0' || strncmp(line, "//", 2) == 0) {
            free(file[i]); // Libera la riga vuota o commentata
            continue;
        }

        // Cerca il commento (se presente) e rimuovilo
        char *commentPos = strchr(line, '/');
        if (commentPos != NULL && commentPos[1] == '/') {
            *commentPos = '\0'; // Rimuove il commento dalla riga
        }

        // Rimuove eventuali caratteri '\r' (formattazione Windows)
        char *pos = strchr(file[i], '\r');
        if (pos != NULL) {
            *pos = '\0'; // Tronca la stringa prima del carattere '\r'
        }

        // Aggiunge la riga pulita al nuovo file
        cleanedFile = realloc(cleanedFile, (cleanedCount + 1) * sizeof(char *));
        if (cleanedFile == NULL) {
            perror("Errore di allocazione memoria");
            exit(1);
        }

        cleanedFile[cleanedCount] = strdup(file[i]);
        if (cleanedFile[cleanedCount] == NULL) {
            perror("Errore di duplicazione stringa");
            exit(1);
        }
        cleanedCount++;
        free(file[i]); // Libera la riga originale
    }

    free(file); // Libera l'array originale
    *lineCount = cleanedCount; // Aggiorna il numero di righe
    return cleanedFile;
}

void removeSubstring(char *str, const char *substr) {
    char *pos;
    while ((pos = strstr(str, substr)) != NULL) {
        // Sposta il resto della stringa per rimuovere la sottostringa
        memmove(pos, pos + strlen(substr), strlen(pos + strlen(substr)) + 1);
    }
}

