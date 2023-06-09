//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_CIRCLE_H
#define STUDIA_CIRCLE_H


#include "Figure.h"

class Circle : public Figure{
private:
    int radius{};


public:
    explicit Circle(int radius,int xpos,int ypos,char symbol);
    void draw(Canvas& c) override;
};


#endif //STUDIA_CIRCLE_H
