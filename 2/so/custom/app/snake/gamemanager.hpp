#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <iostream>
#include <ctime>
#include <ncurses.h>


// Game manager
class GameManager {
    private:
        snake* S;
        Griglia* griglia;
        Points* points;
        Livelli* levels;
        bool game_running;
        int final_score; // Store final score

        // Mela posizione
        int apple_x, apple_y;

        // Direzione corrente
        //creiamo un tipo di dato Direction che puo essere solo UP, DOWN, EAST, WEST
        enum Direction { UP, DOWN, EAST, WEST };
        Direction current_direction;

    public:
        GameManager() : S(nullptr), griglia(nullptr), points(nullptr), levels(nullptr),
                        game_running(true), apple_x(-1), apple_y(-1), current_direction(EAST),
                        final_score(0) {}

        //init finestra ncurses
        void initializeNCurses() {
            initscr();
            cbreak();
            noecho();
            nodelay(stdscr, TRUE);
            keypad(stdscr, TRUE);
            curs_set(0);
            clear();
            refresh();

            int rows, cols;
            getmaxyx(stdscr, rows, cols);
            const int MIN_ROWS = 24;
            const int MIN_COLS = 14;
            if (rows < MIN_ROWS || cols < MIN_COLS) {
                endwin();
                std::cerr << "Terminal too small (" << rows << "," << cols << "), need at least (" << MIN_ROWS << "," << MIN_COLS << ")\n";
                std::exit(1);
            }
        }
        //chiudiamo ncurses
        void cleanupNCurses() {
            endwin();
        }
        //otteniamo punteggio finale
        int getFinalScore() const {
            return final_score;
        }
        //CREIAMO GLI ELEMENTI DEL GIOCO
        void createGameObjects() {
            griglia = new Griglia(GRID_SIZE_Y + 2, GRID_SIZE_X + 2);
            S = alloc_snake();
            points = new Points();
            levels = new Livelli();
            current_direction = EAST;
            placeApple();
        }
        //generiamo un amela randomica
        void placeApple() {
            while(true) {
                apple_x = rand() % GRID_SIZE_X;
                apple_y = rand() % GRID_SIZE_Y;

                bool is_head = false;
                if (!S->is_present_on_this_cell(apple_x, apple_y, is_head)) break;
            }
        }
        //stampiamo la griglia di gioco e legenda
        void printGame() {
            clear();
            griglia->clear();
            griglia->drawBorder();

            bool is_head = false;
            //stampa griglia di
            for (int y = 0; y < GRID_SIZE_Y; y++) {
                for (int x = 0; x < GRID_SIZE_X; x++) {
                    if (S->is_present_on_this_cell(x, y, is_head)) {
                        griglia->aggiungi(y + 1, x + 1, is_head ? 'H' : 'O');
                    }
                }
            }

            griglia->aggiungi(apple_y + 1, apple_x + 1, '@');

            mvprintw(1, 2, "Level: %d | Points: %d | Time left: %d sec",
                    levels->getCurrentLevelId(), points->get_points(), levels->getRemainingTime());
            mvprintw(2, 2, "Controls: W/A/S/D to move, Q to quit");
            mvprintw(3, 2, "Use + or - to change level, or give the exact level number");

            refresh();
            griglia->refresh();
        }
        //passaggio al livello successivo di ncurses
        void nextLevel() {
            points->end_lvl(levels->getCurrentLevelBonus());

            if (!levels->isLastLevel()) {
                levels->nextLevel();

                clear();
                mvprintw(LINES / 2, COLS / 2 - 15, "Level %d completed!", levels->getCurrentLevelId() - 1);
                mvprintw(LINES / 2 + 1, COLS / 2 - 15, "Moving to Level %d...", levels->getCurrentLevelId());
                refresh();
                sleep_ms(2000);
            } else {
                clear();
                mvprintw(LINES / 2, COLS / 2 - 10, "Game Completed!");
                mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Final Score: %d", points->get_points());
                refresh();
                sleep_ms(3000);
                game_running = false;
            }
        }
        //gestore input del movimento del serpente  e del quit
        void handleInput() {
            int ch = getch();
            if (ch != ERR) {
                switch (ch) {
                    case 'w': case 'W':
                        S->up();
                        printGame();
                        break;
                    case 's': case 'S':
                        S->down();
                        printGame();
                        break;
                    case 'd': case 'D':
                        S->east();
                        printGame();
                        break;
                    case 'a': case 'A':
                        S->west();
                        printGame();
                        break;
                    case 'q': case 'Q': case 27:
                        game_running = false;
                        break;
                }
            }
        }
        //controlliamo le collisioni del corpo del serpente
        bool checkCollision(snake* S) {
            return S->collision_body();
        }
        //controlliamo le collisioni con le mele
        bool checkAppleCollision() {
            int head_x, head_y;
            if (getHeadPos(head_x, head_y)) {
                if (head_x == apple_x && head_y == apple_y) {
                    points->eat_apple();
                    placeApple();
                    return true;
                }
            }
            return false;
        }
        //otteniamo la posizione della testa e ritorniamo se l'abbiamo trovata
        bool getHeadPos(int& x, int& y) {
            bool is_head = false;
            for (int j = 0; j < GRID_SIZE_Y; j++) {
                for (int i = 0; i < GRID_SIZE_X; i++) {
                    if (S->is_present_on_this_cell(i, j, is_head) && is_head) {
                        x = i; y = j;
                        return true;
                    }
                }
            }
            return false;
        }

