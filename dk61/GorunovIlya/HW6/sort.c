#include <stdio.h>
#include "TLFloat.h"
#include "sort.h"
//void swap(FloatList *aList, int firstIndex, int secondIndex);



void shellSort(FloatList *aList)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 
	
	
	while (theH <= aList->count / 3)
	{
		theH = theH * 3 + 1;
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aList->count; theOuter ++)
		{
			float theTmp = TLFloatValueAtIndex(aList, theOuter);
			theInner = theOuter;
		
			
			while (theInner > theH - 1 && TLFloatValueAtIndex(aList, theInner - theH) <= theTmp)
			{
				swap(aList, theInner, theInner - theH);
				theInner -= theH;
			}
		
			//aNode->value[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; 
	}
}


void swap(FloatList *aList, int firstIndex, int secondIndex)
{
    if(firstIndex > secondIndex)
    {
        int tmp = firstIndex;
        firstIndex = secondIndex;
        secondIndex = tmp;
    }

    FloatNode *firstNode = FindFloatValueAtIndex(aList, firstIndex);
    FloatNode *secondNode = FindFloatValueAtIndex(aList, secondIndex);
    
    FloatNode *theTmpPrev = firstNode->prev;
    FloatNode *theTmpNext = firstNode->next;

    
    if(firstIndex - secondIndex == -1)
    {
        firstNode->next = firstNode->next->next;

        if(secondIndex != aList->count - 1)
        {
            secondNode->next->prev = firstNode;
        }

        secondNode->next = firstNode;
        firstNode->prev = secondNode;

        if(firstIndex != 0)
        {
            theTmpPrev->next = secondNode;
        }

        secondNode->prev = theTmpPrev;
    }
    else
    {
        
        if( secondIndex != 0)
        {
            secondNode->prev->next = firstNode;
        }

        firstNode->prev = secondNode->prev;
        firstNode->next = secondNode->next;

        if(aList->count-1 != secondIndex)
        {
            secondNode->next->prev = firstNode;
        }

        
        if(firstIndex != 0)
        {
            theTmpPrev->next = secondNode;
        }

        secondNode->prev = theTmpPrev;
        secondNode->next=theTmpNext;

        if(firstIndex != aList->count - 1)
        { 
		    theTmpNext->prev = secondNode;
		}

    }
    if(firstIndex == 0)
    {
        aList->head = secondNode;
    }
    if(secondIndex == 0)
    {
        aList->head = firstNode;
    }
    if(firstIndex == aList->count - 1)
    {
        aList->tail = secondNode;
    }
    if(secondIndex == aList->count - 1)
    {
        aList->tail= firstNode;
    }

 }

