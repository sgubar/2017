#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "sorts.h"

void sortArray(int *aArray, int aSize, FILE *file)
{
	clock_t first, second;
	double time;
	
	values(aArray, aSize);
	
	printf("Bubblesort started\n");
	first = clock();
	bubblesort(aArray, aSize);
	second = clock();
	
	time = (second - first)/1000;
	printf("Bubblesort finished\n");
	fprintf(file, "Bubblesort\t%.5lf s\n", time);
	
	
	values(aArray, aSize);
	
	printf("Insertionsort started\n");
	first = clock();
	insertionsort(aArray, aSize);
	second = clock();
	
	time = (second - first)/1000;
	printf("Insertionsort finished\n");
	fprintf(file, "Insertionsort\t%.5lf s\n", time);
	
	
	values(aArray, aSize);
	
	printf("Selectionsort started\n");
	first = clock();
	selectionsort(aArray, aSize);
	second = clock();
	
	time = (second - first)/1000;
	printf("Selectionsort finished\n");
	fprintf(file, "Selectionsort\t%.5lf s\n", time);
	
	
	values(aArray, aSize);
	
	printf("Shellsort started\n");
	first = clock();
	shellsort(aArray, aSize);
	second = clock();
	
	time = (second - first)/1000;
	printf("Shellsort finished\n");
	fprintf(file, "Shellsort\t%.5lf s\n", time);
	
	
	values(aArray, aSize);
	
	printf("Quicksort started\n");
	first = clock();
	quicksort(aArray, 0, aSize - 1);
	second = clock();
	
	time = (second - first)/1000;
	printf("Quicksort finished\n");
	fprintf(file, "Quicksort\t%.5lf s\n", time);
}

void values(int *aArray, int aSize)
{
	srand(time(NULL));
	for(int i = 0; i < aSize; i++)
	{
		aArray[i] = rand();
	}
}

void searchArray(int *aArray, int aSize, FILE *file)
{
	clock_t first, second;
	double time;
	
	int val, result;
	do{
		printf("\nEnter value to search: ");
		scanf("%d", &val);
	}while(val < 0);
	
	printf("Line search started\n");
	first = clock();
	result = linesearch(aArray, aSize, val);
	second = clock();
	
	time = (second - first)/1000;
	printf("Line search finished\n");
	fprintf(file, "\nLine search \t%.5lf s\n", time);
	
	if(result== 0)
	{
		printf("Founded!\n");
	}
	else
	{
		printf("Not founded\n");
	}
	
	printf("Binary search started\n");
	first = clock();
	result = linesearch(aArray, aSize, val);
	second = clock();
	
	time = (second - first)/1000;
	printf("Binary search finished\n");
	fprintf(file, "Binary search \t%.5lf s\n", time);
	
	if(result == 0)
	{
		printf("Founded!\n");
	}
	else
	{
		printf("Not founded\n");
	}
	
}
