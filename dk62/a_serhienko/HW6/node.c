#include "node.h"
#include <malloc.h>
#include <stdlib.h>

Node *createNodeWithfloatValue(float aValue)
{
    Node *theResult = (Node *)malloc(sizeof(Node));

	theResult->value = aValue;
	theResult->next = NULL;

	return theResult;
}

void FreefloatNode(Node *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}