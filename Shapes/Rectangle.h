//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_RECTANGLE_H
#define STUDIA_RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure{
public:
    void draw(Canvas& c) override;
    Rectangle(int width,int height,int xpos,int ypos,char symbol);
private:
    int width,height;
};


#endif //STUDIA_RECTANGLE_H
