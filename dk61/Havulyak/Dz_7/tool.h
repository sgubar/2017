#ifndef tool_h
#define tool_h
#include <stdio.h>

typedef struct __tagNode CharNode;

typedef struct __tagNode
{
	char value;
	CharNode *leftChild;
	CharNode *rightChild;
} CharNode;

typedef struct __tagTree
{
	CharNode *root;
	int count;
} CharTree;

CharTree *createCharTree();
void CharValueToTree(CharTree *aTree, char aValue);
int counterNodes(CharTree *aTree);
void printTree(CharTree *aTree);
void destroyCharTree(CharTree *aTree);

CharNode* findNodeWithValue(CharTree *aTree, char aValue);
void BackPrint(CharNode *aNode);
void deleteNode(CharNode *aNode);
CharNode* FindMin(CharNode* aNode);
void SymmetricPrint(CharNode *aNode);
void PlainPrint(CharNode *aNode);
CharNode *deleteNodeWithValue(CharTree *aTree, CharNode* aNode, char aValue);


#endif 
