#include <stdio.h>
#include "dk_tool.h"

int main() {

    //max number of circles
    int size=10;

    //circle options
    float centerX=3.0;
    float centerY=3.0;
    float radius=9.0;

    //create struct
    circleList *aCircleList=createCircle(size);

    //add to struct data
    addToCircle(aCircleList, centerX, centerY, radius);
    addToCircle(aCircleList, 6, 5, 4);
    addToCircle(aCircleList, 1, 1, 9);

    //print result
    print(aCircleList);

    //destroy struct
    destroyAllCircle(aCircleList);

    return 0;
}
