#include "TLList.h"
#include "TLNode.h"
#include "stdio.h"
#include <stdlib.h>

const int kTLListError = -1;

DoubleList *TLCreateList()
{
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));
	
	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0; 
	
	return theList;
}

void TLFreeList(DoubleList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	DoubleNode *theNode = aList->head;
	
	while (NULL != theNode)
	{
		DoubleNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;
	
		free(theNodeToBeFree);
	}

	free(aList);
}

DoubleNode *TLAddNode(DoubleList *aList, DoubleNode *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}
	
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		DoubleNode *theTail = aList->tail;
		aList->tail = aNewNode;
		aNewNode->previousNode = theTail;
		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
	
	return aNewNode;
}

int TLCountList(const DoubleList *aList)
{
	int theResult = kTLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

void AddNodeAtIndex(DoubleList *aList, DoubleNode *aNewNode, int anIndex) 
{
	if (NULL != aList && anIndex < aList->count  && NULL != aNewNode)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;	
		do
		{
			if (i == anIndex) //index was found
			{				
				DoubleNode *thePreviousNode = theNode->previousNode;
				aNewNode->nextNode = theNode;
				if(NULL != thePreviousNode)
					thePreviousNode->nextNode = aNewNode;
				else
					aList->head = aNewNode;
				aNewNode->previousNode = thePreviousNode;
				theNode->previousNode = aNewNode;
				break;
			}		
			i++; // increase index
			theNode = theNode->nextNode; //go to next node		
		} while (NULL != theNode);	
		aList->count += 1;
	}
}

void DeleteNodeAtIndex(DoubleList *aList, int anIndex)
{
	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;	
		do
		{
			if (i == anIndex) //index was found
			{
				DoubleNode *PreviousNode = theNode->previousNode;
				DoubleNode *NextNode = theNode->nextNode;
				if(NULL != PreviousNode)
					PreviousNode->nextNode = NextNode;
				else{
					aList->head = NextNode;
					NextNode->previousNode = NULL;
				}
				if(NULL != NextNode)
					NextNode->previousNode = PreviousNode;
				else{
					aList->tail = PreviousNode;
					PreviousNode->nextNode = NULL;
				}
				free(theNode);	
				break;
			}		
			i++; // increase index
			theNode = theNode->nextNode; //go to next element		
		} while (NULL != theNode);		
		aList->count-=1; 
	}
}

DoubleNode *NodeAtIndex(const DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;
	
		do
		{
			if (i == anIndex) //index was found
			{
				theResult = theNode; //our element
				break;
			}
		
			i++; // increase index
			theNode = theNode->nextNode; //go to next element
		
		} while (NULL != theNode);
	}
	
	return theResult;
}
