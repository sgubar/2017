//#ifndef tree_h
#define tree_h

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
void printTree(CharTree *aTree);
void SymmetricPrintNode(CharNode *aNode);
void deleteNodeWithValue(CharTree *aTree, char aValue);
int interface(CharTree *aTree);

