//
//  CharBinarTree.h
//  Lab5
//
//  Created by air on 5/21/17.
//  Copyright © 2017 Laba5. All rights reserved.
//
#include <stdio.h>

#ifndef CharBinarTree_h
#define CharBinarTree_h

#include <stdio.h>

typedef struct __tagNode
{
    char value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} Char_Node;

typedef struct __tagTree
{
    Char_Node *root;
    int count;
} CharTree;


//Create Binar Tree
CharTree *createCharTree();

//Free Tree from stdIN
void destroyCharTree(CharTree *aTree);

//Add Node to Binar Tree
void insertCharValueToTree(CharTree *aTree, char aValue);


//Find Node in Binar Tree
Char_Node *findNodeWithValue(CharTree *aTree, char aValue);


//Counter Nodes
int count_NodesOfTree(CharTree *aTree);

//Show Nodes
void printCharTree(CharTree *aTree, int aTypeOfPassage);

//Delete Node from Tree
Char_Node* DeleteNodeFromTree(CharTree *aTree,Char_Node *Node, char data);
Char_Node* FindMinNodeInBinarTree(Char_Node* root);


/*              the types of Passage            */
void SymmetricPassage_And_PrintNode(Char_Node *aNode);
void PlainPassage_And_PrintNode(Char_Node *aNode);
void BackPassage_And_PrintNode(Char_Node *aNode);


#endif /* CharBinarTree_h */
