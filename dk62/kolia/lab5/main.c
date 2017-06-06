#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


void main()
{

	FloatTree *Tree = createFloatTree();



	insertfloatValueToTree(Tree, 21.22);
	insertfloatValueToTree(Tree, 2.22);
	insertfloatValueToTree(Tree, 61.22);
	insertfloatValueToTree(Tree, 11.22);
	insertfloatValueToTree(Tree, 71.22);
	insertfloatValueToTree(Tree, 81.22);
	insertfloatValueToTree(Tree, 11.53);
	insertfloatValueToTree(Tree, 73.22);

	int count = countNodesWithTree(Tree);
	printf("the count of nodes in tree :%d\n", count);

	FloatNode* search = findNodeWithValue(Tree, 61.22);

	if (search != NULL)
		printf("that node is in tree\n");
	else
		printf("that node isn't found\n");


	printTree(Tree);

	FloatNode *aNode = Tree->root;
	deleteNodeWithValue(Tree,aNode, 61.22);

	search = findNodeWithValue(Tree, 61.22);

	if (search != NULL)
		printf("that node is in tree\n");
	else
		printf("that node isn't found\n");

	count = 0;
	count = countNodesWithTree(Tree);
	printf("the count of nodes in tree :%d\n", count);

	printTree(Tree);

	destroyFloatTree(Tree);

	printf("\nThe Tree has been deleted!\n");

	_getch();

}
