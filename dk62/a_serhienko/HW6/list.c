#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "list.h"
#include "node.h"

static Node *createNodeWithfloatValue(float aValue);

floatList *CreatefloatList()
{
	floatList *theList = (floatList *)malloc(sizeof(floatList));

	if (NULL != theList)
	{
		theList->begin = NULL;
		theList->end = NULL;
		theList->count = 0;
	}

	return theList;
}


void DestroyfloatList(floatList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->end && NULL != aList->begin)
	{
		Node *theNode = aList->begin;

		do
		{
			Node *theNodeToDelete = theNode;
			theNode = theNode->next;

			free(theNodeToDelete);

		} while (NULL != theNode);

		free(aList);
	}
}


Node *AddfloatValueToList(floatList *aList, Node *aNewNode)
{

	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}


	if (NULL == aList->begin && NULL == aList->end)
	{
		
		aList->begin = aList->end = aNewNode;
	}
	else
	{
		Node *theEnd = aList->end;
		aList->end = aNewNode;

		if (NULL != theEnd)
		{
			theEnd->next = aList->end;
		}
	}

	aList->count += 1;

	return aNewNode;
}



Node *floatValueAtIndex(const floatList *aList, int Index)
{
	
	 Node* theResult = -1;
	if (NULL == aList || Index >= aList->count)
	{
		return theResult;
	}

	Node *theNode = aList->begin;
	int i = 0;

	do
	{
		if (i == Index)
		{ 
			theResult = theNode;
			
			break;
		}

		theNode = theNode->next;
		i++;

	} while (NULL != theNode);
	return theResult;
}

void PrintList(floatList *aList)
{
	printf("\n[List] with count (%d):\n", aList->count);
	Node *theNode = aList->begin;

	do
	{
		printf("(%f) \n", theNode->value);
		theNode = theNode->next;

	} while (NULL != theNode);

	printf("\n");
}

int CountList(const floatList *aList)
{
	int theResult = 0;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

 Node *InsertfloatValueAtIndex(floatList *aList, Node*NewNode, int Index)
{
	
	
	if (NULL == aList || NULL == NewNode || Index>aList->count + 1)
	{
		return NULL;
	}
	else
	{
		if (NULL != aList &&  Index < aList->count + 1)
		{
			if (Index == 0)
			{
				NewNode->next = aList->begin;
				aList->begin = NewNode;
				aList->count += 1;
				return (NewNode);
			}
			if (Index == aList->count + 1)
			{
				aList->end = NewNode;
				NewNode->next = aList->end;
				return (NewNode);
			}
			else
			{   
				Node *previousNode = floatValueAtIndex(aList, Index - 1);
				NewNode->next = previousNode->next;
				previousNode->next = NewNode;
				aList->count += 1;
				return (NewNode);
			}
		}
	}
}

void DeleteElementAtIndex(floatList *aList, int Index) 
{
	if (NULL != aList && Index < aList->count)
	{
		int i = 0;
		Node *theNode = aList->begin;
		do
		{
			if (i == Index) 
			{
			   Node *PreviousNode = floatValueAtIndex(aList, Index - 1);
			   Node *NextNode = theNode->next;
				if (NULL != PreviousNode)
					PreviousNode->next = NextNode;
				else {
					aList->begin = NextNode;
					NextNode->next = NULL;
				}
				if (NULL != NextNode)
					NextNode = PreviousNode->next;
				else {
					aList->end = PreviousNode;
					PreviousNode->next = NULL;
				}
				free(theNode);
				break;
			}
			i++; 
			theNode = theNode->next;
		} while (NULL != theNode);
		aList->count -= 1;
	}
}





