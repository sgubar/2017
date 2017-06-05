#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Tool.h"

int main(int argc, char *argv[]) 
{
	Tree *Tree = createTree();
	for (int i = 1; i < 11; i++) 
	{
		insertValueToTree(Tree,i);
	}
	int WayOfPrinting = 1;
	printf("\nTree (symmetric):");
	printTree(Tree, WayOfPrinting);	
	printf("\nEnter the value you want to delete:");
	int ToDelete = EnterElementToDelete();
	printf("\nDeleting...\n");
	deleteNodeWithValue(Tree, ToDelete);
	printTree(Tree, WayOfPrinting);	
	printf("\nCurrent lenth of tree: %i\n",countNodesWithTree(Tree));
	printf("\nEnter the value you want to find:");
	int aValue;
	scanf("%d",&aValue);
	if (findNodeWithValue(Tree, aValue) != NULL)
		printf("\nFound element: %d\n",findNodeWithValue(Tree, aValue)->value);
	else 
	{
		printf("\nNo element found\n");
	}
	printf("\nDeleting tree...\n");
	destroyTree(Tree);
	return 0;
}