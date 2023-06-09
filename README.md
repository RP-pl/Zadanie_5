# Zestaw 5
##### Radosław Pikul gr.7 08.06.2023

## Jak uruchomić:
* `make run` - aby odpalić domyślną konfigurację
* `make compile` - aby skompilować rozwiązanie do pliku a.out
* `g++ -o a.out main.cpp ./Canvas/ASCIICanvas.cpp ./Canvas/ASCIICanvas.h ./Canvas/Canvas.h ./Canvas/Config/Configuration.cpp ./Canvas/Config/Configuration.h ./Light/Light.cpp ./Light/Light.h ./Shapes/Figure.h ./Shapes/Circle.h ./Shapes/Circle.cpp ./Shapes/Rectangle.h ./Shapes/Rectangle.cpp ./Shapes/Square.h ./Shapes/Square.cpp &&
    ./a.out /plik_z_komfiguracją /plik_wyjściowy` - gdyby makefile nie działał


## Hierarchia klas
* Canvas
* * ASCIICanvas
* Figure
* * Rectangle
* * * Square
* * Circle
* Light

## Schemat pliku konfiguracyjnego

> 1. wysokość[int] szerokość[int]
> 2. znak pustego pola[char]
> 3. znak cieniowanego pola[char]
> 4. plik wyjściowy[string]
> 5. W dowolnej kolejności i ilości:
>    - Light xpos[int] ypos[int]
>    - Circle radius[int] xpos[int] ypos[int] symbol[char]
>    - Square sideWidth[int] xpos[int] ypos[int] symbol[char]
>    - Rectangle width[int] height[int] xpos[int] ypos[int] symbol[char]

## Działanie cieniowania

W moim programie cienie są tworzone w następujący sposób:
1. Dla każdego światła i każdego punktu program wybiera parametry funkcji liniowej łączącej te dwa punkty
2. Centrum wykresu funkcji ustawiane jest na punkcie światła
3. Program sprawdza czy na drodze "promienia światła" (funkcji liniowej zaokrąglonej do liczb całkowitych) nie ma żadnej przeszkody
4. Jeśli przeszkoda istnieje reszta trasy "promienia" nie zostaje oświetlona

Technika symulacyjna zapewnia stosunkowo dobre przybliżenia cieniowania dla odpowiednio dużych wielkości Canvas (optymalnie przykład z PDF-a powiększony 10 razy)

Różnice w stosunku do przykładu z PDF-a wynikają prawdopdobnie z innego zaokrąglania funkcji liniowej.

Przykład działania programu znajduje się w pliku [przyklad.txt](./przyklad.txt)

