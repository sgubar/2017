#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
int main() 
{

FloatTree *Tree = createFloatTree();

	ValueToTree(Tree, 1.1);
	ValueToTree(Tree, 2.2);
	ValueToTree(Tree, 3.3);
	ValueToTree(Tree, 4.4);


	int counter = checkNodes(Tree);
	printf("Number of nodes :%d\n", counter);
	
	printTree(Tree);
	printf("\n");
	printf("Lets's find  2.2\n");
	FloatNode* find = findNodeWithValue(Tree, 2.2);
	if (find != NULL)
		printf("That node is in tree.\n");
	else
		printf("Node not found.\n");
		
	FloatNode *aNode = Tree->root;
             printf("We want to find 3.3\n");
	 find = findNodeWithValue(Tree, 3.3);
	if (find != NULL)
		printf("That node is in tree\n");
	else
		printf("Node not found\n");
	counter=0;
	counter = checkNodes(Tree);
	printf("\n\n");
	printf("Number of nodes  :%d\n", counter);
	
	printTree(Tree);
	
	return 0;
}

