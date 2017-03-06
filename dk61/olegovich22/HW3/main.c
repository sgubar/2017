#include <stdio.h>
#include "dk_tool.h"

int main() {

    //max number of circles
    int size=10;

    //circle options
    float centerX=2.0;
    float centerY=2.0;
    float radius=8.0;

    FILE *aFile=fopen("data.json", "w+");

    //create struct
    circleList *aCircleList=createCircle(size);

    //add to struct data
    addToCircle(aCircleList, centerX, centerY, radius);
    addToCircle(aCircleList, 1, 5, 8);
    addToCircle(aCircleList, 0, 0, 7);


    //writing into file
    writeCircleList(aFile, aCircleList);

    //print result
    int CircleCounter=0;
    while(aCircleList->current_size > CircleCounter)
    {
        circle *sizeCircle=&(aCircleList->sizeCircle[CircleCounter]);
        printf("%d)Center (x, y): (%.3f, %.3f)\n", CircleCounter+1, sizeCircle->centerX, sizeCircle->centerY);
        printf("  Radius: %.3f\n", sizeCircle->radius);
        printf("  Square: %.3f\n", sizeCircle->square);
        CircleCounter++;
    }

    //close file after using
    fclose(aFile);

    //destroy struct
    destroyAllCircle(aCircleList);

    return 0;
}
