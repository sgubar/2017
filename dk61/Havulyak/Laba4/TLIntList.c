#include "TLIntList.h"

#include <stdlib.h>
	
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

void TLPrintList1(IntList *aList)
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

void TLPrintList2(IntList *aList)
{
	printf("[List] with count (%d):", aList->count);
	IntNode *theNode = aList->head;
	
	while(theNode->next !=NULL)
	theNode = theNode->next;   //Ïåðåõîä ê êîíöó ñïèñêà
	do
	{
		printf("(%d) ", theNode->value); 
		theNode = theNode->next; //Ïåðåõîä ê ïðåäûäóùåìó óçó.
	
	}while (NULL != theNode);
	
	printf ("\n");
}

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
