#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
using namespace std;

class Menu {
    protected:
        int base, altezza;
        WINDOW * menu;
    public:
        // costruttore
        Menu(int h, int b, int scelta, int evidenzia) {
            int xm, ym;
            getmaxyx(stdscr, ym, xm);
            // creo la finestra centrata b * h del menù
            menu = newwin(h, b, (ym/2)-(h/2), (xm/2)-(b/2));
            base = b;
            altezza = h;
        }
        //eliminatore
        ~Menu() {
            if (menu) {
                delwin(menu);
            }
        }
        // inizializza la finestra
        void inizializza() {
            box(menu, 0, 0);
            wrefresh(menu);
        }
        //attivazione input
        void input_tastiera() {
            keypad(menu, true);
        }
        
        WINDOW* getWindow() {
            return menu;
        }
        
};
// funzione che mi chiude il gioco e mi stampa la scritta "game over"
void gameover(){
    int xm, ym;
    getmaxyx(stdscr, ym, xm);
    clear();
    mvprintw(ym/2, xm/2-5, "GAME OVER");
    refresh();
    getch();
}

#endif // MENU_HPP
