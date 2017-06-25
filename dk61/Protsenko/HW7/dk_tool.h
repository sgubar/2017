#ifndef dk_tool
#include <stdio.h>
#include <stdlib.h>
#define dk_tool

#include <stdio.h>

typedef struct __tagNode CharNode;

typedef struct __tagNode
{
	char value;
	CharNode *leftChild;
	CharNode *rightChild;
}CharNode;

typedef struct __tagTree
{
	CharNode *root;
	int count;
}CharTree;

// interface
CharTree *createCharTree();
void destroyCharTree(CharTree *aTree);
void InsertCharValueToTree(CharTree *aTree, char aValue);
CharNode* FindMin(CharNode *aNode);
CharNode *deleteNodeWithValue(CharTree *aTree, CharNode* aNode, char aValue);
void printTree(CharTree*aTree);
void BackPrint(CharNode *aNode);
int countNodesWithTree(CharTree *aTree);

#endif
