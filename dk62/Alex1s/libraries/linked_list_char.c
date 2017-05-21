#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void createFirstPush(Node **head, char val)
{
	Node *tmp = (Node *) malloc(sizeof(Node));
	tmp->value = val;
	tmp->next = (*head);
	(*head) = tmp;
	tmp = NULL;
}

//-------------------------------------------------------------------------

char deleteFirstPop(Node **head)
{
	if(!head)
	    exit(-1);
	
	Node *last = (*head);
	char el = last->value;
	
	(*head) = (*head)->next;
	free(last);
	
	return el;
}

//-------------------------------------------------------------------------

int getNumber(Node *head, Node *tmp)
{
	if(!head)
	    exit(-2);
	
	int i = 0;
	while(head != tmp && head->next)
	{
    	head = head->next;
    	i++;
	}

	return i;
}

//-------------------------------------------------------------------------

char getValueNumber(Node *head, int num)
{
	if(!head)
	    exit(-3);
	
	int i = 0;
	while(i++ < num && head)
    	head = head->next;
	
	return head->value;
}

//-------------------------------------------------------------------------

Node *getElement(Node *head, int num)
{
	if(!head)
	    exit(-5);
	
	int i = 0;
	while(i++ < num && head)
    	head = head->next;
	
	return head;
}

//-------------------------------------------------------------------------

Node *getLsatElement(Node *head)
{
	if(!head)
    	exit(-6);
	
	while(head->next)
    	head = head->next;
	
	return head;
}

//-------------------------------------------------------------------------

void createLastElement(Node *head, char val)
{
	if(!head)
	    exit(-7);
	
	Node *last = getLsatElement(head);
	Node *tmp = (Node *) malloc(sizeof(Node));
	tmp->value = val;
	tmp->next = NULL;
	last->next = tmp;
}

//-------------------------------------------------------------------------

Node *getPreLastElement(Node *head)
{
	if(!head)
	    exit(-8);
	
	if(!(head->next))
		return NULL;
	
	while(head->next->next)
		head = head->next;
	
	return head;
}

//-------------------------------------------------------------------------

Node *getPreElement(Node *head, Node *tmp)
{
	if(!head || !tmp)
	    exit(-9);
	
	while(head->next != tmp && !(head->next))
		head = head->next;
	
	return head;
}

//-------------------------------------------------------------------------

char deleteLastPop(Node **head)
{
	Node *last = NULL;
	if(!head)
	    exit(-10);
	if(!(*head))
		exit(-11);
	
	last = getPreLastElement(*head);
	char val = last->value;
	if(!last)
	{
	    free(*head);
	    *head = NULL;
    }
	
	else
	{
    	free(last->next);
    	last->next = NULL;
    }
	
	return val;
}

//-------------------------------------------------------------------------

void insertElement(Node *head, int num, char val)
{
	if(!head)
	    exit(-12);
	
	int i = 0;
	Node *tmp = NULL;
	
	while(i++ < (num - 1) && head->next)
	    head = head->next;
	
	tmp = (Node *) malloc(sizeof(Node));
	tmp->value = val;
	
	if(head->next)
	    tmp->next = head->next;
	else
	    tmp->next = NULL;
	
	head->next = tmp;
}

//-------------------------------------------------------------------------

char deleteElement(Node **head, int num)
{
	if(!head)
	    exit(-13);
	if(!(*head))
		exit(-14);
	
	if(!num)
	    return deleteFirstPop(head);
	
	else
	{
    	Node *last = getElement(*head, num - 1);
    	Node *el  = last->next;
    	
		char val = el->value;	
	    last->next = el->next;
	    
		free(el);
	    return val;
    }
}

//-------------------------------------------------------------------------

void deleteList(Node **head)
{
	if(!head)
	    exit(-15);
	
	Node *last = NULL;
	while((*head)->next)
	{
    	last = (*head);
    	(*head) = (*head)->next;
    	free(last);
    }
	free(*head);
}

//-------------------------------------------------------------------------

void arrayToList(Node **head, char *anArray, int aSize)
{
	if(!anArray || !aSize)
	    exit(-16);
	
	do{
	    createFirstPush(head, anArray[--aSize]);
	}while(aSize);
}

//-------------------------------------------------------------------------

char *listToArray(Node *head)
{
	if(!head)
	    exit(-17);
	
	int i, len = getLength(head);
	char *aArray = (char *) malloc(sizeof(char) * len);
	
	while(head)
	{
	    aArray[i++] = head->value;
	    head = head->next;
	}
	
	return aArray;
}

//-------------------------------------------------------------------------

void printList(Node *head)
{
	if(!head)
	    exit(-18);
	
	while(head)
	{
    	printf("%c ", head->value);
    	head = head->next;
    }
	
	printf("\n");
}

//-------------------------------------------------------------------------

int getLength(Node *head)
{
	if(!head)
	    exit(-19);
	
	int i = 0;
	while(head)
	{
	    head = head->next;
		i++;
	}
	
	return i;
}

//-------------------------------------------------------------------------

void changeElement(Node *head, int num, char val)
{
	if(!head)
	    exit(-20);
	
	int i = 0;
	while(i++ < num && head->next)
	    head = head->next;
	
	head->value = val;
}

//-------------------------------------------------------------------------

