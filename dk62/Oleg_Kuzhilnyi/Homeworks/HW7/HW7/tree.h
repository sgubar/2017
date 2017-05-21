#ifndef tree_h
#define tree_h

#include <stdio.h>

//Create Binar Tree
DoubleTree *createDoubleTree();

//Free Tree from stdIN
void destroyDoubleTree(DoubleTree *aTree);

//Add Node to Binar Tree
void insertDoubleValueToTree(DoubleTree *aTree, double aValue);


//Find Node in Binar Tree
Double_Node *findNodeWithValue(DoubleTree *aTree, double aValue);

//Show Nodes
void printDoubleTree(DoubleTree *aTree, int aTypeOfPassage);

//Delete Node from Tree
Double_Node* DeleteNodeFromTree(DoubleTree *aTree,Double_Node *Node, double data);
Double_Node* FindMinNodeInBinarTree(Double_Node* root);


/*              the types of Passage            */
void SymmetricPassage_And_PrintNode(Double_Node *aNode);
void PlainPassage_And_PrintNode(Double_Node *aNode);
void BackPassage_And_PrintNode(Double_Node *aNode);

#endif /* tree_h */
