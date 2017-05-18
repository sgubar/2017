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
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} Double_Node;

typedef struct __tagTree
{
	Double_Node *root;
	int count;
} DoubleTree;

// interface
DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);

Double_Node *findNodeWithValue(DoubleTree *aTree, double aValue);
void deleteNodeWithValue(DoubleTree *aTree, double aValue);

void mergeTrees(DoubleTree *aTreeDst, DoubleTree *aTreeSrc);

//void print (Double_Node *t,int u);

int countNodesWithTree(DoubleTree *aTree);

void printDoubleTree(DoubleTree *aTree, int aTypeOfPassage);

void SymmetricPassage_And_PrintTree(Double_Node *aNode);
void PlainPassage_And_PrintTree(Double_Node *aNode);
void BackPassage_And_PrintTree(Double_Node *aNode);

#endif /* tree_h */
