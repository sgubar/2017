#ifndef dk_tools_h
#define dk_tools_h
typedef struct tagTree
{
	struct tree *left;
	struct tree *right;
	int data;
}Tree;



void AddNode(Tree **tagTree, int val);
void TreePrint(Tree *tagNode);
void DestroyTree(Tree *tagNode);
Tree *Search(Tree **tagTree, int val);

#endif
