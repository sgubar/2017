//
//  SingleLinkedNode.c
//  demoList
//
//  Created by Slava Gubar on 3/2/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "SingleLinkedNode.h"
#include <stdlib.h>

IntNode *SLCreateNodeWithIntValue(int aValue)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	
	theResult->value = aValue;
	theResult->nextNode = NULL;
	
	return theResult;
}

void SLFreeIntNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}
