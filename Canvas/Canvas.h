//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_CANVAS_H
#define STUDIA_CANVAS_H


#include "../Light/Light.h"
#include <vector>
#include <tuple>

using std::vector;

//Abstract class representing all methods needed by canvas subclasses to work properly
class Canvas {
public:
    //Show canvas
    virtual void show() {};
    int width{};
    int height{};
    virtual int* getShapeMatrix(){};
    virtual void addLightSource(Light l){};
    virtual vector<Light>& getLightSources(){};
    virtual void add_shadows(char emptySymbol,char shadowSymbol){};
    virtual ~Canvas(){};
    vector<Light> lightsSources;
protected:
    int* shapeMatrix{};
    //Linear function needed to create shadows
    virtual int linear(int ax,int ay, int by,int bx,double x) {};
    virtual std::tuple<int,int> calculate_function_params(int x,int y,Light l) {
        return std::make_tuple(0,0);
    };
};


#endif //STUDIA_CANVAS_H
