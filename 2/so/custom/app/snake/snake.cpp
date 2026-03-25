#include "snake.hpp"

//ALLOLCA MEMORIA
snake* alloc_snake(){
    return (snake*)new snake;
}
//STAMPA IL CAMPO DA TERMINALE (per debug)
void print_command_line(snake* S) {
    bool is_head = false;
    for (int y = 0; y < GRID_SIZE_Y; ++y) {
        for (int x = 0; x < GRID_SIZE_X; ++x) {
            if (S->is_present_on_this_cell(x, y, is_head)) {
                if (is_head) std::cout << "H";
                else std::cout << "0";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

