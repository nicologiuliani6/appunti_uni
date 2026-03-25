#ifndef GRIGLIA_HPP
#define GRIGLIA_HPP

#include "config.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <cstdio>
#include "snake.hpp"
#include "levels.hpp"


class Griglia {
protected:
    int base, altezza;
    WINDOW* win;

public:
    // Costruttore: crea una finestra centrata di dimensione h x b
    Griglia(int h, int b) : base(b), altezza(h) {
        int xm, ym;
        getmaxyx(stdscr, ym, xm);

        if (ym < h + 2 || xm < b + 2) {
            endwin();
            fprintf(stderr, "Terminal too small (%d,%d), need at least (%d,%d)\n", xm, ym, b + 2, h + 2);
            exit(1);
        }

        win = newwin(h, b, (ym / 2) - (h / 2), (xm / 2) - (b / 2));
        if (win == nullptr) {
            endwin();
            fprintf(stderr, "Failed to create window\n");
            exit(1);
        }
    }

    // Inizializza la griglia: cancella, disegna il bordo e un titolo, e aggiorna
    void inizializza() {
        if (win != nullptr) {
            wclear(win);
            box(win, 0, 0);
            mvwprintw(win, 0, 2, " GRIGLIA ");
            wrefresh(win);
        }
    }

    // Aggiorna la finestra
    void refresh() {
        if (win != nullptr) {
            wrefresh(win);
        }
    }

    // Cancella la finestra e ridisegna il bordo
    void clear() {
        if (win != nullptr) {
            wclear(win);
            box(win, 0, 0);
            wrefresh(win);
        }
    }

    // Aggiunge un carattere alla posizione y,x (coordinate relative alla finestra)
    void aggiungi(const int y, const int x, const char c) {
        if (win != nullptr && y >= 0 && x >= 0 && y < altezza && x < base) {
            mvwaddch(win, y, x, c);
        }
    }
    //funzione del cpp per il bordo
    void drawBorder();
};

#endif
