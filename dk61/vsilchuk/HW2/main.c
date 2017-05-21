#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

int main() 
{
	printf("Max count of pyramids:\n");
	
	int aSize = NumInput();					//максимальный размер комнаты, количество пирамид, которые можно впихнуть в нашу комнату 
	if(aSize < 1 || aSize > 100000000)
	{
		return 1;
	}
	
	pyramidsList *aPyramidsList = createPyramidsList(aSize);		//создали комнату, выделили память под пирамиды
	
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
