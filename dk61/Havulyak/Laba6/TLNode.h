#ifndef TLNode_h
#define TLNode_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __DoubleNode DoubleNode;

struct __DoubleNode
{
	double value;
	DoubleNode *nextNode;
	DoubleNode *previousNode;
};

DoubleNode *TLCreateNodeWithDoubleValue(double aValue);
void TLFreeDoubleNode(DoubleNode *aNode);

#endif
