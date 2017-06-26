#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "Node.h"

typedef struct __tagNode  DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;

DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);
void PlainPrintNode(DoubleNode *aNode);
void insertDoubleValueToTree(DoubleTree *aTree, double aValue);
int countNodesWithTree(DoubleTree *aTree);

void printTree(DoubleTree *aTree);

#endif tree_h 
