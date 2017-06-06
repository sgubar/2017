#ifndef tree
#define tree

#include <stdio.h>

typedef struct __tagNode FloatNode;

typedef struct __tagNode
{
	float value;
	FloatNode *leftChild;
	FloatNode *rightChild;
} FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
} FloatTree;


FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertfloatValueToTree(FloatTree *aTree, float aValue);
FloatNode* FindMin(FloatNode *aNode);
FloatNode* findNodeWithValue(FloatTree *aTree, float aValue);
FloatNode *deleteNodeWithValue(FloatTree *aTree, FloatNode* aNode, float aValue);
void printTree(FloatTree*aTree);
void BackPrint(FloatNode *aNode);
int countNodesWithTree(FloatTree *aTree);

#endif
