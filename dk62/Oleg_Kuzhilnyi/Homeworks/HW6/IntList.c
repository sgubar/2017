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


char FindElementAtIndex(CharList *aList, int anIndex)
{
	 char theResult = '\0';
	
	if (NULL == aList || anIndex >= aList->count)
	{
		return theResult;
	}
	
    int i = 0;
	CharNode *theNode = aList->head;
	
	do
	{
		if (i == anIndex)
		{
            theResult = theNode->value;
			break;
		}
	
        i++;
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
    return theResult;
}

CharNode *FindElementAtIndexAndReturnStruct(CharList *aList, int anIndex)
{
    CharNode *theResult = NULL;
    
    if (NULL == aList || anIndex >= aList->count)
    {
        return theResult;
    }
    
    int i = 0;
    CharNode *theNode = aList->head;
    
    do
    {
        if (i == anIndex)
        {
            theResult = theNode;
            break;
        }
        
        i++;
        theNode = theNode->next;
        
    }while (NULL != theNode);
    
    return theResult;
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




int LT_DeleteCharNode(CharList *aList,int anIndex)
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
      
        //aList->head = theNode->next;
        
    }else if(aList->count == anIndex)
    {
        aList->tail = theNode->next;
        theNode->next = NULL;
      //  aList->tail = NULL;

        
    }else if(NULL != theNode)
        
    {
        CharNode *thePrevNode = theNode; //текущий
        
        theNode = theNode->next;    //следующий
        
        thePrevNode->next = theNode->next;
    }
    
    free(theNode);
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

int partitionIt(CharList aList[], int aLeftIndex, int aRightIndex, CharNode *aPivot)
{
 
    int theLeft = aLeftIndex-1;
    int theRight = aRightIndex;

    
        //        CharNode *theNextLeft = theLeft-> next;
			//	CharNode *theNextRight = theRight->next;
    
    while (1)
    {
        
        
        CharNode *TheLeftElement = FindElementAtIndexAndReturnStruct(aList,theLeft);
        
        while (TheLeftElement->value < aPivot->value)
        {
            theLeft++;
            TheLeftElement = FindElementAtIndexAndReturnStruct(aList, theLeft);
        }
        // search the lowest element
        
        CharNode *TheRightElement = FindElementAtIndexAndReturnStruct(aList,theRight);

            while (theRight > 0 && TheRightElement->value > aPivot->value)
            {
                --theRight;
                TheRightElement = FindElementAtIndexAndReturnStruct(aList,theRight);
            }
        if (theLeft >= theRight) // pointer are the same
        {
            break;
        }
            else
            {
                //lets to swap elements
            /*
                char theTmp = theNode->value;
                theNode->value = theNode->next->value;
                theNode->next->value = theTmp;
            */
                /*
                 char theTmp = anArray->value[theLeft];
                 anArray->value[theLeft] = anArray->value[theRight];
                 anArray->value[theRight] = theTmp;
                */
                
                 swap(aList,TheLeftElement, TheRightElement);

            }
    }
    
 //   swap(aList,TheLeftElement, TheRightElement);

        /*
         int theTmp = anArray[theLeft];
         anArray[theLeft] = anArray[aRightIndex];
         anArray[aRightIndex] = theTmp;
    */
    
    return theLeft; // return break position
}

/*
void quickSort(CharList aList[], int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return; // the array size equals to 1 - the array is fully sorted
    }
    
    CharNode *thePivot = FindElementAtIndexAndReturnStruct(aList, aRightIndex);
    int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);
    
    //left part sorting
    quickSort(aList, aLeftIndex, thePartitionIndex - 1);
    
    //right part sorting
    quickSort(aList, thePartitionIndex + 1, aRightIndex);
}
*/







void swap(CharList *inputList, CharNode *aLeftIndex,CharNode *aRightIndex)
{
    // Do simple sorting
    CharNode *theNode = inputList->head; ///<- seems like 'left' is head
    
   
           // if (theNode->letter > theSubNode->v)
           // {
                //swap nodes
                //1. Swap pointers
                
                CharNode *theTmpNode = theNode;
              //  if (NULL != theNode->prevNode)
              //  {
               //     theNode->prevNode->nextNode = theSubNode;
                //}
               // else
                //{
                    //the border case: update head
                  //  inputList->left = theSubNode;
                //}
                
            //    if (NULL != aLeftIndex->next)
              //  {
                   // theSubNode->nextNode->prevNode = theNode;
              //  }
              //  else
                //{
                    //the border case: update tail.
                  //  inputList->right = theNode;
                //}
                
               // charNode *theTmpNext = theNode->next;
               // charNode *theTmpPrev = theNode->prevNode;
                
                theNode->next = aLeftIndex->next;
               // theNode->prevNode = (theNode != theSubNode->prevNode) ? theSubNode->prevNode : theSubNode;
                
                aRightIndex->next = (aRightIndex != theTmpNode) ? theTmpNode : theNode;
              //  theSubNode->prevNode = theTmpPrev;
                
                //3. Corrected local variables
                theTmpNode = theNode;
                theNode = aRightIndex;
                aRightIndex = theTmpNode;
            }

 

/*
p - A_LEFT
q - a right
  */
/*
    void swap(CharList * aList,CharNode * aLeftIndex, CharNode * aRightIndex) {
        CharNode *thetmp;
        thetmp = aLeftIndex->next;
        aLeftIndex->next = aRightIndex->next;
        aRightIndex->next = thetmp;
        
        thetmp = aLeftIndex->next->next;
        aRightIndex->next->next = aLeftIndex->next->next;
        aLeftIndex->next->next = thetmp;
    }
 */
