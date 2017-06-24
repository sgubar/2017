#include "List.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

DoubleList *CreateList()

{
	//Allocate memory for the list structure
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));
	//Clean internal data
	theList->head = NULL; //<!- not head
	theList->tail = NULL; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list

	return theList;

}

void FreeList(DoubleList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}
	//1. Remove all elements
	DoubleNode *theNode = aList->head;
	while (NULL != theNode)
	{
		DoubleNode *theNodeToBeFree = theNode;
		theNode = theNode->next;
		free(theNodeToBeFree);
	}
	//2. Free memory for the List structure
	free(aList);
}

DoubleNode *AddNode(DoubleList *aList, DoubleNode *aNewNode)
{
	// Check the input parameter
	if (NULL == aList || NULL == aNewNode)

	{
		return NULL;
	}
	//Add the new node to end of the list
	if (NULL == aList->head && NULL == aList->tail)
	{
		//The list is empty
		aList->head = aList->tail = aNewNode;
	}
	else
	{

		DoubleNode *theTail = aList->tail;
		aList->tail = aNewNode;
		aNewNode->prev = theTail;
        theTail->next = aList->tail;
	}

	aList->count += 1;
	return aNewNode;
}

int CountList(DoubleList *aList)
{
	int theResult = -1;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

DoubleNode *NodeAtIndex(DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}
			i++; // increase index
			theNode = theNode->next; //<! - go to next node
		} while (NULL != theNode);
	}

	return theResult;
}

void PrintList(DoubleList *aList)
{
	int i;
	for (i = 0; i < CountList(aList); i++)
	{
		DoubleNode *theNode = NodeAtIndex(aList, i);

		if (NULL != theNode)
		{
			printf("node[%d].value = %f\n", i+1, theNode->value);
		}
	}
}

void BackPrintList(DoubleList *aList)
{
	DoubleNode *theNode = aList->tail;
	int i;
	for (i = CountList(aList); i>=0; i--)
	{

		if (NULL != theNode)
		{
			printf("node[%d].value = %f\n", i, theNode->value);
			theNode = theNode->prev;
		}
		
	}
}
