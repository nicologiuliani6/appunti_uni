#include <iostream>
#include <ctime>
#include <ncurses.h>
#include "config.hpp"
#include "griglia.hpp"
#include "levels.hpp"
#include "snake.hpp"
#include "points.hpp"
#include "gamemanager.hpp"
#include "menu.hpp"
#include "classifica.hpp"


class MainMenu {
    private:
        Menu* menu;
        
    public:
    MainMenu() {
        menu = new Menu(8, 35, 0, 0);
    }
    
    int showMenu() {
        menu->inizializza();
        menu->input_tastiera();

        const char* scelte[] = {"Nuova Partita", "Classifica", "Esci"};
        int num_scelte = 3;
        int evidenzia = 0;
        int scelta = 0;
        
        // stampa il titolo
        int xm, ym;
        getmaxyx(stdscr, ym, xm);
        mvprintw(ym/2 - 6, xm/2 - 10, "=== SNAKE ===");
        refresh();
        
        while(scelta != 10) { // 10 è il codice per il tasto Enter
            // pulizia selezione precedente
            for (int i = 0; i < num_scelte; i++) {
                mvwprintw(menu->getWindow(), i + 2, 9, "                    ");
            }
            
            // mostra le opzioni del menu ed evidenza la scritta
            for (int i = 0; i < num_scelte; i++) {
                if (i == evidenzia) {
                    wattron(menu->getWindow(), A_REVERSE);
                    mvwprintw(menu->getWindow(), i + 2, 9, "%s", scelte[i]);
                    wattroff(menu->getWindow(), A_REVERSE);
                } else {
                    mvwprintw(menu->getWindow(), i + 2, 9, "%s", scelte[i]);
                }
            }
            
            wrefresh(menu->getWindow());
            scelta = wgetch(menu->getWindow());

            // prende in input le freccette ed evidenzia la scritta scelta
            if (scelta == KEY_UP) {
                evidenzia--;
                if (evidenzia < 0) evidenzia = num_scelte - 1; // se si va troppo in alto, viene evidenziato l'ultimo elemento
            } else if (scelta == KEY_DOWN) {
                evidenzia++;
                if (evidenzia > num_scelte - 1) evidenzia = 0; // se si va troppo in basso, viene evidenziato il primo elemento
            }
        }
        
        return evidenzia;
    }
    
    void showLeaderboard() {
        clear();
        
        // lettura leaderboard
        try {
            char* leaderboard_data = get_leaderboard();
            
            int xm, ym;
            getmaxyx(stdscr, ym, xm);
            
            mvprintw(2, xm/2 - 10, "=== CLASSIFICA ===");
            
            // parse e mostriamo la leaderboard
            const char* ptr = leaderboard_data;
            int line = 4;
            
            // saltiamo le prime 2 righe di legenda
            int skipped = 0;
            while (*ptr && skipped < 2) {
                while (*ptr && *ptr != '\n') ptr++;
                if (*ptr == '\n') {
                    ptr++;
                    skipped++;
                }
            }
            
            // mostriamo la leaderboard
            while (*ptr && line < ym - 3) {
                if (*ptr == '\n') {
                    ptr++;
                    continue;
                }
                
                char row[500];
                int i = 0;
                while (*ptr && *ptr != '\n' && i < 499) {
                    row[i++] = *ptr++;
                }
                row[i] = '\0';
                
                // Parsing del position, name, points
                char pos[16] = {0}, name[100] = {0}, points_str[32] = {0};
                
                const char* rptr = row;
                const char* comma1 = strchr(rptr, ',');
                if (!comma1) continue;
                
                strncpy(pos, rptr, comma1 - rptr);
                pos[comma1 - rptr] = '\0';
                
                rptr = comma1 + 1;
                const char* comma2 = strchr(rptr, ',');
                if (!comma2) continue;
                
                strncpy(name, rptr, comma2 - rptr);
                name[comma2 - rptr] = '\0';
                
                strcpy(points_str, comma2 + 1);
                
                mvprintw(line, 5, "%s. %s - %s punti", pos, name, points_str);
                line++;
                
                if (*ptr == '\n') ptr++;
            }
            
            if (line == 4) {
                mvprintw(6, xm/2 - 15, "Nessun punteggio registrato");
            }
            
        } catch (...) {
            int xm, ym;
            getmaxyx(stdscr, ym, xm);
            mvprintw(ym/2, xm/2 - 15, "Errore nel caricamento classifica");
        }
        
        mvprintw(LINES - 2, 2, "Premi un tasto per tornare al menu...");
        refresh();
        getch();
    }
};

