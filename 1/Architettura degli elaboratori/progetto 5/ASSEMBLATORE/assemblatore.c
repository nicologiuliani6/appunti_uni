#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

#define BUFFER_SIZE 102400
// Dichiarazione della variabile globale
int nextAvailableAddress = 16;

// Funzione per leggere il file e creare un buffer di righe
char **create_char(FILE *file_input) {
    char buffer[BUFFER_SIZE];
    char **file = malloc(BUFFER_SIZE * sizeof(char *));
    if (!file) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }

    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, file_input) != NULL) {
        file[i] = malloc(strlen(buffer) + 1);
        if (!file[i]) {
            printf("Errore di allocazione memoria.\n");
            exit(1);
        }
        strcpy(file[i], buffer);
        i++;
        if (feof(file_input)) break;
    }

    file[i] = NULL; // Indica la fine del buffer con un valore NULL
    return file;
}

// Funzione per stampare il contenuto del buffer
void print_char(char **file) {
    for (int i = 0; file[i] != NULL; i++) {
        printf("%s", file[i]); 
    }
}
//FUNZIONE PER STAMPARE LE ISTRUZIONI IN CODIFICA BINARIA
void print_bin(char **file_output, int i) {
    // Stampa l'output binario
    printf("\nIstruzione binaria: \n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", file_output[j]);
    }
}
// Funzione per rimuovere gli accapo e commenti "//"
void clean(char **file) {
    int i = 0, j = 0; // i per scorrere, j per memorizzare le righe senza commento
    while (file[i] != NULL) {
        // Cerca la posizione del commento (//)
        char *comment_pos = strstr(file[i], "//");

        // Se c'è un commento, tronca la riga a quel punto
        if (comment_pos != NULL) {
            *comment_pos = '\0';
        }

        // Rimuovi tutti gli spazi bianchi all'interno della riga
        int k = 0;
        char temp[strlen(file[i]) + 1]; // Array temporaneo per la nuova riga senza spazi
        for (int l = 0; file[i][l] != '\0'; l++) {
            if (file[i][l] != ' ' && file[i][l] != '\t' && file[i][l] != '\r' && file[i][l] != '\n') {
                temp[k++] = file[i][l]; // Aggiungi solo i caratteri non bianchi
            }
        }
        temp[k] = '\0'; // Termina la nuova stringa

        // Copia la riga modificata (senza commenti e spazi) di nuovo in file[i]
        strcpy(file[i], temp);

        // Rimuovi righe vuote o solo spazi bianchi
        if (strlen(file[i]) > 0) {
            file[j] = file[i]; // Mantieni la riga senza commento e senza spazi
            j++;
        }

        i++;
    }

    // Aggiungi un NULL alla fine per segnare la fine dell'array
    file[j] = NULL;
}

