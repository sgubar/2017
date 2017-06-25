#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dk_tool.h"

List *createList()
{
	List *aList = (List *) malloc(sizeof(List));
	
	if(aList != NULL)
	{
		aList->head = NULL;
		aList->tail = NULL;
	}
	
	return aList;
}

void createFirstElement(List *aList, int val)
{
	if(aList != NULL)
	{
		Node *aNode = (Node *) malloc(sizeof(Node));
		
		if(aNode != NULL)
		{
			aNode->value = val;
			aNode->next = aList->head;
			aNode->prev = NULL;
			
			aList->head = aNode;
			aList->tail = aNode;
			aNode = NULL;
			
		}
	}
}

void createNextElement(List *aList, int val)
{
	if(aList->head != NULL)
	{
		Node *aNode = (Node *) malloc(sizeof(Node));
		
		if(aNode != NULL)
		{
			Node *last = aList->tail;
			
			aNode->value = val;
			aNode->prev = last;
			aNode->next = NULL;
			
			aList->tail = aNode;
			last->next = aNode;
			
		}
	}
}

void fillElements(List *aList)
{
	srand(time(NULL));
	createFirstElement(aList, rand() % 100);
	
	for(int i = 0; i < 15; i++)
		createNextElement(aList, rand() %100);
}

void printList(List *aList)
{
	if(aList != NULL)
	{
		printf("Normal: ");
		Node *temp = aList->head;
		while(temp != NULL)
		{
	    	printf("%i ", temp->value);
	    	temp = temp->next;
	    }
		printf("\n");
	}
}

void rePrintList(List *aList)
{
	if(aList != NULL)
	{
		Node *temp = aList->tail->prev;
		
		printf("perevern: %i ", aList->head->value);
		while(temp->prev != NULL)
		{
	    	printf("%i ", temp->value);
	    	temp = temp->prev;
	    }
		printf("%i\n", aList->tail->value);
	}
}

void deleteList(List *aList)
{
	if(aList != NULL)
	{
		Node *last = NULL;
		Node *temp = aList->head;
		
		while(temp->next != NULL && temp->prev != NULL)
		{
	    	last = temp;
	    	temp = temp->next;
	    	free(last);
	    }
		free(temp);
		free(aList);
	}
}
