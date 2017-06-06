#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, char *argv[]) 
{
	FloatTree *Tree = createFloatTree();
	
	floatValueToTree(Tree, 11.1);
	floatValueToTree(Tree, 22.2);
	floatValueToTree(Tree, 33.3);
	floatValueToTree(Tree, 44.4);
	floatValueToTree(Tree, 55.5);
	floatValueToTree(Tree, 66.6);
	floatValueToTree(Tree, 77.7);
	floatValueToTree(Tree, 88.8);
	
	int counter = counterNodes(Tree);
	printf("The number of nodes in  the tree :%d\n", counter);
	
	printTree(Tree);
	printf("\n");
	printf("We want to find 77.7\n");
	FloatNode* find = findNodeWithValue(Tree, 77.7);
	if (find != NULL)
		printf("That node is in tree.\n");
	else
		printf("That node isn't found.\n");
		
	FloatNode *aNode = Tree->root;
	deleteNodeWithValue(Tree,aNode, 66.6);
	printf("We delete 66.6\n");
		printf("We want to find 66.6\n");
	 find = findNodeWithValue(Tree, 66.6);
	if (find != NULL)
		printf("That node is in tree\n");
	else
		printf("That node isn't found\n");
	counter=0;
	counter = counterNodes(Tree);
	printf("\n\n");
	printf("The number of nodes in the tree :%d\n", counter);
	
	printTree(Tree);
	
	destroyFloatTree(Tree);
	return 0;
}
