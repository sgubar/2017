//
// Created by Oleh on 26.03.2017.
//
#include "sort.h"
#include <stdio.h>

//declaration function
void swap(circle *aCircle1, circle *aCircle2);
int partitionIt(circle *aCircle, int aLeftIndex, int aRightIndex, float aPivot);
float mediana(circle *aCircle, int aLeftIndex, int aRightIndex);
void m_manualSort(circle *aCircle, int aLeftIndex, int aRightIndex);

//shell sort
void shellSort(circleList *aCirclelist)
{
    int theInner = 0;
    int theOuter = 0;
    int theH = 1; // start h = 1

    //1. Calculate start value of h
    while (theH <= aCirclelist->current_size/3)
    {
        theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
    }

    //2. Sequental decrease h to 1
    while (theH > 0)
    {
        for (theOuter = theH; theOuter < aCirclelist->current_size; theOuter ++)
        {
            //int theTmp = *(anArray+theOuter);
            float theTmp = aCirclelist->sizeCircle[theOuter].radius;
            circle theTmpCircle = aCirclelist->sizeCircle[theOuter];
            theInner = theOuter;

            // the first sub-array {0, 4, 8}
            while (theInner > theH-1 && aCirclelist->sizeCircle[theInner - theH].radius >= theTmp)
            {
                aCirclelist->sizeCircle[theInner]=aCirclelist->sizeCircle[theInner-theH];
                theInner -= theH;
            }

            aCirclelist->sizeCircle[theInner].radius = theTmp;
            aCirclelist->sizeCircle[theInner]=theTmpCircle;
        }

        theH = (theH - 1) / 3; //decrease h
    }
}

//quick sort
void quickSort(circleList *aCirclelist, int aLeftIndex, int aRightIndex)
{

    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 3)
    {
        m_manualSort(aCirclelist->sizeCircle, aLeftIndex, aRightIndex);
    }
    else
    {
        float thePivot = mediana(aCirclelist->sizeCircle, aLeftIndex, aRightIndex);
        int thePartitionIndex = partitionIt(aCirclelist->sizeCircle, aLeftIndex, aRightIndex, thePivot);
        //left part sorting
        quickSort(aCirclelist, aLeftIndex, thePartitionIndex);
        //right part sorting
        quickSort(aCirclelist, thePartitionIndex, aRightIndex);
    }

}

//help function for quicksort
int partitionIt(circle *aCircle, int aLeftIndex, int aRightIndex, float aPivot)
{
    int theLeft = aLeftIndex;
    int theRight = aRightIndex ;
    while (1)
    {
        // search the bigest element

        while (aCircle[theLeft].radius < aPivot)
        {
            theLeft++;
        }

        // search the lowest element
        while (aCircle[theRight].radius > aPivot)
        {
            theRight--;
        }

        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            swap(&aCircle[theLeft], &aCircle[theRight]);
            theLeft++;
            theRight--;
        }
    }

    return theLeft; // return break position
}

float mediana(circle *aCircle, int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;

    if (aCircle[aLeftIndex].radius > aCircle[theCenter].radius)
    {
        swap(&aCircle[aLeftIndex], &aCircle[theCenter]);
    }

    if (aCircle[aLeftIndex].radius > aCircle[aRightIndex].radius)
    {
        swap(&aCircle[aLeftIndex], &aCircle[aRightIndex]);
    }

    if (aCircle[theCenter].radius > aCircle[aRightIndex].radius)
    {
        swap(&aCircle[theCenter], &aCircle[aRightIndex]);
    }

    swap(&aCircle[theCenter], &aCircle[aRightIndex-1]);

    return aCircle[aRightIndex-1].radius;
}

void m_manualSort(circle *aCircle, int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 1)
    {
        return;
    }

    if (2 == theSize)
    {
        if (aCircle[aLeftIndex].radius > aCircle[aRightIndex].radius)
        {
            swap(&aCircle[aLeftIndex], &aCircle[aRightIndex]);
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (aCircle[aLeftIndex].radius > aCircle[aRightIndex-1].radius)
        {
            swap(&aCircle[aLeftIndex], &aCircle[aRightIndex-1]);
        }

        if (aCircle[aLeftIndex].radius > aCircle[aLeftIndex].radius)
        {
            swap(&aCircle[aLeftIndex], &aCircle[aRightIndex-1]);
        }

        if (aCircle[aRightIndex-1].radius > aCircle[aRightIndex].radius)
        {
            swap(&aCircle[aRightIndex-1], &aCircle[aLeftIndex]);
        }
    }
}

//swap function
void swap(circle *aCircle1, circle *aCircle2)
{
    circle temp=*aCircle1;
    *aCircle1=*aCircle2;
    *aCircle2=temp;
}

//get users choice type of sort from user
int getTypeOfSort()
{
    int numb=0;
    printf("\nPlease do a choice type of sorting:\n");
    printf("Enter 1 - shell sorting\n");
    printf("Enter 2 - quick sorting\n");
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