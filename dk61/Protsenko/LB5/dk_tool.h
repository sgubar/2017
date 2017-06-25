#ifndef dk_tool
#include <stdio.h>
#include <stdlib.h>
#define dk_tool

#include <stdio.h>

typedef struct __tagNode FloatNode;

typedef struct __tagNode
{
	float value;
	FloatNode *leftChild;
	FloatNode *rightChild;
}FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
}FloatTree;

// interface
FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);
void InsertFloatValueToTree(FloatTree *aTree, float aValue);
FloatNode* FindMin(FloatNode *aNode);
FloatNode *deleteNodeWithValue(FloatTree *aTree, FloatNode* aNode, int aValue);
void printTree(FloatTree*aTree);
void BackPrint(FloatNode *aNode);
int countNodesWithTree(FloatTree *aTree);

#endif
