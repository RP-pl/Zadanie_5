//
// Created by RP on 08.06.2023.
//

#ifndef STUDIA_LIGHT_H
#define STUDIA_LIGHT_H


//Class representing light source
//Could not inherit from Figure because of draw method implementation
class Light{

public:
    Light(int xpos,int ypos);

    int xpos;
    int ypos;
};


#endif //STUDIA_LIGHT_H
