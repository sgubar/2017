#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

//Node description
typedef struct __tagNode
{
	int value;
	int level;
	int mark;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} TreeNode;

typedef struct __tagTree
{
	TreeNode *root;
	int count;
} IntTree;


//interface
IntTree *createIntTree(void);
TreeNode *createTreeNodeWithValue(int aValue);
int insertIntValueToTree(IntTree *aTree, int aValue);
int deleteNodeWithValue(IntTree *aTree, int aValue);
void destroyIntTree(IntTree *aTree);
void destroyNode(TreeNode *aNode);

TreeNode *findNodeWithValue(IntTree *aTree, int aValue);
TreeNode *findParentOfTheNode(IntTree *aTree, TreeNode *aNode);
TreeNode *findReceiver(IntTree *aTree, TreeNode *aNodeToDestroy);

//print in the console
void printTreeNode(TreeNode *aNode);
void printTree(IntTree *aTree, void(*method)(TreeNode *));

// from leaves to parents
void backward(TreeNode *aNode);

//check nodes by recursion:  MIN -> {..} -> MAX value
void symmetry(TreeNode *aNode);

// root - left - right
void straight(TreeNode *aNode);


//**graphics
void DrawTreeNodes(TreeNode *aNode, int direct );
void Show_XY_pos(int x_mouse, int y_mouse);
//graphics**//

//show information about deleting node
void analysis(TreeNode *aNode);

//using in drawTreeNode to get position for new Node
int getNodePos_X(IntTree *aTree, TreeNode *aNode);
int getNodePos_Y(IntTree *aTree, TreeNode *aNode);

//return number in area [a..z]
int randomIntFromRange (int min, int max);

//if state 0 = fill with rand values
//otherwise fill with sequence [0,1,2,3... amount]
IntTree *getIntTreeWithRandValues( int amount, bool state );

//find and mark the Node by coordinates
//TreeNode *MarkNodeToDelete(IntTree *aTree, IntList *aList, int x_click, int y_click);

//after deleting a node, refresh depth-level for correct drawing
void refreshLevel(IntTree *aTree, TreeNode* aNode);

//non-implemented functions
void mergeTrees(IntTree *aTreeDst, IntTree *aTreeSrc);
#endif // BINARY_TREE_H_INCLUDED
