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

<<<<<<< HEAD

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
=======
// interface
ShortTree *createShortTree();
void destroyShortTree(ShortTree *aTree);

void insertShortValueToTree(ShortTree *aTree, short aValue);

ShortNode *findNodeWithValue(ShortTree *aTree, short aValue);
void deleteNodeWithValue(ShortTree *aTree, short aValue);

void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);

void printTree(ShortTree *aTree);
int countNodesWithTree(ShortTree *aTree);
>>>>>>> origin/master

#endif /* tree_h */
