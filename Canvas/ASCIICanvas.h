//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_ASCIICANVAS_H
#define STUDIA_ASCIICANVAS_H


#include "Canvas.h"

//Class representing canvas of 2-dimensional ASCII table
class ASCIICanvas : public Canvas{
public:
    ASCIICanvas(int width,int height);
    int* getShapeMatrix() override;
    //Prints canvas to console
    void show() override;
    void write_to_file(std::string filename);
    void addLightSource(Light l) override;
    void add_shadows(char emptySymbol,char shadowSymbol) override;
    vector<Light>& getLightSources() override;
    ~ASCIICanvas() override;
private:
    int linear(int ax,int ay, int by,int bx,double x) override;
    std::tuple<int,int> calculate_function_params(int x,int y,Light l) override;
};


#endif //STUDIA_ASCIICANVAS_H
