#include <iostream>
#include "Canvas/ASCIICanvas.h"
#include "Canvas/Config/Configuration.h"
#include <cmath>




int main(int argc,char* argv[]) {
    if(argc != 2){
        std::cout<<"Invalid number of arguments\n";
        exit(1);
    }
    Configuration config = Configuration(argv[1]);
    ASCIICanvas* canvas = dynamic_cast<ASCIICanvas *>(config.getCanvas());

    canvas->write_to_file(config.output_name);
    delete canvas;
    return 0;
}