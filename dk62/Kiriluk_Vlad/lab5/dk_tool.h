#ifndef _dk_tool
#define _dk_tool
struct tree
{
	struct tree *left;
	struct tree *right;
	int data;
};

typedef struct tree Tree;


void AddNode(Tree **myTree, float value);
void PrintElements(Tree *myNode);
void DeleteElements(Tree *myNode);
Tree *Search(Tree **myTree, float value);

#endif
