#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"

int main() {

    //max number of circles
    int size=10;

    //circle options
    float centerX=8.0;
    float centerY=8.0;
    float radius=8.0;

    FILE *aFile=fopen("data.json", "w+");

    //create struct
    circleList *aCircleList=createCircle(size);

    //add to struct data
    addToCircle(aCircleList, centerX, centerY, radius);
    addToCircle(aCircleList, 10, 10, 10);
    addToCircle(aCircleList, 6, 6, 6);
    addToCircle(aCircleList, 5, 5, 5);
    addToCircle(aCircleList, 2, 2, 2);

    //print sorted result
    printf("BEFORE SORTING\n");
    printCircles(aCircleList);

    int choice=getChoiceTypeSort();

    switch(choice)
    {
        case 1:
            bubbleSort(aCircleList);
        case 2:
            selectionSort(aCircleList);
        case 3:
            insertionSort(aCircleList);
        default:
            break;
    }

    //writing into file
    writeCircleList(aFile, aCircleList);

    //print sorted result
    printf("\nAFTER SORTING\n");
    printCircles(aCircleList);

    //close file after using
    fclose(aFile);

    //destroy struct
    destroyAllCircle(aCircleList);

    return 0;
}
