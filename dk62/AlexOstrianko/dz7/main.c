#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "tree.h"
#include "Tool.h"

int main(int argc, char *argv[]) {
	CharTree *Tree = createCharTree();
	insertCharValueToTree(Tree,'4');
	insertCharValueToTree(Tree,'1');
	insertCharValueToTree(Tree,'2');	
	insertCharValueToTree(Tree,'5');
	insertCharValueToTree(Tree,'3');
	insertCharValueToTree(Tree,'A');
	insertCharValueToTree(Tree,'8');
	insertCharValueToTree(Tree,'6');
	insertCharValueToTree(Tree,'7');
	insertCharValueToTree(Tree,'9');
	insertCharValueToTree(Tree,'E');
	insertCharValueToTree(Tree,'C');
	insertCharValueToTree(Tree,'B');
	insertCharValueToTree(Tree,'D');
	insertCharValueToTree(Tree,'F');
	printf("Select kind of printing:\n");	
	printf("1 - Symmetric printing\n");
	printf("2 - Plain printing\n");
	printf("3 - Back printing\n");
	int WayOfPrinting = EnterWay();
	printTree(Tree, WayOfPrinting);	
	printf("\nEnter the value you want to delete:");
	char ToDelete = EnterElementToDelete();
	printf("\nDeleting...\n");
	deleteNodeWithValue(Tree, ToDelete);
	printTree(Tree, WayOfPrinting);	
	printf("\nCurrent lenth of tree: %i\n",countNodesWithTree(Tree));
	destroyCharTree(Tree);
	return 0;
}
