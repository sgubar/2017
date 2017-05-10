// List.c

#include "List.h"
#include <limits.h>
#include <stdlib.h>

IntNode *createIntNodeWithValue(int anIntValue);

IntList *CreateIntList( void )
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

IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex)
{
	if(aList == NULL || anIndex < 0 || aList->count < anIndex )
	{
		return;
	}
	
	int i = 0;
	IntNode *theNode = aList->head;
		do
	{
		if (i == anIndex)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (NULL != theNode);
	
	return theNode;
}

void DestroyIntList(IntList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		int anIndex = aList->count - 1;
		
		do
		{
		IntNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
		free (theNodeToDelete);
		anIndex--;		
		}while (anIndex >= 0);
	
		free(aList);
	}
}

int AddIntValueToList(IntList *aList, int anIntValue)
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
				IntNode *theTail = aList->tail;// to mem c->NUll
				aList->tail = theNode;		   // new tail (d) -> NULL
				theTail->next = theNode;	   // rewrite c -> d
				theNode->prev = theTail;	   //         c <- d
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	
	return theResult;
}

int IntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = INT_MAX;
	
	//list is empty   or   typed wrong index  
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
	
	return theNode->value;
}

// print list
void PrintList(IntList *aList)
{
	printf("[List] with count (%d): ", aList->count);
	if (0 == aList->count)
	{
		printf(" empty\n");
		return;
	}

	IntNode *theNode = aList->head;
	
	do
	{
		printf("(%d) ", theNode->value);
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
	printf ("\n");
}

int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	IntNode *theNode = FindTheNodeAtIndex(aList, anIndex);

	IntNode *theNewNode = createIntNodeWithValue(anIntValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	IntNode *theANode = theNode;
	
	// a b ^ c(0) => c->a->b
	if (NULL == theANode->prev)	// for the first element
	{
		aList->head = theNewNode;	 // new head
		theNewNode->next = theANode; // c->a
		theANode->prev = theNewNode; // c<-a
	}
	
	// b a  ^ c(1) => b->c->a
	else if (NULL == theANode->next)	// for the last element
	{
		theNewNode->prev = theANode->prev;  // b <- c
		theNewNode->prev->next = theNewNode;// b -> c
		
		theANode->prev = theNewNode;		// c <- a
		theNewNode->next = theANode;		// c -> a
	}
	
	// in the middle
	else 	
	{
		// b c a d ^ z(2) = b->c->z->a->z
		theANode->prev->next = theNewNode; // c->z 
		theNewNode->prev = theANode;	   // z<-a
		
		theNewNode->next = theANode;		// z->a
		theANode-> prev = theNewNode;		// z<-a
	}	
	
	aList->count ++;
	theResult = 0;
	
	return theResult;
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

int DeleteIntValueAtIndex(IntList *aList, int anIndex)
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
	
	IntNode *theNodeToDelete = theNode;
	if (aList->count == 1)	//for list with 1 element
	{
		free(theNodeToDelete);
		aList->count = 0;
		aList->head = NULL;
		aList->tail = NULL;
		theResult = 0;
		return theResult;
	}
	
	if (NULL == theNodeToDelete->prev)	// for the first element
	{
		aList->head = theNodeToDelete->next;
		aList->head->prev = NULL; //head doesn't have prev
		theResult = 0;
	}
	
	else if (NULL == theNodeToDelete->next)	//for the last element
	{
		aList->tail = theNodeToDelete->prev;
		aList->tail->next = NULL;		//end of list
		theResult = 0; 
	}
	else 		//if (NULL != theNodeToDelete->prev && NULL != theNodeToDelete->next) //not the border element
	{
		theNodeToDelete->prev->next = theNodeToDelete->next;
		theNodeToDelete->next->prev = theNodeToDelete->prev;
		theResult = 0;
	}
	
	aList->count--;
	free(theNodeToDelete);
	return theResult;
}

int random(int N)
{
	return rand() % N;
}
