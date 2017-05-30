#include <stdio.h>
#include "dk_tool.h"

int main() 
{		
	FILE *ptrFile = fopen("sortedArray.txt", "w");
	
	int aSize;
	do
	{
		printf("Enter the max count of characters in your array, from 1 to 1 000 000:\n");
		aSize = NumInput();	
	}
	while(aSize < 1 || aSize > 1000000);
	
	char *anArray = createAnArray(aSize);		
	
	fillingArrayFunction(anArray, aSize);

	fprintf(ptrFile, "The count of characters in the array: %d.\n\nYour array before sorting:\n\n\n", aSize);
	
	fileWrite(ptrFile, anArray, aSize);
	
	fprintf(ptrFile, "\n\n____________________\n\n");

	sortType(ptrFile, anArray, aSize);
	
	fileWrite(ptrFile, anArray, aSize);
	
	free(anArray);
	fflush (ptrFile);
	fclose (ptrFile);
	
	return 0;
}