//FUNZIONE CHE CONVERTE DA DEC A BIN senza codifiche strane
char* decimale_a_binario(int numero) {
    static char binario[17];  // 16 bit + 1 per il terminatore '\0'
    int i;

    // Imposta tutti i bit a '0' inizialmente
    for (i = 0; i < 16; i++) {
        binario[i] = '0';
    }
    binario[16] = '\0';  // Terminatore di stringa

    // Converte il numero in binario
    for (i = 15; i >= 0; i--) {
        if (numero & 1) {
            binario[i] = '1';
        }
        numero >>= 1;  // Sposta il numero di un bit a destra
    }

    return binario;
}
//PER CONTROLLARE SE è UNA LETTERA
int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
//CALCOLO ISTRUZIONI IN BINARIO
char* bin_instrc(char *line, SymbolTable* symbolTable) {
    char *binary = malloc(17 * sizeof(char)); // 16 bit + '\0'
    if (binary == NULL) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    memset(binary, '\0', 17); // Azzeramento del buffer
    
    // Istruzione di tipo A (indirizzo assoluto)
    if (line[0] == '@') {

         //istruzioni etichetta
        char *src = line + 1;  // Skip the '@'
        //printf("%s\n",src);
        char *src_temp;
        src_temp=src;
        //size_t len = strlen(src_temp);
        //printf("%s\n",src_temp);
 
        //printf("%s\n",src_temp);
        if (symbolExists(symbolTable, src_temp)==1) {
            //printf("L'etichetta '%s' esiste già nella tabella.\n", src_temp);
            int address = getSymbolAddress(symbolTable, src_temp); // Converte il numero dopo '@' in int
            strcpy(binary, decimale_a_binario(address)); // Converti in binario (15 bit)
            //printf("valore etichetta di %s calcolato in binario: %d!\n",src_temp,getSymbolAddress(symbolTable, src_temp));
        }

        else if (symbolExists(symbolTable, src_temp) == 0) {
            // Controlla se il simbolo inizia con una lettera
            if (is_letter(src_temp[0])) {
                //printf("Calcolo etichetta nuova (%s) con nextAvailableAddress: %d\n",src_temp,nextAvailableAddress);
                // È un'etichetta o una variabile valida
                int address = nextAvailableAddress; // Assegna un nuovo indirizzo RAM
                //printf("alloco etichetta %s al indirizzo automatico %d\n",src_temp,address);
                addSymbol(symbolTable, src_temp, address); // Aggiungi il simbolo alla tabella
                nextAvailableAddress++; // Incrementa il contatore RAM
                strcpy(binary, decimale_a_binario(address)); // Converte l'indirizzo in binario
            }
        }
        //istruzione @
        if(strchr(src_temp, 'R')==NULL && (src_temp[0] == '0' ||src_temp[0] == '1' || src_temp[0] == '2' || src_temp[0] == '3' || src_temp[0] == '4' || src_temp[0] == '5' || src_temp[0] == '6' || src_temp[0] == '7' || src_temp[0] == '8' || src_temp[0] == '9')){
            
            int address = atoi(src_temp); // Converte il numero dopo '@' in int
            strcpy(binary, decimale_a_binario(address)); // Converti in binario (15 bit)
            //printf("valore @ calcolato in binario!\n");
    }
    }
    // Istruzione di tipo C (operazioni di assegnazione o calcolo)
    else {
        //CALCOLO primi 3 bit
        binary[0] = '1'; // Bit di tipo C
        binary[1] = '1';
        binary[2] = '1';
        //calcolo a
        binary[3] = '0';
        //resto dei bit
        binary[4] = '0';
        binary[5] = '0';
        binary[6] = '0';
        binary[7] = '0';
        binary[8] = '0';
        binary[9] = '0';
        binary[10] = '0';
        binary[11] = '0';
        binary[12] = '0';
        binary[13] = '0';
        binary[14] = '0';
        binary[15] = '0';
        //CALCOLO jump
        if (strchr(line,';')!=NULL){
            if (strstr(line,"JGT")!=NULL){
                binary[13] = '0';
                binary[14] = '0';
                binary[15] = '1';
            }
            else if (strstr(line,"JEQ")!=NULL){
                binary[13] = '0';
                binary[14] = '1';
                binary[15] = '0';
            }
            else if (strstr(line,"JGE")!=NULL){
                binary[13] = '0';
                binary[14] = '1';
                binary[15] = '1';
            }
            else if (strstr(line,"JLT")!=NULL){
                binary[13] = '1';
                binary[14] = '0';
                binary[15] = '0';
            }
            else if (strstr(line,"JNE")!=NULL){
                binary[13] = '1';
                binary[14] = '0';
                binary[15] = '1';
            }
            else if (strstr(line,"JLE")!=NULL){
                binary[13] = '1';
                binary[14] = '1';
                binary[15] = '0';
            }
            else if (strstr(line,"JMP")!=NULL){
                binary[13] = '1';
                binary[14] = '1';
                binary[15] = '1';
                char *pos1;
                // Trova la posizione del primo ';'
                pos1 = strchr(line, ';');

                if (pos1 != NULL) {
                    // Modifica 'pos' per puntare alla parte prima del ';'
                    *pos1 = '\0';
                }
                 if (strchr(pos1, 'M') != NULL &&(strchr(line, ';') == NULL || (strchr(line, ';') != NULL && strchr(line, '=') != NULL))) {
                //printf("TROVATO M\n");
                // Scorri ogni carattere della stringa
                binary[3] = '1';
                 }
            }
            else{
                printf("ERRORE: jump non supportato\n");
                strcpy(binary,"ERRORE");
            }
        }

        //CALCOLO dest
        //printf("%s\n",line);
        if(strstr(line,"AMD=")!=NULL){
            binary[10] = '1';
            binary[11] = '1';
            binary[12] = '1';
        }
        else if(strstr(line,"MD=")!=NULL){
            binary[10] = '0';
            binary[11] = '1';
            binary[12] = '1';
        }
        else if(strstr(line,"AM=")!=NULL){
            binary[10] = '1';
            binary[11] = '0';
            binary[12] = '1';
        }
        else if(strstr(line,"AD=")!=NULL){
            binary[10] = '1';
            binary[11] = '1';
            binary[12] = '0';
        }
        else if (strstr(line,"A=")!=NULL){
            binary[10] = '1';
            binary[11] = '0';
            binary[12] = '0';
        }
        else if(strstr(line,"D=")!=NULL){
            binary[10] = '0';
            binary[11] = '1';
            binary[12] = '0';
        }
        else if(strstr(line,"M=")!=NULL){
            binary[10] = '0';
            binary[11] = '0';
            binary[12] = '1';
        }
        //FINE dest

        //CALCOLO comp
        char *pos = NULL;
        char *tmp = NULL;

        
        if (strchr(line, '=') != NULL) {
            //se cè = prendi in tmp il testo dopo =
            pos = strchr(line, '=');
            tmp = pos + 1; //tmp =+1
        }
        else{
            //se non ce = tieni il testo cosi come è e mettilo in tmp
            pos=line;
            tmp=pos;
        }  
        if(strchr(tmp, ';') != NULL){
            // se cè ;
            pos = strchr(tmp, ';');
            *pos = '\0';
            tmp = line;
        }

        if (pos != NULL && tmp != NULL) {
            if (strchr(pos, 'M') != NULL && strstr(line, "JMP") == NULL &&
                (strchr(line, ';') == NULL || strchr(line, '=') != NULL)) {
                binary[3] = '1';
                for (int i = 0; pos[i] != '\0'; i++) {
                    if (pos[i] == 'M') {
                        pos[i] = 'A';
                    }
                }
            }
        }
        if (pos != NULL) {
            if (strstr(tmp,"!D")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '0';
                binary[9] = '1';
            }
            else if (strstr(tmp,"!A")){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '0';
                binary[9] = '1';
            }
            
            else if (strstr(tmp,"D+1")){
                binary[4] = '0';
                binary[5] = '1';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"A+1")){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"D-1")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '0';
            }
            else if (strstr(tmp,"A-1")){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '0';
            }
            else if (strstr(tmp,"D+A")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '0';
            }
            else if (strstr(tmp,"D-A")){
                binary[4] = '0';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"A-D")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '0';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"D&A")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '0';
                binary[9] = '0';
            }
            else if (strstr(tmp,"D|A")){
                binary[4] = '0';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '1';
                binary[8] = '0';
                binary[9] = '1';
            }
            else if(tmp[0]=='0'){
                binary[4] = '1';
                binary[5] = '0';
                binary[6] = '1';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '0';
            }
            else if(tmp[0]=='1'){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"-1")!=NULL){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '1';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '0';
            }
            else if (strstr(tmp,"-D")){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (strstr(tmp,"-A")){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '1';
                binary[9] = '1';
            }
            else if (tmp[0]=='D'){
                binary[4] = '0';
                binary[5] = '0';
                binary[6] = '1';
                binary[7] = '1';
                binary[8] = '0';
                binary[9] = '0';
            }
            else if (tmp[0]=='A'){
                binary[4] = '1';
                binary[5] = '1';
                binary[6] = '0';
                binary[7] = '0';
                binary[8] = '0';
                binary[9] = '0';
            }
            //else printf("ERRORE COMPILAZIONE: comp\n");
        } 
        else {
            printf("ERRORE COMPILAZIONE: pos o tmp NULL\n");
        }
    }
    return binary;
}


