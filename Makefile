COMPILER = gcc
CFLAGS = -Wall -std=c99 -pedantic

.PHONY: run
run: a.out
	./a.out ./config.txt

.PHONY: compile
compile: a.out

a.out : main.cpp ./Canvas/ASCIICanvas.cpp ./Canvas/ASCIICanvas.h ./Canvas/Canvas.h ./Canvas/Config/Configuration.cpp ./Canvas/Config/Configuration.h ./Light/Light.cpp ./Light/Light.h ./Shapes/Figure.h ./Shapes/Circle.h ./Shapes/Circle.cpp ./Shapes/Rectangle.h ./Shapes/Rectangle.cpp ./Shapes/Square.h ./Shapes/Square.cpp
	 g++ -o a.out main.cpp ./Canvas/ASCIICanvas.cpp ./Canvas/ASCIICanvas.h ./Canvas/Canvas.h ./Canvas/Config/Configuration.cpp ./Canvas/Config/Configuration.h ./Light/Light.cpp ./Light/Light.h ./Shapes/Figure.h ./Shapes/Circle.h ./Shapes/Circle.cpp ./Shapes/Rectangle.h ./Shapes/Rectangle.cpp ./Shapes/Square.h ./Shapes/Square.cpp

.PHONY: clean
clean:
	rm a.out