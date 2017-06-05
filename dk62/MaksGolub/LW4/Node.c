#include "List.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

DoubleNode *CreateNodeWithValue(double aValue)

{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

	theNode->value = aValue;
	theNode->next = NULL;
    theNode->prev = NULL;
    

	return theNode;
}

void FreeNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}


