#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

void addElement(Node **theNode, char val)
{
	Node *aNode = (Node *) malloc(sizeof(Node));
	aNode->value = val;
	aNode->next = (*theNode);
	(*theNode) = aNode;
	aNode = NULL;
}

void deleteList(Node **theNode)
{
	if(theNode != NULL)
	{
		Node *del = NULL;
		while((*theNode)->next)
		{
	    	del = *theNode;
	    	*theNode = (*theNode)->next;
	    	free(del);
	    }
		free(*theNode);
		*theNode = NULL;
	}
}

void printList(Node *aNode)
{
	if(aNode)
	{
		while(aNode)
		{
	    	printf("%c", aNode->value);
	    	aNode = aNode->next;
	    }
	}
}
