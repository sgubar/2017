#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
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
	printf("kool uzlow :%d\n", counter);
	
	printTree(Tree);
	printf("\n");
	printf(" ischem  4.4\n");
	FloatNode* find = findNodeWithValue(Tree, 4.4);
	if (find != NULL)
		printf("That node is in tree.\n");
	else
		printf("That node isn't found.\n");
		
	FloatNode *aNode = Tree->root;

	printf("We delete 6.6\n");
		printf("We want to find 6.6\n");
	 find = findNodeWithValue(Tree, 6.6);
	if (find != NULL)
		printf("That node is in tree\n");
	else
		printf("That node isn't found\n");
	counter=0;
	counter = counterNodes(Tree);
	printf("\n\n");
	printf("kool uzlov  :%d\n", counter);
	
	printTree(Tree);
	
	return 0;
}

