//
// Created by RP on 08.06.2023.
//

#include "Circle.h"


void Circle::draw(Canvas &c) {
    int* shapeMatrix = c.getShapeMatrix();
    for(int x=-this->radius+1;x<this->radius;x++){
        for(int y=-this->radius+1;y<this->radius;y++){
            if(x*x + y*y <= this->radius * this->radius) {
                if(0 <= ypos + y && ypos + y < c.height && 0<=x + this->xpos && x + this->xpos < c.width) {
                    shapeMatrix[(this->ypos + y) * c.width + (x + this->xpos)] = this->symbol;
                }
            }
        }
    }
}

Circle::Circle(int radius, int xpos, int ypos,char symbol) : Figure(xpos,ypos,symbol){
    this->radius = radius;
}
