//
// Created by RP on 08.06.2023.
//

#include <fstream>
#include "Configuration.h"
#include "../../Shapes/Square.h"
#include "../../Shapes/Circle.h"
#include "../ASCIICanvas.h"


Canvas* Configuration::getCanvas() {
    std::ifstream in(this->filename);
    in>>this->canvasWidth>>this->canvasHeight>>this->lightedSymbol>>this->shadowSymbol>>this->output_name;
    Canvas* canvas = new ASCIICanvas(this->canvasWidth,this->canvasHeight);
    std::string shape;
    while(in>>shape){
        if(shape == "Circle"){
            int radius,xpos,ypos;
            char symbol;
            in>>radius>>xpos>>ypos>>symbol;
            Circle c = Circle(radius,xpos,ypos,symbol);
            c.draw(*canvas);
        }
        else if(shape == "Rectangle"){
            int width,height,xpos,ypos;
            char symbol;
            in>>width>>height>>xpos>>ypos>>symbol;
            Rectangle rect = Rectangle(width,height,xpos,ypos,symbol);
            rect.draw(*canvas);
        }
        else if(shape == "Square"){
            int sideSize,xpos,ypos;
            char symbol;
            in>>sideSize>>xpos>>ypos>>symbol;
            Square s = Square(sideSize,xpos,ypos,symbol);
            s.draw(*canvas);
        }
        else if(shape == "Light"){
            int xpos,ypos;
            in>>xpos>>ypos;
            canvas->addLightSource(Light(xpos,ypos));
        }
    }
    in.close();
    canvas->add_shadows(this->lightedSymbol,this->shadowSymbol);
    return canvas;
}

Configuration::Configuration(std::string filename) {
    this->filename = filename;
}
