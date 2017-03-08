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
    circleList *aCircleList=createCircle(size);

    //add to struct data
    addToCircle(aCircleList, centerX, centerY, radius);
    addToCircle(aCircleList, 5, 4, 3);
    addToCircle(aCircleList, 0, 0, 9);

    //print result
    print(aCircleList);

    //destroy struct
    destroyAllCircle(aCircleList);

    return 0;
}