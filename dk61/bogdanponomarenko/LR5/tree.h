#ifndef tree
#define tree

#include <stdio.h>

typedef struct __tagNode IntNode;

typedef struct __tagNode
{
	int value;
	IntNode *leftChild;
	IntNode *rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode *root;
	int count;
} IntTree;

// interface
IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void InsertIntValueToTree(IntTree *aTree, int aValue);
IntNode* FindMin(IntNode *aNode);
IntNode* findNodeWithValue(IntTree *aTree, int aValue);
IntNode *deleteNodeWithValue(IntTree *aTree, IntNode* aNode, int aValue);
void printTree(IntTree*aTree);
void BackPrint(IntNode *aNode);
int countNodesWithTree(IntTree *aTree);

void Tree();
#endif
