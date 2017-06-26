#include "TLNode.h"
#include <stdlib.h>
#include <stdio.h>

DoubleNode *TLCreateNodeWithDoubleValue(double aValue)
{
	DoubleNode *theResult = (DoubleNode *)malloc(sizeof(DoubleNode));
	
	theResult->value = aValue;
	theResult->nextNode = NULL;
	theResult->previousNode = NULL;
	
	return theResult;
}

void TLFreeDoubleNode(DoubleNode *theNode)
{
	if (NULL != theNode)
	{
		free(theNode);
	}
}
