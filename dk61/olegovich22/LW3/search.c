//
// Created by Oleh on 10.04.2017.
//

#include "search.h"


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