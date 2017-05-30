#ifndef Node_h
#define Node_h

//#include "tree.h"
#include <stdio.h>

typedef struct __tagTree CharTree;

typedef struct __tagNode
{
	char value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
	
}CharNode;
void destroyNode(CharNode *aNode);
CharNode *createCharNodeWithValue(char aValue);
CharNode *findNodeWithValue(CharTree *aTree, char aValue);

#endif Node_h
