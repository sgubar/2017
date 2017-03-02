#include <stdio.h>
#include "dk_tool.h"

int main() {

    int size=10;

    //circle optins
    float centerX=2.0;
    float centerY=2.0;
    float radiusX=5.0;
    float radiusY=6.0;

    //create struct
    optionCircle *mainCircle=createCircle(size);

    //add to struct data
    addToCircle(mainCircle, centerX, centerY, radiusX, radiusY);
    addToCircle(mainCircle, 5, 4, 3, 2);
    addToCircle(mainCircle, 0, 0, 0, 0);

    //print result
    int printCounter=0;
    while(mainCircle->current_size > printCounter)
    {
        circle *getParam=&(mainCircle->sizeCircle[printCounter]);
        printf("\n%d)Center (x, y): (%.3f, %.3f)\n  Radius (x, y): (%.3f, %.3f)\n  Square: %.3f\n", printCounter+1, getParam->centerX, getParam->centerY, getParam->radiusX, getParam->radiusY, getParam->square);
        printCounter++;
    }

    //destroy struct
    destroyAllCircle(mainCircle);

    return 0;
}