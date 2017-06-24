#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	DoubleDrevo *Drevo = createDoubleDrevo();
	insertdoubleElementToDrevo(Drevo, 6.1852);
	insertdoubleElementToDrevo(Drevo, 5.1785);
	insertdoubleElementToDrevo(Drevo, 3.686);
	insertdoubleElementToDrevo(Drevo, 8.3785);
	insertdoubleElementToDrevo(Drevo, 6.986);
	insertdoubleElementToDrevo(Drevo, 2.175);
	insertdoubleElementToDrevo(Drevo, 2.162);
	insertdoubleElementToDrevo(Drevo, 4.152);
	int count = countNodesWithDrevo(Drevo);
	double forsearch=2.175;
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
