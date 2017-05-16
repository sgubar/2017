#include "TLCharList.h"
#include "SortingList.h"
#include "DoCreateDestroyList.h"


void bubbleSort(CharList *anArray)
{
    CharNode *TheNodeList = anArray->head;
    
    for (CharNode *theOut = TheNodeList; theOut ; theOut = theOut->next)
        for (CharNode *theIn = TheNodeList; theIn; theIn = theIn->next)
        {
            if (theOut->value < theIn->value)
            {
                char thetmp = theOut->value ;
                theOut->value = theIn->value;
                theIn->value = thetmp;
            }
            
        }
}


void quickSort(CharList *aList, int aLeftIndex, int aRightIndex)
{
    if(aList==NULL || aList->count <  2)
    {
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
        quickSort(aList, aLeftIndex, thePartitionIndex-1);
        //right part sorting
        quickSort(aList, thePartitionIndex, aRightIndex);
    }
    
}



int mediana(CharList *aList, int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;
    
    if (FindCharElementAtIndex(aList, aLeftIndex) > FindCharElementAtIndex(aList, theCenter))
    {
        swap(aList, aLeftIndex, theCenter);
    }
    
    if (FindCharElementAtIndex(aList, aLeftIndex) > FindCharElementAtIndex(aList, aRightIndex))
    {
        swap(aList, aLeftIndex, aRightIndex);
    }
    
    if (FindCharElementAtIndex(aList, theCenter) > FindCharElementAtIndex(aList, aRightIndex))
    {
        swap(aList, theCenter, aRightIndex);
    }
    
    swap(aList, theCenter, aRightIndex - 1);
    
    return FindCharElementAtIndex(aList, aRightIndex - 1);
}

int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex;
    int theRight = aRightIndex ;
    while (1)
    {
        // search the bigest element
        
        while (FindCharElementAtIndex(aList, theLeft) < aPivot)
        {
            theLeft++;
        }
        
        // search the lowest element
        while (FindCharElementAtIndex(aList, theRight) > aPivot)
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
            swap(aList, theLeft, theRight);
            theLeft++;
            theRight--;
        }
    }
    
    return theLeft; // return break position
}



void m_manualSort(CharList *aList, int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;
    
    if (theSize <= 1)
    {
        return;
    }
    
    if (2 == theSize)
    {
        if (FindCharElementAtIndex(aList, aLeftIndex) > FindCharElementAtIndex(aList, aRightIndex))
        {
            swap(aList, aLeftIndex, aRightIndex);
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (FindCharElementAtIndex(aList, aLeftIndex) > FindCharElementAtIndex(aList, aRightIndex - 1))
        {
            swap(aList, aLeftIndex, aRightIndex - 1);
        }
        
        if (FindCharElementAtIndex(aList, aLeftIndex) > FindCharElementAtIndex(aList, aRightIndex))
        {
            swap(aList, aLeftIndex, aRightIndex);
        }
        
        if (FindCharElementAtIndex(aList, aRightIndex - 1) > FindCharElementAtIndex(aList, aRightIndex))
        {
            swap(aList, aRightIndex - 1, aRightIndex);
        }
    }
}


void swap(CharList *aList, int FirstIndex, int SecondIndex)
{
    if(FirstIndex > SecondIndex)
    {
        int tmp = FirstIndex;
        FirstIndex = SecondIndex;
        SecondIndex = tmp;
    }
    
    CharNode *TheNodeAnFirstIndex = FindNodeAtIndex(aList, FirstIndex);
    CharNode *TheNodeAnSecondIndex = FindNodeAtIndex(aList, SecondIndex);
    
    
    CharNode *theTmpPrev = TheNodeAnFirstIndex->prev;
    CharNode *theTmpNext = TheNodeAnFirstIndex->next;
    
    
    
    if(FirstIndex-SecondIndex == -1)
    {
        TheNodeAnFirstIndex->next=TheNodeAnFirstIndex->next->next;
        
        if(SecondIndex != aList->count-1)
            TheNodeAnSecondIndex->next->prev=TheNodeAnFirstIndex;
        
        TheNodeAnSecondIndex->next=TheNodeAnFirstIndex;
        TheNodeAnFirstIndex->prev = TheNodeAnSecondIndex;
        
        if(FirstIndex != 0)
            theTmpPrev->next = TheNodeAnSecondIndex;
        
        TheNodeAnSecondIndex->prev=theTmpPrev;
    }
    else
    {
        if(SecondIndex !=0)
            
            TheNodeAnSecondIndex->prev->next = TheNodeAnFirstIndex;
        
        TheNodeAnFirstIndex->prev = TheNodeAnSecondIndex->prev;
        TheNodeAnFirstIndex->next = TheNodeAnSecondIndex->next;
        
        if(aList->count-1 != SecondIndex)
            TheNodeAnSecondIndex->next->prev = TheNodeAnFirstIndex;
        
        if(FirstIndex !=0)
            theTmpPrev->next=TheNodeAnSecondIndex;
        
        TheNodeAnSecondIndex->prev = theTmpPrev;
        TheNodeAnSecondIndex->next = theTmpNext;
        
        if(FirstIndex != aList->count-1)
            theTmpNext->prev=TheNodeAnSecondIndex;
        
    }
    
    if(FirstIndex==0)
    {
        aList->head=TheNodeAnSecondIndex;
    }
    if(SecondIndex==0)
    {
        aList->head=TheNodeAnFirstIndex;
    }
    if(FirstIndex==aList->count-1)
    {
        aList->tail=TheNodeAnSecondIndex;
    }
    if(SecondIndex==aList->count-1)
    {
        aList->tail=TheNodeAnFirstIndex;
    }
    
}
