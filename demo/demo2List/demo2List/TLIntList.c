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

static IntNode *createIntNodeWithValue(int anIntValue);

#pragma mark -
IntList *TLCreateIntList()
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void TLDestroyIntList(IntList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		IntNode *theNode = aList->head;
	
		do
		{
			IntNode *theNodeToDelete = theNode;
			theNode = theNode->next;
		
			free (theNodeToDelete);
		
		}while (NULL != theNode);
	
		free(aList);
	}
}

int TLAddIntValueToList(IntList *aList, int anIntValue)
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		IntNode *theNode = createIntNodeWithValue(anIntValue);
	
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
				IntNode *theTail = aList->tail;
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

int TLIntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = INT_MAX;
	
	if (NULL == aList || anIndex >= aList->count)
	{
		return theResult;
	}
	
	IntNode *theNode = aList->head;
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
	
	return theNode->value;
}

// print list
void TLPrintList(IntList *aList)
{
	printf("[List] with count (%d):", aList->count);
	IntNode *theNode = aList->head;
	
	do
	{
		printf("(%d) ", theNode->value);
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
	printf ("\n");
}

int TLInsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	IntNode *theNode = aList->head;
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
	
	IntNode *theNewNode = createIntNodeWithValue(anIntValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	IntNode *theBNode = theNode;
	
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

#pragma mark -
#pragma mark IntNode interface
IntNode *createIntNodeWithValue(int anIntValue)
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anIntValue;
	}
	
	return theNode;
}
