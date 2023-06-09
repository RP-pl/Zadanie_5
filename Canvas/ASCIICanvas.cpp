//
// Created by RP on 08.06.2023.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "ASCIICanvas.h"

int* ASCIICanvas::getShapeMatrix() {
    return this->shapeMatrix;
}

ASCIICanvas::ASCIICanvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->shapeMatrix = (int*) malloc(width*height*sizeof(int));
    memset(this->shapeMatrix,0, this->width * this->height * sizeof(int));
}

void ASCIICanvas::show() {
    for(int i=0;i<width+2;i++){
        std::cout<<'=';
    }
    std::cout<<'\n';
    for(int i = 0;i<this->height;i++){
        std::cout<<'|';
        for(int j=0;j<this->width;j++){
            std::cout<<(char)this->shapeMatrix[i*this->width + j];
        }
        std::cout<<"|\n";
    }

    for(int i=0;i<width+2;i++){
        std::cout<<'=';
    }
    std::cout<<'\n';
}

ASCIICanvas::~ASCIICanvas() {
    delete this->shapeMatrix;
}

void ASCIICanvas::addLightSource(Light l) {
    this->lightsSources.push_back(l);
    this->shapeMatrix[l.xpos + l.ypos*this->width] = '*';
}

vector<Light> &ASCIICanvas::getLightSources() {
    return this->lightsSources;
}

void ASCIICanvas::write_to_file(std::string filename) {
    std::ofstream out(filename, std::ios_base::out);
    for(int i=0;i<width+2;i++){
        out<<'=';
    }
    out<<'\n';
    for(int i = 0;i<this->height;i++){
        out<<'|';
        for(int j=0;j<this->width;j++){
            out<<(char)this->shapeMatrix[i*this->width + j];

        }
        out<<"|\n";
    }

    for(int i=0;i<width+2;i++){
        out<<'=';
    }
    out<<'\n';
    out.close();
}

void ASCIICanvas::add_shadows(char emptySymbol,char shadowSymbol) {
    Canvas& canvas = *this;
    int* matrix = canvas.getShapeMatrix();
    for(Light l : canvas.getLightSources()) {
        for (int x = 0; x < canvas.width; x++) {
            for (int y = 0; y < canvas.height; y++) {
                std::tuple<int,int> t = calculate_function_params(x,y,l);
                int ax = std::get<1>(t);
                int ay = std::get<0>(t);
                double step = 1.0/ax;
                if(ax == 0){
                    step = 1;
                }
                if(ax < 0){
                    step *= -1;
                }
                if(l.xpos < x){
                    step *= -1;
                }
                for(double i =l.xpos;0<=i&&i<canvas.width;i-=step){
                    if(ay == 0){
                        i+=l.xpos;
                        if(y < l.ypos) {
                            for (int n = l.ypos; 0 <= n; n--) {
                                if (matrix[n * canvas.width + l.xpos] == 0 || matrix[n * canvas.width + l.xpos] == 4){
                                    matrix[n * canvas.width + l.xpos] = 4;
                                }
                                else if (matrix[n * canvas.width + l.xpos] == '*'){}
                                else{
                                    break;
                                }
                            }
                        }
                        else{
                            for (int n = l.ypos; n<canvas.height; n++) {
                                if (matrix[n * canvas.width + l.xpos] == 0 || matrix[n * canvas.width + l.xpos] == 4){
                                    matrix[n * canvas.width + l.xpos] = 4;
                                }
                                else if (matrix[n * canvas.width + l.xpos] == '*'){}
                                else{
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        int y_comp = linear(ax, ay, l.ypos, l.xpos, i);
                        if (y_comp < canvas.height && 0 <= y_comp && round(i) < canvas.width && 0 <= round(i)) {
                            if (matrix[y_comp * canvas.width + (int) round(i)] == 0 || matrix[y_comp * canvas.width + (int) round(i)] == 4) {
                                matrix[y_comp * canvas.width + (int) round(i)] = 4;
                            }
                            else if (matrix[y_comp * canvas.width + (int) round(i)] == '*'){}
                            else{
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<canvas.width*canvas.height;i++){
        if(matrix[i] == 0){
            matrix[i] = shadowSymbol;
        }
        else if(matrix[i] == 4){
            matrix[i] = emptySymbol;
        }
    }
}

int ASCIICanvas::linear(int ax, int ay, int by, int bx, double x) {
    if(ay != 0) {
        return round(((1.0 * ax) / ay) * (x-bx)) + by;
    }
    else{
        return bx;
    }
}

std::tuple<int, int> ASCIICanvas::calculate_function_params(int x, int y, Light l) {
    int x_dist = l.xpos - x;
    int y_dist = l.ypos - y;
    int gcd = std::__gcd(x_dist,y_dist);
    if(gcd == 0){
        gcd = 1;
    }
    return std::make_tuple(x_dist/gcd,y_dist/gcd);
}
