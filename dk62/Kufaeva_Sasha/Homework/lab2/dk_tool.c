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
	
	

	


void values(int *aArray, int aSize)
{
	srand(time(NULL));
	
	for(int i = 0; i < aSize; i++)
		aArray[i] = rand();
}
