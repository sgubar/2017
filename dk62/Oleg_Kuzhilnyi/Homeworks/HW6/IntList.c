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



void quickSort(CharList anArray[], int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }
    
    char thePivot = TLIntValueAtIndex(anArray,aRightIndex);
    int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
    
    //left part sorting
    quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
    
    //right part sorting
    quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}

int partitionIt(CharList anArray[], int aLeftIndex, int aRightIndex, char aPivot)
{
    char theLeft = aLeftIndex - 1;
    char theRight = aRightIndex;

    while (1)
    {
        // search the bigest element
        while (TLIntValueAtIndex(anArray,++theLeft) < aPivot);
        
        // search the lowest element
        while (theRight > 0 && TLIntValueAtIndex(anArray,--theRight) > aPivot);
        
        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
        else
        {
            //lets to swap elements
            CharNode *theNode = theNode->next;

            char theTmp = theNode->value;
            theNode->value = theNode->next->value;
            theNode->next->value = theTmp;
            
            /*
            char theTmp = anArray->value[theLeft];
            anArray->value[theLeft] = anArray->value[theRight];
            anArray->value[theRight] = theTmp;
             */
        }
    }
    CharNode *theNode = theNode->next;

    //lets to swap elements
    char theTmp = theNode->value;
    theNode->value = theNode->next->value;
    theNode->next->value = theTmp;
    
    
    return theLeft; // return break position
}

