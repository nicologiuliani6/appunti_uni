#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "config.hpp"
#include <iostream>
#include <ctime>

class snake{
private:
    //GRIGLIA CAMPO
    bool position[GRID_SIZE_Y][GRID_SIZE_X];
    //CORDINATE TESTA
    int head_x_axis=-1;
    int head_y_axis=-1;
    //CORDINATE CODA
    int tail_x_axis=-1;
    int tail_y_axis=-1;
    //CORDINATE CORPO (no testa)
    int body[SNAKE_LENGHT-1][2]; //0=y,1=x 
    //LUNGHEZZA DEL SERPENTE
    int length=0;
    //GESTIONE COLLISIONI
    bool has_collided = false;
private:
    //AGGIORNA CORDINATE TESTA
    void update_head_cordinate(const int head_x_axis,const int head_y_axis){
        this->head_x_axis=head_x_axis;
        this->head_y_axis=head_y_axis;
    }
    //AGGIORNA CORDINATE CODA
    void update_tail_cordinate(const int tail_x_axis,const int tail_y_axis){
        this->tail_x_axis=tail_x_axis;
        this->tail_y_axis=tail_y_axis;
    }
    //CONTROLLA SE SERPENTE E' STATO INIZIALIZATO
    void check_initialized() {
        if (head_x_axis == -1) {
            std::cerr << "ERRORE: serpente non inizializzato!" << std::endl;
            exit(1);
        }
    }
    //STAMPA DI UN DEB DELLE CORDINATE
    void print_debug(){
        printf("DEBUG: position_x_head=%d\n", head_x_axis);
        printf("DEBUG: position_y_head=%d\n", head_y_axis);
        printf("DEBUG: position_x_tail=%d\n", tail_x_axis);
        printf("DEBUG: position_y_tail=%d\n", tail_y_axis);
    }
    //LOGICA DI MOVIMENTO
    int dir_up = 0, dir_down = 0, dir_east = 0, dir_west = 0;
    void move(const int up, const int down, const int east, const int west) {
        // calcolo nuova posizione testa
        int new_head_y = head_y_axis + (-up + down);
        int new_head_x = head_x_axis + (east - west);

        // gestione oltre i bordi
        if (new_head_y < 0) new_head_y = GRID_SIZE_Y - 1;
        if (new_head_y >= GRID_SIZE_Y) new_head_y = 0;
        if (new_head_x < 0) new_head_x = GRID_SIZE_X - 1;
        if (new_head_x >= GRID_SIZE_X) new_head_x = 0;

        // controlla collisione
        has_collided = position[new_head_y][new_head_x] && !(new_head_y == tail_y_axis && new_head_x == tail_x_axis);

        //DEBUG per le collisioni
        if (DEBUG && has_collided) {
            printf("DEBUG: collisione rilevata a (%d, %d)\n", new_head_x, new_head_y);
        }

        // aggiorna corpo
        int new_body[this->length - 2][2];
        new_body[0][0] = head_y_axis;
        new_body[0][1] = head_x_axis;
        //calcoliamo le cordinate del nuovo corpo
        for (auto i = 1; i < length - 1; i++) {
            new_body[i][0] = this->body[i - 1][0];
            new_body[i][1] = this->body[i - 1][1];
        }
        //scriviamo le nuove cordinate del corpo
        for (auto i = 0; i < length - 1; i++) {
            this->body[i][0] = new_body[i][0];
            this->body[i][1] = new_body[i][1];
        }

        // aggiorna testa
        head_y_axis = new_head_y;
        head_x_axis = new_head_x;
        update_head_cordinate(head_x_axis, head_y_axis);

        // impostiamo la nuova testa
        this->position[head_y_axis][head_x_axis] = true;

        // togliamo la vecchia coda
        this->position[tail_y_axis][tail_x_axis] = false;

        // aggiorna coda
        update_tail_cordinate(this->body[length - 2][1], this->body[length - 2][0]);

        if (DEBUG) print_debug();
    }

public:
    //COSTRUTTORE
    snake(){
        for(auto x=0; x<GRID_SIZE_Y; x++){
            for(auto y=0; y<GRID_SIZE_X; y++){
                this->position[x][y]=false;
            }
        }
        dir_up=0;
        dir_down=0;
        dir_east=0;
        dir_west=0;
    }
    //TRUE SE NELLA CELLA A QUELLE CORDINATE CE IL SERPENTE, E METTE TRUE IN is_head SE E LA CELLA DELLA TESTA
    bool is_present_on_this_cell(const int x, const int y, bool& is_head) {
        is_head = (head_x_axis == x && head_y_axis == y);
        return this->position[y][x];
    }
    // true se la testa collide con il corpo
    bool collision_body() {
        return has_collided;
    }

