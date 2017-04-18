//
// Created by Oleh on 10.04.2017.
//

#include "search.h"
#include <stdio.h>
#include <stdlib.h>

int line_find(int *anArray, int aSize, int aKey)
{
    int theResult = -1;

    for (int i = 0; i < aSize; i++)
    {
        if (*(anArray+i) == aKey)
        {
            theResult = i;
            break;
        }
    }

    return theResult;
}

int binary_find(int *anArray, int aSize, int aKey)
{
    int theResult = -1;
    int theLowerBound = 0;
    int theUpperBound = aSize-1;
    int theCurIn = 0;

    while (1)
    {
        theCurIn = (theLowerBound + theUpperBound) / 2;
        if (*(anArray+theCurIn) == aKey) //<!- an element was found
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
            if (*(anArray+theCurIn) < aKey)
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

//get key
int getKey()
{
    printf("Please enter int from 0 till 10000 which you want to find in this array\n");

    int aKey=0;
    int repair=0;
    do
    {
        repair=scanf("%i", &aKey);
        if (aKey>10000 || aKey<0 || repair!=1)
        {
            printf("ERROR. Please enter int from 0 till 10000 which you want to find in this array\n");
        }
        fflush(stdin);
    }while(aKey>10000 || aKey<0 || repair!=1);

    return aKey;
}

//print search result
void printSearchResult(double *timeSearch, int searchPosition)
{
    if(searchPosition==-1)
    {
        printf("Your numb has not been found in array\n");
    }
    else
    {
        printf("Your numb has been found in array for %lf sec on %i position\n", *timeSearch, searchPosition);
    }
}