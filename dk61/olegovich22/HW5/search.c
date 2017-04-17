//
// Created by Oleh on 10.04.2017.
//

#include "search.h"
#include <stdio.h>
#include <float.h>
#include "dk_tool.h"

int line_find(circleList *aCircleList, float aKey)
{
    int theResult = -1;

    for (int i = 0; i < aCircleList->current_size; i++)
    {
        if (aCircleList->sizeCircle[i].radius == aKey)
        {
            theResult = i;
            break;
        }
    }

    return theResult;
}

int binary_find(circleList *aCircleList, float aKey)
{
    int theResult = -1;
    int theLowerBound = 0;
    int theUpperBound = aCircleList->current_size-1;
    int theCurIn = 0;

    while (1)
    {
        theCurIn = (theLowerBound + theUpperBound) / 2;
        if (aCircleList->sizeCircle[theCurIn].radius == aKey) //<!- an element was found
        {
            theResult = theCurIn;
            break;
        }
        else if (theLowerBound > theUpperBound) //<!- all elements were viewed
        {
            break;
        }
        else
        {
            if (aCircleList->sizeCircle[theCurIn].radius < aKey)
            {
                theLowerBound = theCurIn + 1; //!<- in upper position
            }
            else
            {
                theUpperBound = theCurIn - 1; //!<- in lower position
            }
        }

    }

    return theResult;
}

//get users choice type of sort from user
int getTypeOfSearch()
{
    int numb=0;
    printf("\nPlease do a choice type of search:\n");
    printf("Enter 1 - liner search\n");
    printf("Enter 2 - binary search\n");
    do
    {
        int aChek=scanf("%d", &numb);
        rewind(stdin); //clear buffer in scanf
        if (numb<1 || numb>2 || aChek!=1)
            printf("ERROR. Please do a choice and enter one integer or 1 or 2\n");
    }
    while(numb<1 || numb>2);

    return numb;
}

//get key
float getKey()
{
    printf("Please enter radius length of circle which you want to find\n");

    float aKey=0;
    int repair=0;
    do
    {
        repair=scanf("%f", &aKey);
        if (aKey<0 || repair!=1)
        {
            printf("ERROR. Radius can't be low zero\n");
        }
        if (aKey>FLT_MAX)
        {
            printf("ERROR. You entered max numb. Please enter lower numb.\n");
        }
        fflush(stdin);
    }while(aKey>FLT_MAX || aKey<0 || repair!=1);

    return aKey;
}

//print search result
void printSearchResult(circleList *aCircleList, int searchPosition)
{
    if(searchPosition==-1)
    {
        printf("Your circle has not been found\n");
    }
    else
    {
        printf("\nYour circle has been found on %i position\n", searchPosition);
        printf("Searched circle\n");
        printf("Center (x, y): (%.3f, %.3f)\n", aCircleList->sizeCircle[searchPosition].centerX, aCircleList->sizeCircle[searchPosition].centerY);
        printf("Radius: %.3f\n", aCircleList->sizeCircle[searchPosition].radius);
    }
}