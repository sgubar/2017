#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "Node.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{	printf("Value a Tree:\n");
	char value;
	int input;
	CharTree *Tree = createCharTree();
	insertCharValueToTree(Tree,'A');
	insertCharValueToTree(Tree,'E');
	insertCharValueToTree(Tree,'Z');	
	insertCharValueToTree(Tree,'J');
	insertCharValueToTree(Tree,'L');
	insertCharValueToTree(Tree,'U');
	insertCharValueToTree(Tree,'S');
	insertCharValueToTree(Tree,'B');
	insertCharValueToTree(Tree,'O');
	printTree(Tree);
	putchar('\n');
	
	interface(Tree);
	
	//printf("Enter value to delete: ");
	//scanf("%c", &value);
	//deleteNodeWithValue(Tree, value);
	printf("You Tree after operation on interface:\n");
	printTree(Tree);
	destroyCharTree(Tree);
}
