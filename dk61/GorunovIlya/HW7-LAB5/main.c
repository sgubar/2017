#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	FloatTree* aTree = createFloatTree();
	
	insertFloatValueToTree(aTree,2.345);
	insertFloatValueToTree(aTree,7.345);
	insertFloatValueToTree(aTree,6.345);
	insertFloatValueToTree(aTree,4.345);
	insertFloatValueToTree(aTree,8.345);
	insertFloatValueToTree(aTree,5.345);
	insertFloatValueToTree(aTree,9.345);
	insertFloatValueToTree(aTree,3.345);
	
	ReversePrintTree(aTree);
	
	deleteNodeWithValue(aTree,6.345);
	printf("\n----------\n");
	ReversePrintTree(aTree);
	
	destroyFloatTree(aTree);
	
//	FloatNode *theResult = findNodeWithValue(aTree,3.345);
//	if(theResult == -3)
//	{
//		printf("Not found!");
//		
//	}
//	else
//	{
//		printf("Found!\n");
//	}
	
	
	
	
	
	return 0;
}
