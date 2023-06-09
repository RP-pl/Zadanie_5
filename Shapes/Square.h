//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_SQUARE_H
#define STUDIA_SQUARE_H


#include "Rectangle.h"

class Square : public Rectangle{
public:
    Square(int side_width,int xpos,int ypos,char symbol) : Rectangle(side_width,side_width,xpos,ypos,symbol){};
};


#endif //STUDIA_SQUARE_H
