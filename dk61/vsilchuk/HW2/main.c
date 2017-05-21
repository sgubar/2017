#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main() 
{
	printf("Max count of pyramids:\n");
	
	int aSize = NumInput();					 
	if(aSize < 1 || aSize > 100000000)
	{
		return 1;
	}
	
	pyramidsList *aPyramidsList = createPyramidsList(aSize);		
	
	int i;
	for(i = 0; i < aSize; i++)
	{
			addPyramid(aPyramidsList);
	}	
	
	printPyramidsList(aPyramidsList);

	printSquare(aPyramidsList);

	destroyAPyramidsList(aPyramidsList);

	return 0;
}
