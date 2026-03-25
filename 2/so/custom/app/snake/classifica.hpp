#ifndef CLASSIFICA_HPP
#define CLASSIFICA_HPP

#include "config.hpp"
#include <iostream>
#include <fstream> //per la gestione dei file .txt
#include <cstring>



#define BUFFER_SIZE 500 //buffer globale per un po tutto
//STRUTTURA PER LA GESTIONE DEI DATI DEI PLAYER
typedef struct player{
public:
    char name[BUFFER_SIZE]; //nome del giocatore
    unsigned int points; //punteggio del giocatore
    //NOTA: la posizione verra calcolata in modo dinamico alla classifica!
public:
    //costruttore con parametri
    player(const char* name, const unsigned int points) {
        strncpy(this->name, name, BUFFER_SIZE - 1); //ricorda: \0!
        this->name[BUFFER_SIZE - 1] = '\0';
        this->points = points;
    }
    // Costruttore predefinito (facoltativo in questo codice)
    player() : points(0) {
        this->name[0] = '\0';  // Nome vuoto
    }
} *ptr_player; //puntatore alla struttura

//OTTIENE LA CLASSIFICA ATTUALE
char* get_leaderboard();
//SCRIVI SU FILE LA CLASSIFICA
void write_leaderboard(const ptr_player player[], int length);
//SCRIVI LA NUOVA CLASSIFICA SORTATA CON UN NUOVO PLAYER
void add_player_to_leaderboard_file(const char name[],const unsigned int points);
#endif