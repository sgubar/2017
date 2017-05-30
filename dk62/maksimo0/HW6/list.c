//
// Created by Max on 29.05.2017.
//

#include "list.h"
#include <stdlib.h>

IntNode *createIntNodeWithValue(int anIntValue)
{
    IntNode *theNode=(IntNode *)malloc(sizeof(IntNode));
    if(NULL!=theNode)
    {
        theNode->next=NULL;
        theNode->prev=NULL;
        theNode->value=anIntValue;
    }
    return theNode;
}

IntList *CreateIntList()
{
    IntList *theList=(IntList *)malloc(sizeof(IntList));
    if(NULL!=theList)
    {
        theList->head=NULL;
        theList->tail=NULL;
        theList->count=0;
    }
    return theList;
}

void DestroyIntList(IntList *aList)
{
    if(NULL==aList)
    {
        return;
    }
    if (NULL!=aList->tail&&NULL!=aList->head)
    {
        IntNode *theNode = aList->head;
        do
        {
            IntNode *theNodeToDelete=theNode;
            theNode=theNode->next;
            free(theNodeToDelete);

        }while(NULL!=theNode);
        free(aList);
    }
}

int AddIntValueToList(IntList *aList, int anIntValue)
{
    int theResult=-1;
    if(NULL!=aList)
    {
        IntNode *theNode=createIntNodeWithValue(anIntValue);
        if(NULL!=theNode)
        {
            if(NULL==aList->head&&aList->head==aList->tail)
            {
                aList->head=aList->tail=theNode;
            }
            else
            {
                IntNode *theTail=aList->tail;
                aList->tail=theNode;
                theTail->next=theNode;
                theNode->prev=theTail;
            }
            aList->count++;
            theResult=0;
        }
    }
    return theResult;
}

IntNode *IntValueAtIndex(IntList *aList, int anIndex)
{
    IntNode *theResult=NULL;
    if(NULL==aList||anIndex>=aList->count)
    {
        IntNode *theNode=aList->head;
        int i=0;
        do
        {
            if(i==anIndex)
            {
                theResult=theNode;
                break;
            }
            i++;
            theNode=theNode->next;
        }while(NULL!=theNode);
    }
    return theResult;
}

void PrintList(IntList *aList)
{
    printf("[List] with count (%d):", aList->count);
    IntNode *theNode=aList->head;
    do
    {
        printf("(%d) ", theNode->value);
        theNode=theNode->next;

    }while(NULL!= theNode);
    printf ("\n");
}

int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{
    int theResult=-1;
    if (NULL==aList||anIndex>=aList->count||anIndex<0)
    {
        return theResult;
    }
    IntNode *theNode=aList->head;
    int i=0;
    do
    {
        if (i==anIndex)
        {
            break;
        }

        theNode=theNode->next;
        i++;

    }while(NULL!=theNode);
    IntNode *theNewNode=createIntNodeWithValue(anIntValue);
    if(NULL==theNewNode)
    {
        return theResult;
    }
    IntNode *theBNode=theNode;
    if (NULL!=theBNode->prev)
    {
        theBNode->prev->next=theNewNode;
        theNewNode->prev=theBNode->prev;
    }
    theNewNode->next=theBNode;
    theBNode->prev=theNewNode;
    aList->count++;
    theResult=0;
    return theResult;
}

void DeleteIntValueAtIndex(IntList *aList, int anIndex)
{
    if (NULL!=aList&&anIndex<aList->count)
    {
        int i=0;
        IntNode *theNode=aList->head;
        do
        {
            if(i==anIndex)
            {
                IntNode *PrevNode=theNode->prev;
                IntNode *NextNode=theNode->next;
                if(NULL!=PrevNode)
                {
                    PrevNode->next=NextNode;
                }
                else
                {
                    aList->head=NextNode;
                    NextNode->prev=NULL;
                }
                if(NULL!=NextNode)
                {
                    NextNode->prev=PrevNode;
                }
                else
                {
                    aList->tail=PrevNode;
                    PrevNode->next=NULL;
                }
                free(theNode);
                break;
            }
            i++;
            theNode=theNode->next;
        }while(NULL!=theNode);
        aList->count-=1;
    }
}