        // Aggiornamento del gameLoop per gestire il cambio livello
        void gameLoop() {
            S->init_position(SNAKE_LENGHT);
            griglia->inizializza();
            printGame();

            std::clock_t last_move_time = std::clock();
            std::clock_t last_render_time = std::clock();
            bool input_received = false;

            while (game_running) {
                if (levels->isCurrentLevelTimeUp()) {
                    nextLevel();
                    if (!game_running) break;
                }

                int ch = getch();
                if (ch != ERR) {
                    switch (ch) {
                        case 'w': case 'W': case KEY_UP:
                            S->up();
                            input_received = true;
                            printGame();
                            break;
                        case 's': case 'S': case KEY_DOWN:
                            S->down();
                            input_received = true;
                            printGame();
                            break;
                        case 'd': case 'D': case KEY_RIGHT:
                            S->east();
                            input_received = true;
                            printGame();
                            break;
                        case 'a': case 'A': case KEY_LEFT:
                            S->west();
                            input_received = true;
                            printGame();
                            break;
                        case 'q': case 'Q': case 27:
                            game_running = false;
                            break;
                        // Usare tasti numerici per cambio livello
                        case '1': case '2': case '3': case '4': case '5':
                            {
                                int target_level = ch - '0';
                                if (target_level >= 1 && target_level <= 5) {
                                    // Cambia al livello specificato
                                    for (int i = 0; i < 5; i++) {
                                        if (levels->getCurrentLevelId() == target_level) break;
                                        placeApple();
                                        levels->nextLevel();
                                    }
                                    printGame();
                                }
                            }
                            break;
                        // Usare + e - per navigare tra i livelli
                        case '+': case '=':
                            placeApple();
                            levels->nextLevel();
                            printGame();
                            break;
                        case '-': case '_':
                            placeApple();
                            levels->prevLevel();
                            printGame();
                            break;
                    }
                }
                //se presente l'input del giocatore
                if (input_received) {
                    std::clock_t current_time = std::clock();
                    double elapsed_seconds = double(current_time - last_move_time) / CLOCKS_PER_SEC;
                    //movimento automatico del serprente
                    if (elapsed_seconds >= levels->getCurrentLevelSpeed() / 1000.0) {
                        S->autoMove();
                        last_move_time = current_time;


                    }
                    //fermiamo il gicoo se il corpo collide 
                    if (checkCollision(S)) {
                        game_running = false;
                        break;
                    }
                    checkAppleCollision();
                    //stampiamo il gioco
                    printGame();
                }

                std::clock_t current_time = std::clock();
                double elapsed_render = double(current_time - last_render_time) / CLOCKS_PER_SEC;

                if (elapsed_render >= 1.0) {
                    printGame();
                    last_render_time = current_time;
                }

                sleep_ms(10);
            }

            final_score = points->get_points();
        }

        int run() {
            initializeNCurses();
            createGameObjects();

            clear();
            mvprintw(LINES / 2, COLS / 2 - 15, "Snake Game Starting...");
            mvprintw(LINES / 2 + 1, COLS / 2 - 20, "Use WASD or Arrow Keys to move");
            mvprintw(LINES / 2 + 2, COLS / 2 - 10, "Press Q to quit");
            mvprintw(LINES / 2 + 4, COLS / 2 - 15, "Press any key to start!");
            refresh();

            nodelay(stdscr, FALSE);
            getch();
            nodelay(stdscr, TRUE);
            //gioco
            gameLoop();

            clear();
            mvprintw(LINES / 2, COLS / 2 - 5, "Game Over!");
            mvprintw(LINES / 2 + 1, COLS / 2 - 10, "Final Score: %d", final_score);
            mvprintw(LINES / 2 + 2, COLS / 2 - 15, "Press any key to continue...");
            refresh();
            nodelay(stdscr, FALSE);
            getch();
            //pulizia finale del gioco di ncurses
            cleanupNCurses();

            return final_score;
        }

        // Funzione per ritardo (millisecondi) usando solo <ctime>
        void sleep_ms(int milliseconds) {
            std::clock_t start_time = std::clock();
            while (1000.0 * (std::clock() - start_time) / CLOCKS_PER_SEC < milliseconds);
        }
};

#endif
