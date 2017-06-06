#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "link.h"

Node *createList(int aSize)
{
	srand(time(NULL));


	Node *head = (Node *) malloc(sizeof(Node));
	head->value = rand() % 10000;
	head->next = NULL;

	int i;

	for(i = 0; i < aSize - 1; i++)
		createElement(head, rand() % 10000);

	return head;
}

void createElement(Node *head, int val)
{
	if(head == NULL)
	{
		printf("Empty linked list\n");
	    return;
	}


	while(head->next != NULL)
		head = head->next;


	Node *last = head;
	Node *tmp = (Node *) malloc(sizeof(Node));

	tmp->value = val;
	tmp->next = NULL;
	last->next = tmp;
}

int deleteElement(Node **head, int num)
{
	if(head == NULL)
	{
		printf("Error with deleting\n");
	    return 1;
	}
	if((*head) == NULL)
	{
		printf("Error with deleting\n");
	    return 2;
	}


	if(num == 0)
	{
		Node *last = (*head);
		int el = last->value;

		(*head) = (*head)->next;
		free(last);

		return el;
	}


	else
	{
		int i = 0;
		Node *tmp = *head;


		while(i < num - 1 && head != NULL)
		{
			tmp = tmp->next;
			i++;
		}


    	Node *last = tmp;
    	Node *el  = last->next;

		int val = el->value;
	    last->next = el->next;

		free(el);
	    return val;
    }
}

void deleteList(Node **head)
{
	if(head == NULL)
	{
		printf("Empty linked list\n");
	    return;
	}

	Node *last = NULL;

	while((*head)->next != NULL)
	{
    	last = (*head);
    	(*head) = (*head)->next;
    	free(last);
    }

	free(*head);
	*head = NULL;
}

void printLinkedList(Node *head)
{
	if(head == NULL)
	{
		printf("Empty linked list\n");
	    return;
	}
	printf("\nLinked list: ");
	while(head != NULL)
	{
    	printf("%i ", head->value);
    	head = head->next;
    }

	printf("\n");
}

float findAverage(Node *head)
{
	int i = 0;
	float sum = 0;

	while(head != NULL)
	{
		sum += head->value;	//amount values of list
		head = head->next;
		i++;				//amount elements in list
	}

	return sum / i;
}

int findTrash(Node *head, float pivot)
{
	if(head == NULL)
	    return 22;

	int i = 0, j, tmp;

	//search in all list
	while(head != NULL)
	{
		//max value that smaller than pivot
		if(head->value < pivot && head->value > tmp)
		{
			tmp = head->value;	//save value of searching element
			j = i;				//save number of searching element
		}

		i++;
		head = head->next;
	}

	return j;
}

int valueElement(Node *head, int num)
{
	if(head == NULL)
	    return 3;

	int i = 0;
	//searching element
	while(i < num)
	{
		head = head->next;
		i++;

		//if num larger than amount of elements in list
		if(head == NULL)
		{
			printf("No such element with this number: %i", num);
			return 4;
		}
	}

	return head->value;
}
