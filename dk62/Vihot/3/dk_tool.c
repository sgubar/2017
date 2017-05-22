#include "dk_tool.h"

clock_t sortShell(int array[], int n) 
{
	clock_t start = clock();

	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 

	while (theH <= n/3)
	{
		theH = theH*3 + 1; 
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < n; theOuter ++)
		{
			int theTmp = array[theOuter];
			theInner = theOuter;
			while (theInner > theH-1 && array[theInner - theH] < theTmp)
			{
				array[theInner] = array[theInner - theH];
				theInner -= theH;
			}

			array[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
	return clock() - start;
}

clock_t find(int array[], int n, int x, int *index) 
{
	clock_t start = clock();
	for (int i = 0; i < n; i++)
		if (array[i] == x) 
		{
			*index = i;
			return clock() - start;
		}
	*index = -1;
	return clock() - start;
}

void readNum(char *path, int **array, int *n) 
{
	FILE *file = fopen(path, "r");
	if (!file) 
	{
		printf("Error opening file\n");
		exit(1);
	}
	int i = 0;
	*n = 10;
	*array = (int*)realloc(*array, *n * sizeof(int));
	while (!feof(file)) 
	{
		fscanf(file, "%d", &((*array)[i]));
		if (++i >= *n) 
		{
			*n *= 2;
			*array = (int*)realloc(*array, *n *sizeof(int));
		}
	}
	*n = i - 1;
	*array = (int*)realloc(*array, i *sizeof(int));
	fclose(file);
}

void writeNum(char *path, int *array, int n) 
{
	FILE *file = fopen(path, "w");
	if (!file) 
	{
		printf("Error opening file\n");
		exit(1);
	}
	for (int i = 0; i < n; i++)
		fprintf(file, "%d ", array[i]);
	fclose(file);
}