int main(int argc, char** argv){
    if (argc <= 1) {
        printf("Errore: argomenti mancanti.\n");
        exit(1);
    }

    char path_file_input[BUFFER_SIZE];

    // Copia il primo argomento in path_file_input
    if (strlen(argv[1]) >= BUFFER_SIZE) {
        printf("Errore: il percorso è troppo lungo.\n");
        exit(1);
    }

    strncpy(path_file_input, argv[1], BUFFER_SIZE - 1);
    path_file_input[BUFFER_SIZE - 1] = '\0'; // Garantire che la stringa sia terminata da null

    FILE *file_input = fopen(path_file_input, "r");

    // Controllo se il file esiste o è accessibile
    if (file_input == NULL) {
        printf("Errore: impossibile aprire il file %s\n", path_file_input);
        exit(1);
    }
    else{
        printf("File %s aperto correttamente.\n", path_file_input);
        char **file = create_char(file_input); //COPIATURA del file dato in path in un char
        fclose(file_input); // Chiude il file dopo la lettura
        clean(file); //RIMOZIONE COMMENTI E A CAPO

        //CREATE SYMBOL TABLE
        SymbolTable* symbolTable = createSymbolTable();

        // Aggiungi registri R0–R15
        for (int i = 0; i <= 15; i++) {
            char label[5];
            sprintf(label, "R%d", i);
            addSymbol(symbolTable, label, i);
        }
        // Aggiungi puntatori predefiniti
        addSymbol(symbolTable, "SP", 0);     // Stack Pointer
        addSymbol(symbolTable, "LCL", 1);   // Local
        addSymbol(symbolTable, "ARG", 2);   // Argument
        addSymbol(symbolTable, "THIS", 3);  // This
        addSymbol(symbolTable, "THAT", 4);  // That
        // Aggiungi indirizzi dello schermo e tastiera
        addSymbol(symbolTable, "SCREEN", 16384);  // Indirizzo base dello schermo
        addSymbol(symbolTable, "KBD", 24576);     // Indirizzo base della tastiera
        
        //LOAD CUSTOM ETICHETTE TO SYMBOL TABLE
        int linea=0; //CAMBIARE SE ETICHETTA PARTE DA 1
       for (int riga_n = 0; file[riga_n] != NULL; riga_n++) {
        // Se la riga contiene un punto, rimuovilo
        char *str = file[riga_n];  // Puntatore alla stringa originale
        char result[strlen(str) + 1];  // Stringa temporanea per il risultato
        char *dest = result;  // Puntatore alla destinazione temporanea

        while (*str) {
            if (*str != '.') {     // Se il carattere non è un punto
                *dest = *str;      // Copia nella destinazione
                dest++;            // Sposta il puntatore della destinazione
            }
            else{
                //printf("eliminazione punto\n");
            }
            str++;  // Sposta il puntatore della stringa originale
        }
        *dest = '\0';  // Termina la stringa con il carattere nullo

        // Aggiorna file[riga_n] con il risultato modificato
        strcpy(file[riga_n], result);
        //printf("%s\n",file);
        // Aggiungi il simbolo alla tabella
        if (add_to_symbol_table(symbolTable, file[riga_n], linea) != 1) {
            //printf("%s\n",file[riga_n]);
            linea++;
        }
    }

        //CREAZIONE ISTRUZIONI IN BINARIO
        char *file_output[BUFFER_SIZE]; // Array per le righe binarie
        int riga_n = 0; // Indice della riga
        int posizione = 0;
        while (file[riga_n] != NULL) {
            // Salva l'istruzione binaria nella riga corrispondente
            if(strstr(file[riga_n],"(")==NULL){
                file_output[posizione] = bin_instrc(file[riga_n], symbolTable); // bin() restituisce una stringa dinamica
                //printf("%s\n",file_output[riga_n]);
                posizione++;
            }
            riga_n++;
        }

        //print_bin(file_output, posizione); // Stampa le istruzioni in binario

        // Nome del file di output
        char path_file_output[BUFFER_SIZE];
        const char *new_extension = ".hack";
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
    }
}
