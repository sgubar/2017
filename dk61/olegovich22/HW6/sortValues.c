//
// Created by Oleg on 03.05.2017.
//

#include "dk_list.h"
#include "sortValues.h"
#include <stdio.h>

//declarations
void swapValues(intList *aList, int index1, int index2);

int partitionItV(intList *aList, int aLeftIndex, int aRightIndex, int aPivot);
int medianaV(intList *aList, int aLeftIndex, int aRightIndex);
void m_manualSortV(intList *aList, int aLeftIndex, int aRightIndex);

//shell sort
void shellSortValues(intList *aList)
{
    if(aList==NULL || aList->count<2)
    {
        printf("List is empty or has less than two elements. Impossible to sort.\n");
        return;
    }
    int theInner = 0;
    int theOuter = 0;
    int theH = 1; // start h = 1

    //1. Calculate start value of h
    while (theH <= aList->count/3)
    {
        theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
    }

    //2. Sequental decrease h to 1
    while (theH > 0)
    {
        for (theOuter = theH; theOuter < aList->count; theOuter ++)
        {
            int theTmp = intValueAtIndex(aList, theOuter);
            theInner = theOuter;

            // the first sub-array {0, 4, 8}
            while (theInner > theH-1 && intValueAtIndex(aList, theInner - theH) >= theTmp)
            {
                // anArray[theInner] = anArray[theInner - theH];

                intNode *node1=intNodeAtIndex(aList, theInner);
                intNode *node2=intNodeAtIndex(aList, theInner-theH);
                node1->value=node2->value;

                theInner -= theH;
            }
            intNode *node1=intNodeAtIndex(aList, theInner);
            node1->value = theTmp;
        }

        theH = (theH - 1) / 3; //decrease h
    }
}

//quick sort
void quickSortValues(intList *aList, int aLeftIndex, int aRightIndex)
{
    if(aList==NULL || aList->count<2)
    {
        printf("List is empty or has less than two elements. Impossible to sort.\n");
        return;
    }
    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 3)
    {
        m_manualSortV(aList, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot = medianaV(aList, aLeftIndex, aRightIndex);
        int thePartitionIndex = partitionItV(aList, aLeftIndex, aRightIndex, thePivot);
        //left part sorting
        quickSortValues(aList, aLeftIndex, thePartitionIndex-1);
        //right part sorting
        quickSortValues(aList, thePartitionIndex, aRightIndex);
    }

}

//help function for quicksort
int partitionItV(intList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex;
    int theRight = aRightIndex ;
    while (1)
    {
        // search the bigest element

        while (intValueAtIndex(aList, theLeft) < aPivot)
        {
            theLeft++;
        }

        // search the lowest element
        while (intValueAtIndex(aList, theRight) > aPivot)
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
            swapValues(aList, theLeft, theRight);
            theLeft++;
            theRight--;
        }
    }

    return theLeft; // return break position
}

int medianaV(intList *aList, int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;

    if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, theCenter))
    {
        swapValues(aList, aLeftIndex, theCenter);
    }

    if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex))
    {
        swapValues(aList, aLeftIndex, aRightIndex);
    }

    if (intValueAtIndex(aList, theCenter) > intValueAtIndex(aList, aRightIndex))
    {
        swapValues(aList, theCenter, aRightIndex);
    }

    swapValues(aList, theCenter, aRightIndex - 1);

    return intValueAtIndex(aList, aRightIndex - 1);
}

void m_manualSortV(intList *aList, int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 1)
    {
        return;
    }

    if (2 == theSize)
    {
        if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex))
        {
            swapValues(aList, aLeftIndex, aRightIndex);
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex - 1))
        {
            swapValues(aList, aLeftIndex, aRightIndex - 1);
        }

        if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex))
        {
            swapValues(aList, aLeftIndex, aRightIndex);
        }

        if (intValueAtIndex(aList, aRightIndex - 1) > intValueAtIndex(aList, aRightIndex))
        {
            swapValues(aList, aRightIndex - 1, aRightIndex);
        }
    }
}

void swapValues(intList *aList, int index1, int index2)
{
    intNode *node1=intNodeAtIndex(aList, index1);
    intNode *node2=intNodeAtIndex(aList, index2);

    int tmp=node1->value;
    node1->value=node2->value;
    node2->value=tmp;
}