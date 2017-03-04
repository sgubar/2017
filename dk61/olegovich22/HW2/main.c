#include <stdio.h>
#include "dk_tool.h"

int main() {

    //max number of circles
    int size=10;

    //circle options
    float centerX=2.0;
    float centerY=2.0;
    float radius=7.0;

    //create struct
    optionCircle *mainCircle=createCircle(size);

    //add to struct data
    addToCircle(mainCircle, centerX, centerY, radius);
    addToCircle(mainCircle, 5, 4, 3);
    addToCircle(mainCircle, 0, 0, 9);

    //print result
    int printCounter=0;
    while(mainCircle->current_size > printCounter)
    {
        circle *getParamCircle=&(mainCircle->sizeCircle[printCounter]);
        printf("%d)Center (x, y): (%.3f, %.3f)\n", printCounter+1, getParamCircle->centerX, getParamCircle->centerY);
        printf("  Radius: %.3f\n", getParamCircle->radius);
        printf("  Square: %.3f\n", getParamCircle->square);
        printCounter++;
    }

    //destroy struct
    destroyAllCircle(mainCircle);

    return 0;
}