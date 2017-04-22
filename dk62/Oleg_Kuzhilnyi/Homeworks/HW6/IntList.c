//
//  TLIntList.c
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "TLIntList.h"
#include <limits.h>
#include <stdlib.h>

static CharNode *createCharNodeWithSymbol(char anCharSymbol);

#pragma mark -
CharList *TLCreateCharList()
{
	CharList *theList = (CharList *)malloc(sizeof(CharList));
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void TLDestroyIntList(CharList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		CharNode *theNode = aList->head;
	
		do
		{
			CharNode *theNodeToDelete = theNode;
			theNode = theNode->next;
		
			free (theNodeToDelete);
		
		}while (NULL != theNode);
	
		free(aList);
	}
}

int TLAddCharSymbolToList(CharList *aList, char *anCharSymbol)
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		CharNode *theNode = createCharNodeWithSymbol(*anCharSymbol);
	
		if (NULL != theNode)
		{
			// lets to add to the end of the list
			//1. The list is empty
			if (NULL == aList->head && aList->head == aList->tail)
			{
				aList->head = aList->tail = theNode;
			}
			else
			{
				// (head) a b c (tail) + d -> (head)a b c=>d (tail)
				CharNode *theTail = aList->tail;
                
				aList->tail = theNode;
				theTail->next = theNode;
                
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	
	return theResult;
}


int TLIntValueAtIndex(CharList *aList, int anIndex)
{
	int theResult = INT_MAX;
	
	if (NULL == aList || anIndex >= aList->count)
	{
		return theResult;
	}
	
	CharNode *theNode = aList->head;
	int i = 1;
	
	do
	{
		if (i == anIndex)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (NULL != theNode);
	
	return theNode->value;
}

// print list
void TLPrintList(CharList *aList)
{
    if(aList->count == 0)
    {
        puts("The list is empty"); return;
    }
    
        printf("[List] with count (%d):", aList->count);
        CharNode *theNode = aList->head;
        
        do
        {
            
		printf("(%c) ", theNode->value);
		theNode = theNode->next;
            
        }while (NULL != theNode);
	
        printf ("\n");

}

int TLInsertCharSymbolAtIndex(CharList *aList, char *anCharValue, int anIndex)
{

	int theResult = -1;
	
	if (NULL == aList || anIndex > aList->count || anIndex < 0)
	{
		return theResult;
	}
	
    CharNode *theNode = aList->head;
	int i = 1;

	do
	{
		if (i == anIndex)
		{
			break;
		}
	
        theNode = theNode->next;
		i++;
	
	}while (NULL != theNode);
	    
	CharNode *theNewNode = createCharNodeWithSymbol(*anCharValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
    CharNode *theBNode = theNode;
    
    if(anIndex == 0)
    {
        theNewNode->next = aList->head;
        aList->head = theNewNode;
        
    }else if(NULL != theBNode->next)
        
    {
        
        theNewNode->next = theBNode->next;
        theBNode->next = theNewNode;
        
    } else {

        CharNode *theTail = aList->tail;
        aList->tail = theNewNode;
        theTail->next = theNewNode;
    }
    
	aList->count ++;
	theResult = 0;
	
	return theResult;
}


int LT_ExtractCharNode(CharList *aList,int anIndex)
{
    int theResult = -1;
    
    if (NULL == aList || anIndex >= aList->count || anIndex < 0)
    {
        return theResult;
    }
    
    CharNode *theNode = aList->head;
    int i = 1;
    
    do
    {
        if (i == anIndex)
        {
            break;
        }
        
    theNode = theNode->next;
    i++;
        
    }while (NULL != theNode);

        if(anIndex == 0)
        {
            theNode = aList->head;
            CharNode *theBNode = theNode;
            aList->head = theBNode->next;
            
            
        }else if(aList->count-1 == anIndex)
        {
            theNode->next = NULL;
            
        }else if(NULL != theNode)
            
        {
          theNode->next = theNode->next->next;
          theNode = NULL;
       
      }
    
    aList->count --;
    theResult = 0;
    
    return theResult;
}

#pragma mark -
#pragma mark IntNode interface
CharNode *createCharNodeWithSymbol(char CharSymbol)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->value = CharSymbol;
	}
	
	return theNode;
}
/*
void bubbleSort(CharList *anArray)
{
    CharList *anArray = NULL;
    
    for (int theOut = aSize - 1; theOut > 1; theOut --)
    {
        for (int theIn = 0; theIn < theOut; theIn ++)
        {
            if (anArray[theIn] > anArray[theIn + 1])
            {
                int theTmp = anArray[theIn];
                anArray[theIn] = anArray[theIn + 1];
                anArray[theIn + 1] = theTmp;
            }
        }
    }
}
 */
/*
int mediana(int anArray[], int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;
    
    if (anArray[aLeftIndex] > anArray[theCenter])
    {
        swap(anArray, aLeftIndex, theCenter);
    }
    
    if (anArray[aLeftIndex] > anArray[aRightIndex])
    {
        swap(anArray, aLeftIndex, aRightIndex);
    }
    
    if (anArray[theCenter] > anArray[aRightIndex])
    {
        swap(anArray, theCenter, aRightIndex);
    }
    
    swap(anArray, theCenter, aRightIndex - 1);
    
    return anArray[aRightIndex - 1];
}
int m_partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex;
    int theRight = aRightIndex - 1;
    
    while (1)
    {
        // search the bigest element
        while (anArray[++theLeft] < aPivot);
        
        // search the lowest element
        while (anArray[--theRight] > aPivot);
        
        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            swap(anArray, theLeft, theRight);
        }
    }
    
    //lets to swap elements
    swap(anArray, theLeft, aRightIndex - 1);
    
    return theLeft; // return break position
}

void quickSort(CharList anArray[], CharList aLeftIndex, CharList aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;
    
    if (theSize <= 3)
    {
        m_manualSort(anArray, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
        int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
        
        //left part sorting
        quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
        
        //right part sorting
        quickSort(anArray, thePartitionIndex + 1, aRightIndex);
    }
}

void m_manualSort(int anArray[], int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;
    
    if (theSize <= 1)
    {
        return;
    }
    
    if (2 == theSize)
    {
        if (anArray[aLeftIndex] > anArray[aRightIndex])
        {
            swap(anArray, aLeftIndex, aRightIndex);
        }
        return ;
    }
    else
    {
        // 3 elementes
        if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
        {
            swap(anArray, aLeftIndex, aRightIndex - 1);
        }
        
        if (anArray[aLeftIndex] > anArray[aRightIndex])
        {
            swap(anArray, aLeftIndex, aRightIndex);
        }
        
        if (anArray[aRightIndex - 1] > anArray[aRightIndex])
        {
            swap(anArray, aRightIndex - 1, aRightIndex);
        }
    }
}

void swap(CharList *anArray, CharNode aLeftIndex, CharNode aRightIndex)
{
    CharNode theTmp = anArray-> [aLeftIndex];
    anArray[aLeftIndex] = anArray[aRightIndex];
    anArray[aRightIndex] = theTmp;
}
*/
