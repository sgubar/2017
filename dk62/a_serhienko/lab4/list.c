
#include <stdio.h>
#include <malloc.h>
#include "list.h"
#include "node.h"



List* CreateList() 
{
	List *theList = (List *)malloc(sizeof(List));

	
	theList->begin = NULL; 
	theList->end = NULL; 
	theList->count = 0; 

						

	return theList;
}


Node *AddNodeToList(List *aList, Node *aNewNode)
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

	aList->count++;

	return aNewNode;
}

int CountList(const List *aList)
	{
		int theResult = 0;
		if (NULL != aList)
		{
			theResult = aList->count;
		}

		return theResult;

	}


void printListNodebyNode(List*aList)
{
	if (NULL == aList)
		return;

	Node*theNode = aList->begin;

	while (theNode != NULL)
	{
		if (theNode == aList->begin) {
			printf("-----------------------\n");
			printf("| The symbol :    '%c' |\n", theNode->symbol);
			printf("| Entry point(s): '%d' |\n", theNode->counter);
			printf("-----------------------\n");
			printf("           | \n");
			printf("          | |\n");
			printf("           |\n");
			theNode = theNode->next;
		}
		else if(theNode != aList->end)
		{
			printf("-----------------------\n");
			printf("| The symbol :    '%c' |\n", theNode->symbol);
			printf("| Entry point(s): '%d' |\n", theNode->counter);
			printf("-----------------------\n");
			printf("           | \n");
			printf("          | |\n");
			printf("           |\n");
			theNode = theNode->next;

		}
		else if (theNode == aList->end) 
		{
			printf("-----------------------\n");
			printf("| The symbol :    '%c' |\n", theNode->symbol);
			printf("| Entry point(s): '%d' |\n", theNode->counter);
			printf("-----------------------\n");
			theNode = theNode->next;
		}
		
	}

}

void FreeList(List *aList)
{

	if (NULL == aList)
	{
		return;
	}

	
	Node *theNode = aList->begin;

	while (NULL != theNode)
	{
		Node *theNodeToBeFree = theNode;
		theNode = theNode->next;

		free(theNodeToBeFree);
	}

	
	free(aList);
}