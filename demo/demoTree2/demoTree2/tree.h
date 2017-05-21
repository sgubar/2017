//
//  tree.h
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	short value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} ShortNode;

typedef struct __tagTree
{
	ShortNode *root;
	int count;
} ShortTree;

// interface
ShortTree *createShortTree();
void destroyShortTree(ShortTree *aTree);

void insertShortValueToTree(ShortTree *aTree, short aValue);

ShortNode *findNodeWithValue(ShortTree *aTree, short aValue);
void deleteNodeWithValue(ShortTree *aTree, short aValue);

void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);

void printTree(ShortTree *aTree);
int countNodesWithTree(ShortTree *aTree);

#endif /* tree_h */
