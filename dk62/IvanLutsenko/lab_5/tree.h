#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "Node.h"

typedef struct __tagNode  FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
} Tree;

Tree *createTree();
void destroyTree(Tree *aTree);

void insertValueToTree(Tree *aTree, int aValue);
int countNodesWithTree(Tree *aTree);

void printTree(Tree *aTree, int Way);

#endif 