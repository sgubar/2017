#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void createList(Node **head, Node **last)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = 0;

	(*head) = newNode;
	(*last) = (*head);
}


void addToList(Node **head, Node **last)
{
    float theData;

	printf("Введите число: ");
	scanf("%f", &theData);

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = theData;
	(*last)->next = newNode;
	(*last) = newNode;
	(*last)->next = NULL;

}

void deleteElement(Node **head)
{
	if ((*head)->next == NULL)
	{
		printf("Список очищен.\n");
		return;
	}

	Node *tmp = (*head);
	(*head) = (*head)->next;
	free(tmp);

}


void printElements(Node **head, Node **last)
{
	*last = (*head);
	int size = 0;
	printf("Содержимое списка: ");
	while ((*last) != NULL)
	{
		printf("%f ", (*last)->data);
		size++;
		(*last) = (*last)->next;
	}

	printf("\n");
	printf("Размер списка %i\n", size);
}


Node *findMinimum(Node **head, Node **last)
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

	printf("Минимальный элемент: %f\n", (*minNode)->data);
	return *minNode;
}

void swap(Node *a, Node *b)
{
	float temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sort(Node **head, Node **last, Node **minNode)
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
