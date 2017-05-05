#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void crFirst_push(Node **head, int val)
{
Node *tmp = (Node *) malloc(sizeof(Node));
tmp->value = val;
tmp->next = (*head);
(*head) = tmp;
tmp = NULL;
}

//-------------------------------------------------------------------------

int delFirst_pop(Node **head)
{
if(!head)
    exit(-1);

Node *last = (*head);
int el = last->value;

(*head) = (*head)->next;
free(last);
return el;
}

//-------------------------------------------------------------------------

int get_num(Node *head, Node *tmp)
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

int getVal_num(Node *head, int num)
{
if(!head)
    exit(-3);

int i = 0;
while(i++ < num && head)
    head = head->next;

return head->value;
}

//-------------------------------------------------------------------------

Node *get_el(Node *head, int num)
{
if(!head)
    exit(-5);

int i = 0;
while(i++ < num && head)
    head = head->next;

return head;
}

//-------------------------------------------------------------------------

Node *getLast_el(Node *head)
{
if(!head)
    exit(-6);

while(head->next)
    head = head->next;

return head;
}

//-------------------------------------------------------------------------

void crLast_el(Node *head, int value)
{
if(!head)
    exit(-7);

Node *last = getLast_el(head);
Node *tmp = (Node *) malloc(sizeof(Node));
tmp->value = value;
tmp->next = NULL;
last->next = tmp;
}

//-------------------------------------------------------------------------

Node *getPre_last(Node *head)
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

Node *getPre_el(Node *head, Node *tmp)
{
if(!head || !tmp)
    exit(-9);

while(head->next != tmp && !(head->next))
	head = head->next;

return head;
}

//-------------------------------------------------------------------------

int delLast_pop(Node **head)
{
if(!head || !(*head))
    exit(-10);

Node *last = getPre_last(*head);
int val = last->value;
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

void insert_el(Node *head, int num, int val)
{
if(!head)
    exit(-11);

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

int del_el(Node **head, int num)
{
if(!head || !(*head))
    exit(-12);

if(!num)
    return delFirst_pop(head);
else
	{
    Node *last = get_el(*head, num - 1);
    Node *el  = last->next;
    int val = el->value;

    last->next = el->next;
    free(el);
    return val;
    }
}

//-------------------------------------------------------------------------

void delList(Node **head)
{
if(!head)
    exit(-13);

Node* last = NULL;
while((*head)->next)
	{
    last = (*head);
    (*head) = (*head)->next;
    free(last);
    }
free(*head);
}

//-------------------------------------------------------------------------

void getVal_arr(Node **head, int *anArray, int aSize)
{
if(!anArray || !aSize)
    exit(-14);

do{
    crFirst_push(head, anArray[--aSize]);
}while(aSize);
}

//-------------------------------------------------------------------------

int *getVal_list(Node *head)
{
if(!head)
    exit(-15);

int i, len = getLength(head);
int *aArray = (int *) malloc(sizeof(int) * len);
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
    exit(-16);

while(head)
	{
    printf("%i ", head->value);
    head = head->next;
    }
printf("\n");
}

//-------------------------------------------------------------------------

int getLength(Node *head)
{
if(!head)
    exit(-17);

int i = 0;
while(head)
	{
    head = head->next;
	i++;
	}
return i;
}

//-------------------------------------------------------------------------

void change_el(Node *head, int num, int val)
{
if(!head)
    exit(-18);

int i = 0;
while(i++ < num && head->next)
    head = head->next;

head->value = val;
}

//-------------------------------------------------------------------------

void qSortList(Node *left, Node *right)
{
if(!left || !right)
    exit(-19);

if(left == right)
    return;

else if(left->next == right && left->value > right->value)
    swap_el(left, right);

else
	{
    Node *last = left;
    Node *current = left;
    
    do{
        current = current->next;
        
        if(current->value < left->value)
			{
            last = last->next;
            swap_el(last, current);
            }
    }while(current != right);
    
    swap_el(left, last);
    qSortList(left, last);
    
    if(last != right)
        qSortList(last->next, right);
    
	last = NULL;
	current = NULL;
    }
}

//-------------------------------------------------------------------------

void swap_el(Node *a, Node *b)
{
if(!a || !b)
    exit(-20);

if(a == b || a->value == b->value)
	return;

int tmp = a->value;
a->value = b->value;
b->value = tmp;
}

//-------------------------------------------------------------------------


