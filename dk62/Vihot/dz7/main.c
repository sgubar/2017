#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	DoubleDrevo *Drevo = createDoubleDrevo();
	insertdoubleElementToDrevo(Drevo, 56.1652);
	insertdoubleElementToDrevo(Drevo, 65.1685);
	insertdoubleElementToDrevo(Drevo, 23.646);
	insertdoubleElementToDrevo(Drevo, 18.3685);
	insertdoubleElementToDrevo(Drevo, 76.9886);
	insertdoubleElementToDrevo(Drevo, 82.165);
	insertdoubleElementToDrevo(Drevo, 92.1652);
	insertdoubleElementToDrevo(Drevo, 34.1652);
	int count = countNodesWithDrevo(Drevo);
	double forsearch=82.165;
	DoubleNode* search = findNodeWithElement(Drevo, forsearch);
	printDrevo(Drevo,count);
	if (search != NULL)
		printf("Element %f naiden!\n",forsearch);
	else
		printf("Element %f ne naiden!\n",forsearch);
	
	DoubleNode *aNode = Drevo->root;
	deleteNodeWithElement(Drevo,aNode, forsearch);
	search = findNodeWithElement(Drevo, forsearch);
	if (search != NULL)
		printf("Element %f naiden!\n",forsearch);
	else
		printf("Element %f ne naiden!\n",forsearch);
	count = 0;
	count = countNodesWithDrevo(Drevo);
	printDrevo(Drevo,count);
	destroyDoubleDrevo(Drevo);
	printf("Drevo udaleno!");
}
