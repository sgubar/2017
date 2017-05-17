#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"
#include "dk_tool.h"

int main(int argc, const char *argv[])
{
	int aSize;
	do{
		printf("Max size: 100000\nEnter size of array: ");
		scanf("%d", &aSize);
	}while(aSize < 2 || aSize > 100000);
	
	int *aArray = (int *) malloc(sizeof(int) * aSize);
	if(aArray == 0)
	{
		printf("Crash\n");
		return 1;
	}
	
	FILE *file = fopen("Data.txt", "w");
	if(file == NULL)
	{
		printf("File not created!\n");
		free(aArray);
		return 2;
	}
	
	sortArray(aArray, aSize, file);
	
	fflush(file);
	fclose(file);
        free(aArray);
