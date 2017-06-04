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
void floatValueToTree(FloatTree *aTree, float aValue);
int counterNodes(FloatTree *aTree);
void printTree(FloatTree *aTree);
void BackPrint(FloatNode *aNode);
void destroyFloatTree(FloatTree *aTree);
void deleteNode(FloatNode *aNode);
FloatNode* FindMin(FloatNode* aNode);
void SymmetricPrint(FloatNode *aNode);
void PlainPrint(FloatNode *aNode);
FloatNode *deleteNodeWithValue(FloatTree *aTree, FloatNode* aNode, float aValue);

#endif 
