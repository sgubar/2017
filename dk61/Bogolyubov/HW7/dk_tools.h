#ifndef dk_tools_h
#define dk_tools_h
typedef struct tagTree
{
	struct tree *left;
	struct tree *right;
	double data;
}Tree;



void AddNode(Tree **tagTree, double val);
void TreePrint(Tree *tagNode);
void DestroyTree(Tree *tagNode);
Tree *Search(Tree **tagTree, double val);

#endif
