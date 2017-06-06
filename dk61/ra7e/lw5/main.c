#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

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


	return 0;
}
