#ifndef npda_h
#define noda_h

#include <stdio.h>

typedef struct __tagTree FloatTree;

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
	
}FloatNode;

void destroyNode(FloatNode *aNode);
FloatNode *createFloatNodeWithValue(float aValue);
FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);

#endif noda_h
