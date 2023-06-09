//
// Created by RP on 08.06.2023.
//

#include "Rectangle.h"

void Rectangle::draw(Canvas &c) {
    int* shapeMatrix = c.getShapeMatrix();
    for(int y=0;y< this->height;y++){
        for(int x=0;x< this->width;x++){
            if(0 <= ypos + y && ypos + y < c.height && 0<=x + this->xpos && x + this->xpos < c.width) {
                shapeMatrix[(ypos + y) * c.width + xpos + x] = this->symbol;
            }
        }
    }
}

Rectangle::Rectangle(int width, int height,int xpos,int ypos,char symbol) : Figure(xpos,ypos,symbol){
    this->width = width;
    this->height = height;
}
