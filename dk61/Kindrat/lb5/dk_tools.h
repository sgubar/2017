#ifndef _dk_tools
#define _dk_tools
struct tree
{
	struct tree *leftson;
	struct tree *rightson;
	int data;
};

typedef struct tree Tree;


void AddNode(Tree **thisTree, int chislo);
void PrintTree(Tree *thisNode);
void DeleteElements(Tree *thisNode);
Tree *Search(Tree **thisTree, int chislo);

#endif
