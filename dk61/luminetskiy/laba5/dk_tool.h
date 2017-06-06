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



#endif 
