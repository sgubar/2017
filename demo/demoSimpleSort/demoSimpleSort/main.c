//
//  main.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SimpleSort.h"
#include "shellSort.h"
#include "quickSort.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void printArray(int anArray[], int aSize);
static void fillArray(int anArray[], int aSize, int aPivot);

int main(int argc, const char * argv[])
{
	int theArray[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	
	printf("Test bubble sorting\n");
	
	printArray(theArray, ARRAY_SIZE(theArray));
	bubbleSort(theArray, ARRAY_SIZE(theArray));
	printArray(theArray, ARRAY_SIZE(theArray));

	printf("\nTest selection sorting\n");
	int theArray2[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray2, ARRAY_SIZE(theArray2));
	selectionSort(theArray2, ARRAY_SIZE(theArray2));
	printArray(theArray2, ARRAY_SIZE(theArray2));	

	printf("\nTest insertion sorting\n");
	int theArray3[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray3, ARRAY_SIZE(theArray3));

	clock_t theStart0 = clock();
	selectionSort(theArray3, ARRAY_SIZE(theArray3));
	clock_t theEnd0 = clock();
	printArray(theArray3, ARRAY_SIZE(theArray3));
	printf ("time of Selection sorting: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);

	printf("\nTest Shell sorting\n");
	int theArray4[] = {77, 99, 44, 55, 22, 88, 11, 0, 66, 33};
	printArray(theArray4, ARRAY_SIZE(theArray4));
	
	clock_t theStart = clock();
	shellSort(theArray4, ARRAY_SIZE(theArray4));
	clock_t theEnd = clock();
	printArray(theArray4, ARRAY_SIZE(theArray4));
	
	printf ("time of Shell sorting: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
	
	printf ("Start to make partition of the array\n");
	int the20Array[20];
	int thePivot = 99; //make the pivot as avarage VALUE
	fillArray(the20Array, ARRAY_SIZE(the20Array), thePivot);
	printArray(the20Array, ARRAY_SIZE(the20Array));
	
	printf("Finish the partition with a pivot: %d\n", partitionIt(the20Array, 0,
				ARRAY_SIZE(the20Array) - 1, 99));
	
	printArray(the20Array, ARRAY_SIZE(the20Array));

	printf("\nTest Quick sorting\n");
	int theQuickArray[10000];
	fillArray(theQuickArray, ARRAY_SIZE(theQuickArray), 100);
	printArray(theQuickArray, ARRAY_SIZE(theQuickArray));
	
	clock_t theStartQuick = clock();
	quickSort2(theQuickArray, 0, ARRAY_SIZE(theQuickArray) - 1);
	clock_t theEndQuick = clock();
	printArray(theQuickArray, ARRAY_SIZE(theQuickArray));
	
	printf ("time of Quick sorting: %.10lf\n", (double)(theEndQuick - theStartQuick)/CLOCKS_PER_SEC);

	printf("Hello, World!\n");
	
	system("pause");
}

#pragma mark -
void printArray(int anArray[], int aSize)
{
	printf("{");
	for (int i = 0; i < aSize; i++)
	{
		printf(" %d ", anArray[i]);
	}

	printf("}\n");
}

void fillArray(int anArray[], int aSize, int aPivot)
{
	srand(0);
	for (int i = 0; i < aSize; i++)
	{
		anArray[i] = rand() % (2 * aPivot);
	}
}
