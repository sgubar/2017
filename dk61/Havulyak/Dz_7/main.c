#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main(int argc, const char * argv[]) 
{
	CharTree *Tree = createCharTree();
	
	CharValueToTree(Tree, 'a'); 
	CharValueToTree(Tree, 'b');
	CharValueToTree(Tree, 'c');
	CharValueToTree(Tree, 'd');
	CharValueToTree(Tree, 'e');
	CharValueToTree(Tree, 'f');
	CharValueToTree(Tree, 'g');
	CharValueToTree(Tree, 'h');
	
	int counter = counterNodes(Tree);
	printf("The number of nodes in  the tree :%d\n", counter);
	
	printTree(Tree);
	printf("\n");
	printf("We want to find g\n");
	CharNode* find = findNodeWithValue(Tree, 'g');
	if (find != NULL)
		printf("That node is in tree.\n");
	else
		printf("That node isn't found.\n");
		
	CharNode *aNode = Tree->root;
	deleteNodeWithValue(Tree,aNode, 'f');
	printf("We delete f\n");
		printf("We want to find f\n");
	 find = findNodeWithValue(Tree, 'f');
	if (find != NULL)
		printf("That node is in tree\n");
	else
		printf("That node isn't found\n");
	counter=0;
	counter = counterNodes(Tree);
	printf("\n\n");
	printf("The number of nodes in the tree :%d\n", counter);
	
	printTree(Tree);
	
	destroyCharTree(Tree);
	return 0;
}
