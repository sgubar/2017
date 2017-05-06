#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void crFirst_push(Node **head, char val)
{
Node *tmp = (Node *) malloc(sizeof(Node));
tmp->value = val;
tmp->next = (*head);
(*head) = tmp;
tmp = NULL;
}

//-------------------------------------------------------------------------

void delList(Node **head)
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
(*head) = NULL;
}

//-------------------------------------------------------------------------

void printList(Node *head)
{
if(!head)
    exit(-18);

while(head)
	{
    printf("%c", head->value);
    head = head->next;
    }
printf("\n");
}
