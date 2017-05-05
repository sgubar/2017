//
// Created by Oleh on 26.03.2017.
//
#include "sortPointers.h"
#include "dk_list.h"
#include <stdio.h>
#include <stdlib.h>

//declaration function
void swapNodes(intList *aList, int index1, int index2);

int partitionIt(intList *aList, int aLeftIndex, int aRightIndex, int aPivot);
int mediana(intList *aList, int aLeftIndex, int aRightIndex);
void m_manualSort(intList *aList, int aLeftIndex, int aRightIndex);


//shell sort
void shellSortPointers(intList *aList)
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
                swapNodes(aList, theInner, theInner - theH);
                theInner -= theH;
            }
        }

        theH = (theH - 1) / 3; //decrease h
    }
}

//quick sort
void quickSortPointers(intList *aList, int aLeftIndex, int aRightIndex)
{
    if(aList==NULL || aList->count<2)
    {
        printf("List is empty or has less than two elements. Impossible to sort.\n");
        return;
    }
    int theSize = aRightIndex - aLeftIndex + 1;

    if (theSize <= 3)
    {
        m_manualSort(aList, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot = mediana(aList, aLeftIndex, aRightIndex);
        int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
        //left part sorting
        quickSortPointers(aList, aLeftIndex, thePartitionIndex-1);
        //right part sorting
        quickSortPointers(aList, thePartitionIndex, aRightIndex);
    }

}

//help function for quicksort
int partitionIt(intList *aList, int aLeftIndex, int aRightIndex, int aPivot)
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
            swapNodes(aList, theLeft, theRight);
            theLeft++;
            theRight--;
        }
    }

    return theLeft; // return break position
}

int mediana(intList *aList, int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;

    if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, theCenter))
    {
        swapNodes(aList, aLeftIndex, theCenter);
    }

    if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex))
    {
        swapNodes(aList, aLeftIndex, aRightIndex);
    }

    if (intValueAtIndex(aList, theCenter) > intValueAtIndex(aList, aRightIndex))
    {
        swapNodes(aList, theCenter, aRightIndex);
    }

    swapNodes(aList, theCenter, aRightIndex - 1);

    return intValueAtIndex(aList, aRightIndex - 1);
}

void m_manualSort(intList *aList, int aLeftIndex, int aRightIndex)
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
            swapNodes(aList, aLeftIndex, aRightIndex);
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex - 1))
        {
            swapNodes(aList, aLeftIndex, aRightIndex - 1);
        }

        if (intValueAtIndex(aList, aLeftIndex) > intValueAtIndex(aList, aRightIndex))
        {
            swapNodes(aList, aLeftIndex, aRightIndex);
        }

        if (intValueAtIndex(aList, aRightIndex - 1) > intValueAtIndex(aList, aRightIndex))
        {
            swapNodes(aList, aRightIndex - 1, aRightIndex);
        }
    }
}

//swap function
void swapNodes(intList *aList, int index1, int index2)
{
    if(index1>index2)
    {
        int tmp=index1;
        index1=index2;
        index2=tmp;
    }

    intNode *node1=intNodeAtIndex(aList, index1);
    intNode *node2=intNodeAtIndex(aList, index2);
    intNode *theTmpPrev=node1->prev;
    intNode *theTmpNext=node1->next;

    //save tmp pointers
    //theTmp->prev=node1->prev;
    //theTmp->next=node1->next;

    int cheker=index1-index2;
    if(cheker==-1)
    {
        node1->next=node1->next->next;

        if(index2!=aList->count-1)
            node2->next->prev=node1;

        node2->next=node1;
        node1->prev=node2;

        if(index1!=0)
            theTmpPrev->next=node2;

        node2->prev=theTmpPrev;
    }
    else
    {
        //change pointers node1
        if(index2!=0)
            node2->prev->next=node1;

        node1->prev=node2->prev;
        node1->next=node2->next;

        if(aList->count-1!=index2)
            node2->next->prev=node1;

        //change pointers node2 from tmp pointers
        if(index1!=0)
            theTmpPrev->next=node2;

        node2->prev=theTmpPrev;
        node2->next=theTmpNext;

        if(index1!=aList->count-1)
            theTmpNext->prev=node2;

    }
    //free(theTmp);

    if(index1==0)
    {
        aList->head=node2;
    }
    if(index2==0)
    {
        aList->head=node1;
    }
    if(index1==aList->count-1)
    {
        aList->tail=node2;
    }
    if(index2==aList->count-1)
    {
        aList->tail=node1;
    }

}



