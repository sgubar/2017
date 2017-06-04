#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main() 
{
FloatTree *Tree = createFloatTree();



	floatValueToTree(Tree, 1.1);
	floatValueToTree(Tree, 2.2);
	floatValueToTree(Tree, 3.3);
	floatValueToTree(Tree, 4.4);
	floatValueToTree(Tree, 5.5);
	floatValueToTree(Tree, 6.6);
	floatValueToTree(Tree, 7.7);
	floatValueToTree(Tree, 8.8);

	int counter = counterNodes(Tree);
	printf("The number of nodes in  the tree :%d\n", counter);
	
	printTree(Tree);
	
	FloatNode *aNode = Tree->root;
	deleteNodeWithValue(Tree,aNode, 6.6);
	
	counter=0;
	counter = counterNodes(Tree);
	printf("The number of nodes in the tree :%d\n", counter);
	printf("\n\n");
	printTree(Tree);
	
	destroyFloatTree(Tree);
	return 0;
}
