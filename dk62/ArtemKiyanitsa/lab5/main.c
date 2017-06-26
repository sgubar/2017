#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Tool.h"

int main(int argc, char *argv[]) {
	DoubleTree *Tree = createDoubleTree();
	insertDoubleValueToTree(Tree,0.11);
	insertDoubleValueToTree(Tree,0.25);
	insertDoubleValueToTree(Tree,0.33);	
	insertDoubleValueToTree(Tree,0.41);
	insertDoubleValueToTree(Tree,0.55);
	insertDoubleValueToTree(Tree,0.62);
	insertDoubleValueToTree(Tree,0.75);
	insertDoubleValueToTree(Tree,0.86);
	insertDoubleValueToTree(Tree,0.92);
	insertDoubleValueToTree(Tree,1.01);
	insertDoubleValueToTree(Tree,1.15);
	insertDoubleValueToTree(Tree,1.24);
	insertDoubleValueToTree(Tree,1.31);
	insertDoubleValueToTree(Tree,1.42);
	insertDoubleValueToTree(Tree,1.54);
	printTree(Tree);	
	printf("\nEnter the value you want to delete:");
	double ToDelete = EnterElementToDelete();
	printf("\nDeleting...\n");
	deleteNodeWithValue(Tree, ToDelete);
	printTree(Tree);	
	printf("\nCurrent lenth of tree: %i\n",countNodesWithTree(Tree));
	destroyDoubleTree(Tree);
	return 0;
}
