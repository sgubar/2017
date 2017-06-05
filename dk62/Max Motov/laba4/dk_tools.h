#ifndef _dk_tools
#define _dk_tools
struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
};

typedef struct tree Tree;


void AddNode(Tree **myTree, int value);
void PrintElements(Tree *myNode);
void DeleteElements(Tree *myNode);
Tree *Search(Tree **myTree, int value);

#endif // !_dk_tools
