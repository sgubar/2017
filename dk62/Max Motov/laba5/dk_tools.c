#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"


void CreateList(Node **head, Node **last)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = 0;

	(*head) = newNode;
	(*last) = (*head);
}


void AddElementToList(Node **head, Node **last)
{
	float theData;
	printf("Enter value: ");
	scanf("%f", &theData);

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = theData;
	//newNode->next = (*head);
	(*last)->next = newNode;
	(*last) = newNode;
	(*last)->next = NULL;

	printf("Element added\n");
}

void DeleteElement(Node **head)
{
	if ((*head)->next == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Node *tmp = (*head);
	(*head) = (*head)->next;
	free(tmp);

	printf("Element deleted\n");
}


void PrintElements(Node **head, Node **last)
{
	*last = (*head);
	int size = 0;
	printf("List elements: ");
	while ((*last) != NULL)
	{
		printf("%f ", (*last)->data);
		size++;
		(*last) = (*last)->next;
	}

	printf("\n");
	printf("List size %i\n", size);
}


Node *FindMinimum(Node **head, Node **last)
{
	last = head;
	Node **minNode = last;
	do
	{
		if ((*minNode)->data > (*last)->next->data)
		{
			minNode = &(*last)->next;
		}
		last = &(*last)->next;
	} while ((*last)->next != NULL);

	printf("Minimum: %f\n", (*minNode)->data);
	return *minNode;
}

void swap(Node *a, Node *b)
{
	float temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void Sort(Node **head, Node **last, Node **minNode)
{
	int swapped;
    Node *ptr1, *lptr;
    lptr = NULL;
	do
	{
		swapped = 0;
		ptr1 = (*minNode);

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}
