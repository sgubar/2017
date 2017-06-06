#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} intNode;

typedef struct __tagTree
{
	intNode *root;
	int size;
} intTree;

// interface

intTree *createIntTree();
void destroyIntTree(intTree *aTree);

void insertIntValueToTree(intTree *aTree, int aValue);
int fillingAnTree(intTree *aTree);

intNode *findNodeWithValue(intTree *aTree, int aValue);

void printTreeToConsole(intTree *aTree);
void printNodeToConsole(intNode *aNode);

int countNodesWithTree(intTree *aTree);

int deleteNodeWithValue(intTree *aTree);

void doTestTree();

int scan();// just scanf with checking on idiot




#endif /* tree_h */
