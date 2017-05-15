#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "Node.h"

typedef struct __tagNode  FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
} FloatTree;

FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, float aValue);
int countNodesWithTree(FloatTree *aTree);

void printTree(FloatTree *aTree, int Way);

#endif tree_h 
