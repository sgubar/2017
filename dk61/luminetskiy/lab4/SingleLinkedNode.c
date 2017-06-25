//
// Created by 28-07-2014 on 20.06.2017.
//

#include "SingleLinkedNode.h"
#include "SingleLinkedList.h"
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