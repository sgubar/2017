#include "dk_tool.h"

// bubble sort
clock_t sortBubble(int **array, int n) 
{
	clock_t start = clock();
	int* a = *array;
	for (int r = n; r > 1; r--)
		for (int i = 0; i < r - 1; i++)
			if (a[i] < a[i+1]) 
			{
				int b = a[i];
				a[i] = a[i+1];
				a[i+1] = b;
			}
	return clock() - start;
}

// insertion sort
clock_t sortInsert(int **array, int n) 
{
	clock_t start = clock();
	for (int i = 1; i < n; i++) 
	{
		int b = (*array)[i];
		int j = 0;
		while (b < (*array)[j]) 
			j++;
		for (int k = i - 1; k >= j; k--) 
			(*array)[k+1]=(*array)[k];
		(*array)[j]=b;
	}
	return clock() - start;
}

// selection sort
clock_t sortSelect(int **array, int n) 
{
	clock_t start = clock();
	int *a = *array;
	for (int s=0; s < n-1; s++) 
	{
		int imax = s;
		int max = a[s];
		for (int i = s+1; i < n; i++)
			if (a[i] > max) 
			{
				max = a[i];
				imax = i;
			}
		a[imax] = a[s];
		a[s] = max;
	}
	return clock() - start;
}

void readNum(char *path, int **array, int *n) 
{
	FILE *file = fopen(path,"r");
	if (!file) 
	{
		printf("Error opening file\n");
		exit(1);
	}
	int i = 0;
	*n = 10;
	*array = (int*)realloc(*array,*n * sizeof(int));
	while (!feof(file)) 
	{
		fscanf(file,"%d",&((*array)[i]));
		if (++i >= *n) 
		{
			*n *= 2;
			*array = (int*)realloc(*array,*n *sizeof(int));
		}
	}
	*n = i - 1;
	*array = (int*)realloc(*array, i *sizeof(int));
	fclose(file);
}

void writeNum(char *path, int *array, int n) 
{
	FILE *file = fopen(path,"w");
	if (!file) 
	{
		printf("Error opening file\n");
		exit(1);
	}
	for (int i = 0; i < n; i++)
		fprintf(file,"%d ",array[i]);
	fclose(file);
}
