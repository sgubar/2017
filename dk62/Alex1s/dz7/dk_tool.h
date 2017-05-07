#ifndef dk_tool_h
#define dk_tool_h

typedef struct element
{
	int value;
	struct element *left;
	struct element *right;
	struct element *parent;
}Node;

typedef struct aTree
{
	int count;
	Node *root;
}Tree;

Tree *createTree();									//create base of tree
void destroyTree(Tree *aTree);						//destroy base of tree
Node *createNode(Node *aParent, int val);			//create element with val value
void destroyNode(Node *aNode);						//destroy element

void insert_el(Tree *aTree, int val);				//insert element with val value
void change_el(Node *aNode, int val);				//change element with aNode pointer
void del_el(Tree *aTree, Node *aNode);				//delete element
void delVal_el(Tree *aTree, Node *aNode, int val);	//delete element with val value

Node *minVal(Node *aNode);							//return min value after aNode pointer
Node *maxVal(Node *aNode);							//return max value after aNode pointer
Node *search_v(Node *aNode, int val);				//return pointer on element with val value

void preorderPrint(Node *aNode);					//print: root, left, right
void inorderPrint(Node *aNode);						//print: left, root, right
void postorderPrint(Node *aNode);					//print: left, right, root
void print(Tree *aTree, int type);					//print tree

#endif
