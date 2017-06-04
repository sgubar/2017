#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "dk_tool.h"

#define ARRAY_SIZE 50000

int main(int argc, const char *argv[])
{
	int *Array = (int *) malloc(sizeof(int) * ARRAY_SIZE);		
	if(Array == NULL)												
	{
		printf("Error!\n");
		return 1;
	}
	
	FILE *file = fopen("Result.txt","w");					
	if(file == NULL)										
	{
		printf("File lost!\n");
		free(Array);
		return 2;										
	}
	
	printf("Array created: %i elements.\n\n", ARRAY_SIZE);
	
	testing(file, Array, ARRAY_SIZE);
	
	fflush(file);
	fclose(file);
	
	free(Array);												
	return 0;
}
