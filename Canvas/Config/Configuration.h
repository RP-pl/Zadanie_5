//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_CONFIGURATION_H
#define STUDIA_CONFIGURATION_H


#include <string>
#include <vector>
#include "../Canvas.h"

class Configuration {
public:
    char shadowSymbol = '.';
    char lightedSymbol = ' ';
    int canvasWidth = 20;
    int canvasHeight = 10;
    Configuration(std::string filename);
    std::string filename;
    std::string output_name;

    Canvas* getCanvas();
};


#endif //STUDIA_CONFIGURATION_H
