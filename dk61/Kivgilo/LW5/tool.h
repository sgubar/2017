//#ifndef tool_h
#define tool_h

#include <stdio.h>

typedef struct __tagNode FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
	
}FloatTree;

FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);
void insertFloatValueToTree(FloatTree *aTree, float aValue);
void printTree(FloatTree *aTree);
void SymmetricPrintNode(FloatNode *aNode);
void deleteNodeWithValue(FloatTree *aTree, float aValue);
int interface(FloatTree *aTree);
