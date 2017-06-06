#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>


void main()
{
	FloatTree *Tree = createFloatTree();

	insertFloatValueToTree(Tree, 18.98);
	insertFloatValueToTree(Tree, 3.25);
	insertFloatValueToTree(Tree, 61.22);
	insertFloatValueToTree(Tree, 14.88);
	insertFloatValueToTree(Tree, 14.58);
	insertFloatValueToTree(Tree, 12.12);
	insertFloatValueToTree(Tree, 71.22);
	insertFloatValueToTree(Tree, 12.55);
	insertFloatValueToTree(Tree, 2.28);
	insertFloatValueToTree(Tree, 73.22);

	int nodeCount = countNodesWithTree(Tree);
	printf("We have %d nodes in our tree.\n\n", nodeCount);

	printf("Searching the node with the value 71.22.\n");
	FloatNode* search = findNodeWithValue(Tree, 71.22);

	if (search != NULL)
	{
		printf("Search ended. This node is in the tree.\n\n");
	}	
	else
	{
		printf("Search ended. This node is not in the tree.\n\n");
	}
		
	printTree(Tree);

	FloatNode *aNode = Tree->root;
	
	printf("\n\nDeleting the node with the value 71.22.");
	deleteNodeWithValue(Tree, aNode, 71.22);

	printf("\n\nSearching the node with the value 71.22.\n");
	search = findNodeWithValue(Tree, 71.22);
	
	if (search != NULL)
		printf("\nSearch ended. This node is in the tree.\n\n");
	else
		printf("\nSearch ended. This node is not in the tree.\n\n");

	nodeCount = 0;
	nodeCount = countNodesWithTree(Tree);
	printf("We have %d nodes in our tree.\n\n", nodeCount);

	printTree(Tree);

	destroyFloatTree(Tree);

	printf("\n\nThe binaryTree has been successfully deleted!\n");

	_getch();
}
