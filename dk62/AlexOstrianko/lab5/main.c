#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Tool.h"

int main(int argc, char *argv[]) {
	FloatTree *Tree = createFloatTree();
	insertFloatValueToTree(Tree,0.1);
	insertFloatValueToTree(Tree,0.2);
	insertFloatValueToTree(Tree,0.3);	
	insertFloatValueToTree(Tree,0.4);
	insertFloatValueToTree(Tree,0.5);
	insertFloatValueToTree(Tree,0.6);
	insertFloatValueToTree(Tree,0.7);
	insertFloatValueToTree(Tree,0.8);
	insertFloatValueToTree(Tree,0.9);
	insertFloatValueToTree(Tree,1.0);
	insertFloatValueToTree(Tree,1.1);
	insertFloatValueToTree(Tree,1.2);
	insertFloatValueToTree(Tree,1.3);
	insertFloatValueToTree(Tree,1.4);
	insertFloatValueToTree(Tree,1.5);
	printf("Select kind of printing:\n");	
	printf("1 - Symmetric printing\n");
	printf("2 - Plain printing\n");
	printf("3 - Back printing\n");
	int WayOfPrinting = EnterWay();
	printTree(Tree, WayOfPrinting);	
	printf("\nEnter the value you want to delete:");
	float ToDelete = EnterElementToDelete();
	printf("\nDeleting...\n");
	deleteNodeWithValue(Tree, ToDelete);
	printTree(Tree, WayOfPrinting);	
	printf("\nCurrent lenth of tree: %i\n",countNodesWithTree(Tree));
	destroyFloatTree(Tree);
	return 0;
}
