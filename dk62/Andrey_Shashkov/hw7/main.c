#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Node.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{	printf("Value a Tree:\n");
	float value;
	int input;
	FloatTree *Tree = createFloatTree();
	insertFloatValueToTree(Tree, 3.55);
	insertFloatValueToTree(Tree, 6.5);
	insertFloatValueToTree(Tree, 9.2);	
	insertFloatValueToTree(Tree, 6.98);
	insertFloatValueToTree(Tree, 12.4);
	insertFloatValueToTree(Tree, 56.45);
	insertFloatValueToTree(Tree, 34.5);
	insertFloatValueToTree(Tree, 56.4);
	insertFloatValueToTree(Tree, 98);
	printTree(Tree);
	putchar('\n');
	
	interface(Tree);
	
	printf("You Tree after operation on interface:\n");
	printTree(Tree);
	destroyFloatTree(Tree);
}
