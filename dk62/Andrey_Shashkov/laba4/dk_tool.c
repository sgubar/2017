#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "dk_tool.h"

void gstring(char *min)
{
char *buf = NULL;
unsigned int cp = 0, n = 0;
int c;

while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
	if(n + 1 > cp)
    	{
        if(!cp)
            cp = 32;
        else if(cp <= UINT_MAX)		
            cp += 32;
        else
            {
            free(buf);
            return;
            }
        
		char *tmp = realloc(buf, sizeof(char) * cp);
        buf = tmp;
        tmp = NULL;
        
        if(!buf)
			{
			free(buf);
			return;
			}
		}
	buf[n++] = c;
    }
if(!n && c == EOF)
    return;

min = realloc(min, sizeof(char) * (n + 1));
strncpy(min, buf, n);
free(buf);

min[n] = '\0';
}



void crFirst_push(Node **head, char val)
{
Node *tmp = (Node *) malloc(sizeof(Node));
tmp->value = val;
tmp->next = (*head);
(*head) = tmp;
tmp = NULL;
}



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
