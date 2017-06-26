#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"


void CreateList(Node **head, Node **last)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = 0;

	(*head) = newNode;
	(*last) = (*head);
}

void addElement(Node **theNode, char val)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	aNode->data = val;
	aNode->next = (*theNode);
	(*theNode) = aNode;
	aNode = NULL;
}

void AddElementToList(Node **head, Node **last)
{
	float theData;
	printf("Enter value: ");
	scanf("%f", &theData);

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = theData;
	(*last)->next = newNode;
	(*last) = newNode;
	(*last)->next = NULL;

	printf("Element added\n");
}

void PrintEdge(Node **head, Node **last, int edge)
{
	*last = (*head);
	printf("--------List of elements smaller for [%i]--------\n", edge);
	while ((*last) != NULL)
	{
		if((*last)->data < edge)
		printf("%i ", (*last)->data);
		(*last) = (*last)->next;
		
	}
}

void PrintRange(Node **head, Node **last, int a, int b)
{
	*last = (*head);
	printf("\n--------List of elements from the range [%i;%i]--------\n", a, b);
	while ((*last) != NULL)
	{
		if(((*last)->data > a-1) && ((*last)->data < b+1))
		printf("%i ", (*last)->data);
		(*last) = (*last)->next;
		
	}
}

void PrintNOTRange(Node **head, Node **last, int a, int b)
{
	*last = (*head);
	printf("\n--------Elements NOT in the range[%i;%i]--------\n", a, b);
	while ((*last) != NULL)
	{
		if(((*last)->data < a)||((*last)->data > b)) //
		printf("%i ", (*last)->data);
		(*last) = (*last)->next;
	}
}
