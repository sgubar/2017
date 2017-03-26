//
// Created by Oleh on 26.03.2017.
//

#include "sort.h"

//bubble sort
void bubbleSort(circleList *aCircleList)
{
    for (int theOut = aCircleList->current_size; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if ((aCircleList->sizeCircle[theIn].radius) > (aCircleList->sizeCircle[theIn+1].radius))
            {
                circle tmp=aCircleList->sizeCircle[theIn];
                aCircleList->sizeCircle[theIn]=aCircleList->sizeCircle[theIn+1];
                aCircleList->sizeCircle[theIn+1]=tmp;
            }
        }
    }

}

//selection sort
void selectionSort(circleList *aCircleList)
{

    for (int theOut = 0; theOut < aCircleList->current_size; theOut ++)
    {
        int theMinIndex = theOut;

        for (int theIn = theOut + 1; theIn <= aCircleList->current_size; theIn ++)
        {
            if ((aCircleList->sizeCircle[theIn].radius) < (aCircleList->sizeCircle[theMinIndex].radius))
            {
                theMinIndex = theIn;
            }
        }
        circle tmp=aCircleList->sizeCircle[theOut];
        aCircleList->sizeCircle[theOut]=aCircleList->sizeCircle[theMinIndex];
        aCircleList->sizeCircle[theMinIndex]=tmp;
    }

}

//insertion sort
void insertionSort(circleList *aCircleList)
{
    for (int theOut = 1; theOut <= aCircleList->current_size; theOut ++)
    {
        float theTmpRadius = aCircleList->sizeCircle[theOut].radius;
        circle theTmpCircle = (aCircleList->sizeCircle[theOut]);
        int theIn = theOut;

        while (theIn > 0 && (aCircleList->sizeCircle[theIn-1].radius) >= theTmpRadius)
        {
            (aCircleList->sizeCircle[theIn]) = (aCircleList->sizeCircle[theIn-1]);
            -- theIn;
        }

        aCircleList->sizeCircle[theIn].radius = theTmpRadius;
        aCircleList->sizeCircle[theIn] = theTmpCircle;

    }
}
