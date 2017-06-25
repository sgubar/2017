#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

typedef struct tagNode
{
    int value;
    struct tagNode *leftChild;
    struct tagNode *rightChild;
} IntNode;

typedef struct tagTree
{
    IntNode *root;
    int count;
} intTree;

intTree *createIntTree();

void destroyIntTree(intTree *aTree);

void insertIntValueToTree(intTree *aTree, int aValue);

void deleteNodeWithValue(intTree *aTree, int aValue);

int countNodesWithTree(intTree *aTree);

void printTree(intTree *aTree);

void plainPrintNode(IntNode *aNode);

#endif /* tree_h */
