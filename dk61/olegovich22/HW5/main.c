#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"
#include "search.h"

int main() {

    //max number of circles
    int size=10;

    FILE *aFile=fopen("data.json", "w+");

    //create struct
    circleList *aCircleList=createCircle(size);

    //add to struct data
    addToCircle(aCircleList, 1, 1, 4);
    addToCircle(aCircleList, 2, 2, 7);
    addToCircle(aCircleList, 3, 3, 3);
    addToCircle(aCircleList, 4, 4, 7);

    //print sorted result
    printf("YOUR CIRCLES\n");
    printCircles(aCircleList);

    // get type of sort and sorting
    int choice=getTypeOfSort();
    if (choice==1)
    {
        shellSort(aCircleList);
    }
    else if (choice==2)
    {
        quickSort(aCircleList, 0, aCircleList->current_size-1);
    }

    //writing into file
    writeCircleList(aFile, aCircleList);
    printf("\nCircles have written into file\n");

    //print sorted result
    printf("\nAFTER SORTING\n");
    printCircles(aCircleList);

    //geting key(search radius) from user
    float aKey=getKey();

    //geting type of search an searching
    choice=getTypeOfSearch();
    int searchPosition=0;
    if (choice==1)
    {
        searchPosition=line_find(aCircleList, aKey);
    }
    else if (choice==2)
    {
        searchPosition=binary_find(aCircleList, aKey);
    }

    //print search result
    printSearchResult(aCircleList, searchPosition);

    //close file after using
    fclose(aFile);

    //destroy struct
    destroyAllCircle(aCircleList);

    return 0;
}
