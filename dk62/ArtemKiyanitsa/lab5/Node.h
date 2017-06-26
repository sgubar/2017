#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "tree.h"

typedef struct __tagTree DoubleTree;

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

void destroyNode(DoubleNode *aNode);
DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
DoubleNode *createDoubleNodeWithValue(double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

#endif Node_h
