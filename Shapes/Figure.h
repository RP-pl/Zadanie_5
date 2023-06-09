//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_FIGURE_H
#define STUDIA_FIGURE_H


#include "../Canvas/Canvas.h"

class Figure {
public:
    Figure(int xpos,int ypos,char symbol){
        this->xpos = xpos;
        this->ypos = ypos;
        this->symbol = symbol;
    }
    int xpos{},ypos{};
    char symbol;
    virtual void draw(Canvas& c){};
};


#endif //STUDIA_FIGURE_H
