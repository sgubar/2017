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
void ValueToTree(FloatTree *aTree, float aValue);
int checkNodes(FloatTree *aTree); //counting of nodes
void printTree(FloatTree *aTree);
void PlainPrint(FloatNode *aNode);



#endif 
