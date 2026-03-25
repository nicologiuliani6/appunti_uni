#ifndef POINTS_HPP
#define POINTS_HPP

#include <iostream>

class Points{
    protected:
        int pt;

    public:
        //costruttore
        Points(int p = 0) : pt(p) {}

        // pt se viene mangiata mela
        void eat_apple(){
            pt += 10;
        }

        // pt bonus fine livello
        void end_lvl(int bonus) { 
            pt += bonus; 
        }

        // pt attuali
        int get_points() const {
            return pt; 
        }
};

#endif // POINTS_HPP