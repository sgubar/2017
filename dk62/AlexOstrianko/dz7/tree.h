#ifndef tree_h
#define tree_h

#include "Node.h"
#include <stdio.h>

typedef struct __tagNode CharNode;

typedef struct __tagTree
{
	CharNode *root;
	int count;
} CharTree;

CharTree *createCharTree();
void destroyCharTree(CharTree *aTree);

void insertCharValueToTree(CharTree *aTree, char aValue);
int countNodesWithTree(CharTree *aTree);

void printTree(CharTree *aTree, int Way);

#endif tree_h 
