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


	int counter = counterNodes(Tree);
	printf("kool uzlow :%d\n", counter);
	
	printTree(Tree);
	printf("\n");
	printf(" ischem  2.2\n");
	FloatNode* find = findNodeWithValue(Tree, 2.2);
	if (find != NULL)
		printf("That node is in tree.\n");
	else
		printf("That node isn't found.\n");
		
	FloatNode *aNode = Tree->root;

	printf("We delete 3.3\n");
		printf("We want to find 3.3\n");
	 find = findNodeWithValue(Tree, 3.3);
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

