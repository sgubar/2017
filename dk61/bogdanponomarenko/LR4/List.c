#include "List.h"
#include <stdlib.h>
#include <stdio.h>


void List()
{
		printf("\n");
		printf("\t\t\tList :\n\n");
	DoubleList *theList = CreateList();
	DoubleNode *theNode1 = CreateNodeWithValue(17);
	DoubleNode *theNode2 = CreateNodeWithValue(8);
	DoubleNode *theNode3 = CreateNodeWithValue(21);
	DoubleNode *theNode4 = CreateNodeWithValue(11);
	DoubleNode *theNode5 = CreateNodeWithValue(2);
	DoubleNode *theNode6 = CreateNodeWithValue(1);
	AddNode(theList, theNode1);
	AddNode(theList, theNode2);
	AddNode(theList, theNode3);
	AddNode(theList, theNode4);
	AddNode(theList, theNode5);
	AddNode(theList, theNode6);
	printf("Number of elements is : %d\n", CountList(theList));
	printf("------------------------------------------------------------\n");
	for (int i=0;i<2;i++)
	{
	PrintList(theList);
	printf("\n");
	printf("Back print\n");
	BackPrintList(theList);
	printf("-------------------------------------------------------------");
	printf("\n\n");
	}
	FreeList(theList);
}
DoubleList *CreateList()

{
	
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));
	
	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0; 

	return theList;

}

void FreeList(DoubleList *aList)
{
	
	if (NULL == aList)
	{
		return;
	}
	
	DoubleNode *theNode = aList->head;
	while (NULL != theNode)
	{
		DoubleNode *theNodeToBeFree = theNode;
		theNode = theNode->next;
		free(theNodeToBeFree);
	}

	free(aList);
}

DoubleNode *AddNode(DoubleList *aList, DoubleNode *aNewNode)
{
	
	if (NULL == aList || NULL == aNewNode)

	{
		return NULL;
	}

	if (NULL == aList->head && NULL == aList->tail)
	{
	
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
			if (i == anIndex) 
			{
				theResult = theNode; 
				break;
			}
			i++; 
			theNode = theNode->next; 
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
			printf("node[%d].value = %.2f\n", i+1, theNode->value);
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
			printf("node[%d].value = %.2f\n", i, theNode->value);
			theNode = theNode->prev;
		}
		
	}
}

DoubleNode *CreateNodeWithValue(double aValue)

{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

	theNode->value = aValue;
	theNode->next = NULL;
    theNode->prev = NULL;
    
	return theNode;
}

void FreeNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}



