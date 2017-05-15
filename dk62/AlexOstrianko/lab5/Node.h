#ifndef Node_h
#define Node_h

#include <stdio.h>
#include "tree.h"

typedef struct __tagTree FloatTree;

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} FloatNode;

void destroyNode(FloatNode *aNode);
FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);
FloatNode *createFloatNodeWithValue(float aValue);
void deleteNodeWithValue(FloatTree *aTree, float aValue);

#endif Node_h