    //INIZIALIZZA LA POSIZIONE RANDOM DEL SERPRENTE
    void init_position(const int base_length) {    
        //check se la lunghezza non sia oltre il massimo consentito (ovvero max(GRID)-1)    
        if (base_length >= GRID_SIZE_X || base_length >= GRID_SIZE_Y || base_length <= 1) {
            std::cerr << "Errore: la lunghezza del serprente supera/inferiore la dimensione della griglia" << std::endl;
            exit(1);
        }

        //impostiamo la lunghezza del serpente
        this->length=base_length;
        
        //inizializzazione casuale della testa
        int position_y_head = rand() % (GRID_SIZE_Y - base_length);
        int position_x_head = rand() % (GRID_SIZE_X - base_length);
        
        //impostiamo attiva la cella della testa 
        this->position[position_y_head][position_x_head] = true;
        //aggiorniamo le cordinate della testa
        update_head_cordinate(position_x_head, position_y_head);
    
        //debug per la posizione testa
        if (DEBUG) {
            printf("DEBUG: position_x_head=%d\n", head_x_axis);
            printf("DEBUG: position_y_head=%d\n", head_y_axis);
        }
        
        //segniamoci le direzioni verso dove il corpo puo essere creato
        bool can_move[4];
        can_move[0] = position_y_head >= base_length;                       // Nord
        can_move[1] = position_x_head + base_length < GRID_SIZE_X;         // Est
        can_move[2] = position_y_head + base_length < GRID_SIZE_Y;         // Sud
        can_move[3] = position_x_head >= base_length;                      // Ovest
        
        //inizializzazione delle variabili per la scelta della direzione del corpo
        int direction = -1;
        int pick = 0;
        //ciclo per prendere casualmente una delle direzioni fra quelle possibili
        //ATTENZIONE: dato che cè il controllo sopra del limite della lunghezza per forza cè almeno una direzione consentita!
        do {
            pick = rand() % 4;
            direction = pick;
        } while (!can_move[pick]);
    
        // Variabili per la coda, che aggiorneremo una volta sola alla fine
        int tail_x = position_x_head;
        int tail_y = position_y_head;
        
        //ciclo per impostare le celle del corpo in base alla direzione
        for (int i = 1; i < base_length; ++i) {
            if (direction == 0) {
                // Nord
                if (position_y_head - i >= 0) {
                    //impostaimo la cella del corpo su occupata 
                    this->position[position_y_head - i][position_x_head] = true;
                    //calcoliamo le cordinate verticali della coda
                    tail_y = position_y_head - i;
                    //segniamoci le cordinate del corpo rispetto la coda e la testa
                    this->body[i-1][0]= tail_y; //y
                    this->body[i-1][1]= position_x_head; //x
                }
            } else if (direction == 1) {
                // Est
                if (position_x_head + i < GRID_SIZE_X) {
                    this->position[position_y_head][position_x_head + i] = true;
                    tail_x = position_x_head + i;
                    this->body[i-1][0]= position_y_head; //y
                    this->body[i-1][1]= tail_x; //x
                }
            } else if (direction == 2) {
                // Sud
                if (position_y_head + i < GRID_SIZE_Y) {
                    this->position[position_y_head + i][position_x_head] = true;
                    tail_y = position_y_head + i;
                    this->body[i-1][0]= tail_y; //y
                    this->body[i-1][1]= position_x_head; //x
                }
            } else {
                // Ovest
                if (position_x_head - i >= 0) {
                    this->position[position_y_head][position_x_head - i] = true;
                    tail_x = position_x_head - i;
                    this->body[i-1][0]= position_y_head; //y
                    this->body[i-1][1]= tail_x; //x
                }
            }
            
        }
        //aggiorniamo le cordinate finale della coda
        update_tail_cordinate(tail_x, tail_y);
        
        //debug per la posizione coda
        if (DEBUG) {
            printf("DEBUG: position_x_tail=%d\n", tail_x_axis);
            printf("DEBUG: position_y_tail=%d\n", tail_y_axis);
        }
    }
    //COMANDI DI MOVIMENTO
    void up() {
        dir_up=1; dir_down=0; dir_east=0; dir_west=0;
        move(1,0,0,0);
    }
    void down() {
        dir_up=0; dir_down=1; dir_east=0; dir_west=0;
        move(0,1,0,0);
    }
    void east() {
        dir_up=0; dir_down=0; dir_east=1; dir_west=0;
        move(0,0,1,0);
    }
    void west() {
        dir_up=0; dir_down=0; dir_east=0; dir_west=1;
        move(0,0,0,1);
    }
    void autoMove() {
        move(dir_up, dir_down, dir_east, dir_west);
    }
    
};
//ALLOCA MEMORIA
snake* alloc_snake();
#endif // SNAKE_HPP