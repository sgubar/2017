#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[])
{
	int a = 0;
	do{
		printf("Enter number of circles: ");
		scanf("%i", &a);
	}while(a < 1);
	
	list *circ = createList(a);
	
	while(a != 0)
	{
		newCoordinate(circ);
		a--;
	}
	
	printArea(circ);
	
	if(circ->currentSize > 1)
	{
		shellSort(circ);
		printArea(circ);
	}
	
	int x = lineSearch(circ);
	if(x == 0)
		printf("Found\n");
	else
		printf("Not found\n");
	
	destroyList(circ);
	return 0;
}
