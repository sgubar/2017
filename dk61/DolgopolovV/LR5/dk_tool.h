#ifndef dk_tool
#define dk_tool
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct tree
{
	double value;
	struct tree *left;
	struct tree *right;
}b_tree;

b_tree* add(b_tree *atree);
b_tree* del(b_tree *atree);
void print(b_tree *atree);
void PrintElements(b_tree *myNode);
void destr(b_tree *aNode);

#endif
