#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "sort.h"

void fill_Array(int *aArray, int aSize)
{
	srand(time(NULL));								
	int i;
	for(i = 0; i < aSize; i++)
		aArray[i] = rand() % 10001;							
}

void sorting(int *aArray, int aSize)
{
	FILE *file = fopen("Result.txt", "w");					
	if(file == NULL)										
	{
		printf("File lost!\n");
		free(aArray);
		exit(-2);											
	}
	
	fprintf(file, "Size of array: %i\n\n", aSize);
	
	clock_t start, finish;									
	double result;									
	
	fill_Array(aArray, aSize);								
	
	start = clock();										
	bubblesort(aArray, aSize);
	finish = clock();										
	
	result = (finish - start)/CLOCKS_PER_SEC;				
	printf("Bubblesort finished\n");
	fprintf(file, "Bubblesort\t\t\t%.18lf sec\n", result);	
	
	
	fill_Array(aArray, aSize);								//ñíîâà çàïîëíÿåì ìàññèâ ñëó÷àéíûìè ÷èñëàìè
	
	start = clock();
	insertionsort(aArray, aSize);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Insertionsort finished\n");
	fprintf(file, "Insertionsort\t\t%.18lf sec\n", result);
	
	
	fill_Array(aArray, aSize);
	
	start = clock();
	selectionsort(aArray, aSize);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Selectionsort finished\n");
	fprintf(file, "Selectionsort\t\t%.18lf sec\n", result);
	
	fflush(file);
	fclose(file);
}
