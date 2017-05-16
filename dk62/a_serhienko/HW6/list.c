#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "list.h"
#include "node.h"




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


int AddfloatValueToList(floatList *aList,float floatValue)
{
	int theResult = -1;
	if (aList != NULL)
	{
		Node *aNode = createNodeWithfloatValue(floatValue);

		if (aNode != NULL)
		{
			if (aList->begin == NULL && aList->end == NULL)
			{
				aList->begin = aList->end = aNode;
			}
			else
			{
				// (head) a b c (tail) + d -> (head)a b c=>d (tail)

				Node *theTail = aList->end;
				aList->end = aNode;
				theTail->next = aNode;
				aNode->prev = theTail;
			}

			aList->count++;
			theResult = 0;
		}
	}

    return theResult;
}



float floatValueAtIndex(floatList *aList, int anIndex)
{
	if (aList == NULL || anIndex >= aList->count || anIndex<0)
	{
		return -1;
	}

	Node *aNode = floatNodeAtIndex(aList, anIndex);

	return aNode->value;
}

Node *floatNodeAtIndex(floatList *aList, int anIndex)
{
	if (aList == NULL || aList->count == 0)
	{
		return NULL;
	}
	Node *aNode = aList->begin;
	int counter = 0;

	while (counter<anIndex)
	{
		aNode = aNode->next;
		counter++;
	}
	return aNode;
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

Node*  InsertfloatValueAtIndex(floatList *aList, Node *aNewNode, int anIndex)
{
	if (NULL != aList && anIndex < aList->count  && NULL != aNewNode)
	{
		int i = 0;
		Node *theNode = aList->begin;
		do
		{
			if (i == anIndex) //<!- index was found
			{
				Node *thePreviousElement = theNode->prev;
				aNewNode->next = theNode;
				if (NULL != thePreviousElement)
					thePreviousElement->next = aNewNode;
				else
					aList->begin = aNewNode;
				aNewNode->prev = thePreviousElement;
				theNode->prev = aNewNode;
				break;
			}
			i++; // increase index
			theNode = theNode->next; //<! - go to next node		
		} while (NULL != theNode);
		aList->count += 1;
	}
}

Node* DeleteElementAtIndex(floatList *aList, int anIndex)
{
	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		Node *theNode = aList->begin;
		do
		{
			if (i == anIndex) //<!- index was found
			{
				Node *PreviousElement = theNode->prev;
				Node *NextElement = theNode->next;
				if (NULL != PreviousElement)
					PreviousElement->next = NextElement;
				else {
					aList->begin = NextElement;
					NextElement->prev = NULL;
				}
				if (NULL != NextElement)
					NextElement->prev = PreviousElement;
				else {
					aList->end = PreviousElement;
					PreviousElement->next = NULL;
				}
				free(theNode);
				break;
			}
			i++; // increase index
			theNode = theNode->next; //<! - go to next element		
		} while (NULL != theNode);
		aList->count -= 1;
	}
}
void DeleteElement(floatList *aList)
{
	if (NULL != aList && aList->count != 0)
	{
		Node *theNodeToDelete = aList->end;
		Node *theNode = theNodeToDelete->prev;
		aList->end = theNode;
		theNode->next = NULL;
		free(theNodeToDelete);
		aList->count -= 1;
	}

}

void dotestList() 
{
	floatList *theList = CreatefloatList();
	if (NULL == theList)
	{
		return -1;
	}



	AddfloatValueToList(theList, 5.523);
	AddfloatValueToList(theList, 5.423);
	AddfloatValueToList(theList, 68.643);
	AddfloatValueToList(theList, 62.322);
	AddfloatValueToList(theList, 11.2);
	AddfloatValueToList(theList, 53.5);

	PrintList(theList);

	printf("The value at index %d: %f\n", 3, floatValueAtIndex(theList, 3));



	Node*theNode = createNodeWithfloatValue(23.5);

	InsertfloatValueAtIndex(theList, theNode, 3);
	printf("the Node has been created and added at index 3\n\n");
	PrintList(theList);

	DeleteElementAtIndex(theList, 5);
	printf("the Node has been succsessfully deleted at index 5\n\n");
	PrintList(theList);

	ShellSort(theList, theList->count);
	printf("the sorted List is:\n");
	PrintList(theList);
	printf("\nThe value at index %d: %f\n", 1, floatValueAtIndex(theList, 1));


	DestroyfloatList(theList);

}


