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

void testing(FILE *file, int *aArray, int aSize)
{
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
	
	
	fill_Array(aArray, aSize);								//снова заполняем массив случайными числами
	
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
	
	
	fill_Array(aArray, aSize);
	
	start = clock();
	shellsort(aArray, aSize);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Shellsort finished\n");
	fprintf(file, "Shellsort\t\t\t%.18lf sec\n", result);
	
	
	fill_Array(aArray, aSize);
	
	start = clock();
	quicksort(aArray, 0, aSize - 1);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Quicksort finished\n");
	fprintf(file, "Quicksort\t\t\t%.18lf sec\n\n", result);
	
	
	srand(time(NULL));
	fill_Array(aArray, aSize);
	
	start = clock();
	int x = lineSearch(rand() % 10001, aSize, aArray);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	if(x == 0)
		printf("Found\n");
	else
		printf("Not found\n");
	
	fprintf(file, "Line search\t\t%.18lf sec\n", result);
	
}
