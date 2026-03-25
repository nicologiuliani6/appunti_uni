#include "classifica.hpp"
#include "sort.hpp"

//ottiene i dati dell classifica attuale
char* get_leaderboard() {
    static char buffer[BUFFER_SIZE]; // max 1023 caratteri + '\0'
    std::ifstream inputFile("leaderboard.txt"); //apertuta del file .txt

    //errore se la classifica non esiste
    if (!inputFile.is_open()) {
        std::cerr << "ERRORE: file classifica non trovato" << std::endl;
        exit(1);
    }
    //copiamo il contenuto del file dentro la variabile
    int i = 0;
    char ch;
    while (inputFile.get(ch) && i < BUFFER_SIZE-1) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0'; // terminatore stringa
    //chiudiamo il file
    inputFile.close();
    //ritorniamo la stringa
    return buffer;
}

//CONVERTIAMO UNA STRINGA IN UNSIGNED INT
bool str_to_uint(const char* str, unsigned int& result) {
    result = 0;
    if (!str || *str == '\0') return false; //controlliamo che la stringa sia valida

    const unsigned int UINT_MAX_CUSTOM = 4294967295U; //valore massimo rappresentabile da unsigned int

    while (*str == ' ') str++; //saltiamo eventuali spazi iniziali

    while (*str) {
        if (*str < '0' || *str > '9') return false; //se troviamo un carattere non numerico, ritorniamo errore
        unsigned int digit = *str - '0'; //convertiamo il carattere in cifra

        //controllo per evitare overflow
        if (result > (UINT_MAX_CUSTOM - digit) / 10) return false;

        result = result * 10 + digit; //aggiorniamo il valore finale
        str++; //avanziamo al prossimo carattere
    }

    return true; //conversione riuscita
}
//CONVERTIAMO DA UNA STRINGA ALLA STRUTTURA COLLEGATA PLAYER
ptr_player* char_to_player_struct(const char* leaderboard, int& length) {
    //creiamo un array di player
    ptr_player* players = new ptr_player[BUFFER_SIZE];
    //init della struttura
    for (int i = 0; i < BUFFER_SIZE; ++i) players[i] = nullptr;
    //lunghezza della struttura a 0
    length = 0;
    //puntiamo alla stringa data in input
    const char* ptr = leaderboard;

    // saltiamo le prime due righe (ovvero quelle con '#')
    int skipped = 0;
    while (*ptr && skipped < 2) {
        //usciamo quando troviamo 2 '\0'
        while (*ptr && *ptr != '\n') ptr++;
        if (*ptr == '\n') {
            ptr++;
            skipped++;
        }
    }

    // Ora `ptr` punta all'inizio della lista vera dei giocatori
    while (*ptr) {
        //controllo che non ci sia una righa vuota
        if (*ptr == '\n') {
            ptr++;
            continue;
        }

        char row[BUFFER_SIZE];
        int i = 0;
        while (*ptr && *ptr != '\n' && i < BUFFER_SIZE - 1) {
            //copiamo dentro row il contenuto
            row[i++] = *ptr++;
        }
        row[i] = '\0';

        // Parsing manuale dei dati (si semplifica molto se si utilizza 'sscanf()')
        char pos[16] = {0}, name[BUFFER_SIZE] = {0};
        unsigned int points = 0;

        //puntiamo ai dati
        const char* rptr = row;

        // Estrai position
        const char* pos_end = strchr(rptr, ','); //punta alla prima virgola
        if (!pos_end) continue; // se non c'è una virgola, la riga non è valida -> salta tutto
        int pos_len = pos_end - rptr;
        strncpy(pos, rptr, pos_len); //copiamo la posizione
        pos[pos_len] = '\0';
        rptr = pos_end + 1; //andiamo oltre la virgola

        // Estrai name
        const char* name_end = strchr(rptr, ','); //punta alla seconda virgola
        if (!name_end) continue; // se non c'è una virgola, la riga non è valida -> salta tutto
        int name_len = name_end - rptr;
        strncpy(name, rptr, name_len); //copiamo il nome
        name[name_len] = '\0';
        rptr = name_end + 1; //andiamo oltre la virgola

        // Estrai points
        if (!str_to_uint(rptr, points)) { //copiamo dentro int points il valore convertito dalla stringa
            continue; // errore nella conversione -> saltiamo la riga
        }
        
        //allochiamo dinamicamente un nuovo player e lo aggiungiamo all'array
        players[length++] = new player(name, points);

        //se siamo su una nuova riga, avanziamo il puntatore
        if (*ptr == '\n') ptr++;
    }

    //ritorniamo il puntatore all'array di player
    return players;
}

//SCRITTURA SU FILE .TXT DELLA CLASSIFICA
void write_leaderboard(const ptr_player player[], int length) {
    //apertura file di output .txt
    std::ofstream outputFile_leaderboard("leaderboard.txt");
    //errore sul file
    if (!outputFile_leaderboard.is_open()) {
        std::cerr << "Errore nell'apertura del file leaderboard.txt\n";
        return;
    }
    //creami legenda
    outputFile_leaderboard << "# Player Leaderboard\n";
    outputFile_leaderboard << "# Format: Position | Player | Points\n";

    //scriviamo i dati seguendo la legenda
    for (int i = 0; i < length; i++) {
        outputFile_leaderboard << 
        (i + 1) //posizione
        << "," 
        << player[i]->name  //nome
        << "," 
        << player[i]->points //punteggio
        << "\n"; //terminatore riga

        if (DEBUG) {
            std::cout << (i + 1) << "," << player[i]->name << "," << player[i]->points << "\n";
        }
    }
    //chiudiamo il file
    outputFile_leaderboard.close();
}

// AGGIUNGI UN NUOVO PLAYER E RISCRIVI LA CLASSIFICA VIA FILE .TXT
void add_player_to_leaderboard_file(const char name[], const unsigned int points) {
    //copiamo come stringa la leaderboard
    char* leaderboard = get_leaderboard();
    //impossibile ottenere leaderboard via stringa
    if (!leaderboard) {
        std::cerr << "Errore: impossibile ottenere il leaderboard.\n";
        exit(1);
    }

    if (DEBUG) {
        std::cout << "Leaderboard:\n" << leaderboard << std::endl;
    }
    //init della struttura array
    ptr_player P[BUFFER_SIZE] = {nullptr};
    //lunghezza della struttura pari ad 0
    int length = 0;

    ptr_player* result = char_to_player_struct(leaderboard, length);
    //errore se il parsing non è possibile
    if (!result) {
        std::cerr << "Errore: parsing del leaderboard fallito.\n";
        exit(1);
    }

    if (DEBUG) {
        std::cout << "LENGTH: " << length << std::endl;
    }

    for (int i = 0; i < length; ++i) {
        P[i] = result[i];
        if (DEBUG) {
            std::cout << "DEBUG - PLAYER[" << i << "]: " << P[i]->name << ", POINTS: " << P[i]->points << std::endl;
        }
    }

    //aggiungiamo un nuovo player
    P[length++] = new player(name, points);

    //mettiamo in ordine i player
    bubbleSort(P, length);
    //scriviamo su file il testo aggiornato con il nuovo player
    write_leaderboard(P, length);

    //pulizia memoria
    for (int i = 0; i < length; ++i) {
        delete P[i];
    }
    delete[] result;
}