void quickSort(IntList *aList, int aLeftIndex, int aRightIndex)
{
    int theSize=aRightIndex-aLeftIndex+1;
    if(theSize<=3)
    {
        m_manualSort(aList, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot=mediana(aList, aLeftIndex, aRightIndex);
        int thePartitionIndex=m_partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
        quickSort(aList, aLeftIndex, thePartitionIndex-1);
        quickSort(aList, thePartitionIndex+1, aRightIndex);
    }
}

void m_manualSort(IntList *aList, int aLeftIndex, int aRightIndex)
{
    int theSize=aRightIndex-aLeftIndex+1;
    if(theSize<=1)
    {
        return;
    }
    if(2==theSize)
    {
        IntNode *theLeftNode=IntValueAtIndex(aList, aLeftIndex);
        IntNode *theRightNode=IntValueAtIndex(aList, aRightIndex);
        if(theLeftNode->value>theRightNode->value)
        {
            swap(aList, aLeftIndex, aRightIndex);
        }
        return ;
    }
    else
    {
        IntNode *theLeftNode=IntValueAtIndex(aList, aLeftIndex);
        IntNode *theRightNode=IntValueAtIndex(aList, aRightIndex-1);
        if(theLeftNode->value>theRightNode->value)
        {
            swap(aList, aLeftIndex, aRightIndex - 1);
        }
        theLeftNode=IntValueAtIndex(aList, aLeftIndex);
        theRightNode=IntValueAtIndex(aList, aRightIndex);
        if(theLeftNode->value>theRightNode->value)
        {
            swap(aList, aLeftIndex, aRightIndex);
        }
        theLeftNode=IntValueAtIndex(aList, aRightIndex-1);
        theRightNode=IntValueAtIndex(aList, aRightIndex);
        if (theLeftNode->value>theRightNode->value)
        {
            swap(aList, aRightIndex-1, aRightIndex);
        }
    }
}

int mediana(IntList *aList, int aLeftIndex, int aRightIndex)
{
    int theCenter=(aLeftIndex+aRightIndex)/2;
    IntNode *theLeftElement=IntValueAtIndex(aList, aLeftIndex);
    IntNode *theRightElement=IntValueAtIndex(aList, theCenter);
    if(theLeftElement->value>theRightElement->value)
    {
        swap(aList, aLeftIndex, theCenter);
    }
    theLeftElement=IntValueAtIndex(aList, aLeftIndex);
    theRightElement=IntValueAtIndex(aList, aRightIndex);
    if(theLeftElement->value>theRightElement->value)
    {
        swap(aList, aLeftIndex, aRightIndex);
    }
    theLeftElement=IntValueAtIndex(aList, theCenter);
    theRightElement=IntValueAtIndex(aList, aRightIndex);
    if (theLeftElement->value>theRightElement->value)
    {
        swap(aList, theCenter, aRightIndex);
    }
    swap(aList, theCenter, aRightIndex);
    theRightElement=IntValueAtIndex(aList, aRightIndex);
    return theRightElement->value;
}

int m_partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    if(NULL!=aList)
    {
        int theLeft=aLeftIndex;
        int theRight=aRightIndex;
        while(1)
        {
            IntNode *theLeftElement=IntValueAtIndex(aList, theLeft);
            while(theLeftElement->value<aPivot)
            {
                theLeft++;
                theLeftElement=IntValueAtIndex(aList, theLeft);
            }
            IntNode *theRightElement=IntValueAtIndex(aList, theRight);
            while(theRightElement->value>aPivot)
            {
                theRight--;
                theRightElement=IntValueAtIndex(aList, theRight);
            }
            if (theLeft>=theRight)
            {
                break;
            }
            else
            {
                swap(aList, theLeft, theRight);
            }
        }
        return theLeft;
    }
    return 0;
}

void swap(IntList *aList, int aLeftIndex, int aRightIndex)
{
    if (NULL != aList && aRightIndex < aList->count && -1 < aLeftIndex && 0 < (aRightIndex-aLeftIndex) && aRightIndex > aLeftIndex)
    {
        int i = 0;
        IntNode *theLeft = IntValueAtIndex(aList, aLeftIndex);
        IntNode *theRight = IntValueAtIndex(aList, aRightIndex);

        if(NULL != theLeft && NULL != theRight)
        {
            if(1 < (aRightIndex-aLeftIndex))
            {
                IntNode *theNextLeft = theLeft->next;
                IntNode *thePreviousLeft = theLeft->prev;
                IntNode *theNextRight = theRight->next;
                IntNode *thePreviousRight = theRight->prev;

                theNextLeft->prev = theRight;

                if(NULL != thePreviousLeft)
                    thePreviousLeft->next = theRight;

                else
                    aList->head = theRight;

                if(NULL != theNextRight)
                    theNextRight->prev = theLeft;

                else
                    aList->tail = theLeft;

                thePreviousRight->next = theLeft;
                theLeft->prev = thePreviousRight;

                if(NULL != theNextRight)
                    theLeft->next = theNextRight;

                else
                    theLeft->next = NULL;

                if(NULL != thePreviousLeft)
                    theRight->prev = thePreviousLeft;

                else
                    theRight->prev = NULL;

                theRight->next = theNextLeft;

            }

            else
            {
                IntNode *thePreviousLeft = theLeft->prev;
                IntNode *theNextRight = theRight->next;

                if(NULL != thePreviousLeft)
                    thePreviousLeft->next = theRight;

                else
                    aList->head = theRight;

                if(NULL != theNextRight)
                    theNextRight->prev = theLeft;

                else
                    aList->tail = theLeft;
                theLeft->prev = theRight;
                theRight->next = theLeft;

                if(NULL != theNextRight)
                    theLeft->next = theNextRight;

                else
                    theLeft->next = NULL;

                if(NULL != thePreviousLeft)
                    theRight->prev = thePreviousLeft;

                else
                    theRight->prev = NULL;
            }
        }
    }
}