// otteniamo il nome di un giocatore per la leaberboard
void getPlayerName(char* buffer, int buffer_size) {
    clear();
    
    int xm, ym;
    getmaxyx(stdscr, ym, xm);
    
    mvprintw(ym/2 - 2, xm/2 - 15, "Inserisci il tuo nome:");
    mvprintw(ym/2, xm/2 - 10, "Nome: ");
    refresh();
    
    echo(); // Enable character echoing
    curs_set(1); // Show cursor
    
    // Read string input with limit to buffer_size-1 chars
    wgetnstr(stdscr, buffer, buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; // null terminate
    
    noecho(); // Disable character echoing
    curs_set(0); // Hide cursor
}

extern "C" int game_main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    bool running = true;
    
    while (running) {
        clear();
        
        MainMenu mainMenu;
        int choice = mainMenu.showMenu();
        
        switch (choice) {
            case 0: { // Nuova Partita
                try {
                    endwin(); // End current ncurses session
                    
                    GameManager game; //attiviamo il gestore del gioco
                    //runniamo il gioco e alla fine torniamo il punteggio
                    int finalScore = game.run(); // Get the final score from the game
                    
                    // alla fine del gioco chiediamo il nome del giocatore se il punteggio e' positivo
                    initscr(); // Restart ncurses
                    noecho();
                    curs_set(0);
                    keypad(stdscr, TRUE);
                    
                    // Only ask for name if player scored points
                    if (finalScore > 0) {
                        char playerName[100] = {0};
                        getPlayerName(playerName, sizeof(playerName));
                        
                        if (playerName[0] != '\0') {
                            try {
                                add_player_to_leaderboard_file(playerName, finalScore);
                                
                                clear();
                                int xm, ym;
                                getmaxyx(stdscr, ym, xm);
                                mvprintw(ym/2, xm/2 - 15, "Punteggio salvato!");
                                mvprintw(ym/2 + 1, xm/2 - 20, "Punteggio finale: %d punti", finalScore);
                                mvprintw(ym/2 + 2, xm/2 - 15, "Premi un tasto per continuare...");
                                refresh();
                                getch();
                            } catch (...) {
                                clear();
                                int xm, ym;
                                getmaxyx(stdscr, ym, xm);
                                mvprintw(ym/2, xm/2 - 15, "Errore nel salvare il punteggio");
                                mvprintw(ym/2 + 1, xm/2 - 15, "Premi un tasto per continuare...");
                                refresh();
                                getch();
                            }
                        }
                    } else {
                        // Show final score even if it's 0
                        clear();
                        int xm, ym;
                        getmaxyx(stdscr, ym, xm);
                        mvprintw(ym/2, xm/2 - 15, "Punteggio finale: %d punti", finalScore);
                        mvprintw(ym/2 + 1, xm/2 - 15, "Premi un tasto per continuare...");
                        refresh();
                        getch();
                    }
                    
                } catch (const std::exception& e) {
                    // Restart ncurses if there was an error
                    initscr();
                    noecho();
                    curs_set(0);
                    keypad(stdscr, TRUE);
                    
                    clear();
                    int xm, ym;
                    getmaxyx(stdscr, ym, xm);
                    mvprintw(ym/2, xm/2 - 10, "Errore: %s", e.what());
                    mvprintw(ym/2 + 1, xm/2 - 15, "Premi un tasto per continuare...");
                    refresh();
                    getch();
                }
                break;
            }
            
            case 1: { // Classifica
                mainMenu.showLeaderboard();
                break;
            }
            
            case 2: { // Esci
                running = false;
                break;
            }
        }
    }
    
    endwin();
    return 0;
}

