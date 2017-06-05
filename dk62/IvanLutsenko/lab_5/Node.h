#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "tree.h"

typedef struct __tagTree Tree;

typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} intNode;

void destroyNode(intNode *aNode);
intNode *findNodeWithValue(Tree *aTree, int aValue);
intNode *createintNodeWithValue(int aValue);
void deleteNodeWithValue(Tree *aTree, int aValue);

#endif 