//
//  TLIntList.c
//  demo2List
//
//  Created by Slava Gubar on 4/11/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//


#include <limits.h>
#include <stdlib.h>
#include "TLCharList.h"
#include "SortingList.h"
#include "DoCreateDestroyList.h"


static CharNode *createCharNodeWithSymbol(char anCharSymbol);

#pragma mark -

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
                theNode->prev = theTail;
                
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	
	return theResult;
}



char FindCharElementAtIndex(CharList *aList, int anIndex)
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

CharNode *FindNodeAtIndex(CharList *aList, int anIndex)
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

int TLInsertCharSymbolAtIndex(CharList *aList, char *anCharValue, int anIndex)
{
    int theResult = -1;
    
    if (NULL == aList || anIndex >= aList->count || anIndex < 0)
    {
        return theResult;
    }
    
    CharNode *theNode = aList->head;
    int i = 0;
    
    do
    {
        if (i == anIndex)
        {
            break;
        }
        
        theNode = theNode->next;
        i++;
        
    }while (NULL != theNode);
    
    // a b c ^ d(1) => a ->d->b c
    
    CharNode *theNewNode = createCharNodeWithSymbol(*anCharValue);
    if (NULL == theNewNode)
    {
        return theResult;
    }
    
    CharNode *theBNode = theNode;
    
    if (NULL != theBNode->prev)
    {
        theBNode->prev->next = theNewNode; //a->d
        theNewNode->prev = theBNode->prev; //d->a
    }
    
    theNewNode->next = theBNode; //d->b
    theBNode->prev = theNewNode; //b->d
    
    aList->count ++;
    theResult = 0;
    
    return theResult;
}

CharNode *removeCharNodeAtIndex(CharList *aList, int anIndex)

{
if(anIndex < aList->count)
    {
    
    CharNode *theNode = FindNodeAtIndex(aList, anIndex);
    if(aList->tail == theNode)
    {
        aList->tail = theNode->prev;
        theNode->next = NULL;
    }
    else if(aList->head==theNode)
    {
        aList->head=theNode->next;
        theNode->prev=NULL;
    }
    else {
        CharNode *aNextNode = theNode->next;
        CharNode *aPrevNode = theNode->prev;
        aPrevNode->next = aNextNode;
        aNextNode->prev = aPrevNode;
    }
    aList->count--;
    return theNode;
}
return NULL;
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


#pragma mark -
#pragma mark IntNode interface
CharNode *createCharNodeWithSymbol(char CharSymbol)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
        theNode->prev = NULL;
		theNode->value = CharSymbol;
	}
	
	return theNode;
}




/*
        For Simply-connected list
                            */

/*
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
 */

/*
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
 */
