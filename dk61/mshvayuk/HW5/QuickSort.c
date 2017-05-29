#include "QuickSort.h"
#include "area_tools.h"

#include <time.h>

static void swap(SquareArray *anArray, int aLeftIndex, int aRightIndex);
static int mediana(SquareArray *anArray, int aLeftIndex, int aRightIndex);

int partitionIt(SquareArray *anArray, int aLeftIndex, int aRightIndex, float aPivot)//return element, which razdilyaet PODmassiv 
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;
	
	while (1)
	{
		// search the bigest element
		while (anArray->array[++theLeft].area < aPivot);
	
		// search the lowest element
		while (theRight > 0 && anArray->array[--theRight].area > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			swap( anArray, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(anArray, theLeft, aRightIndex);
		
	return theLeft; // return break position
}

void quickSort(SquareArray *anArray, int aLeftIndex, int aRightIndex)//recursivno sortiruet masiv
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}
	
	int thePivot = anArray->array[aRightIndex].area;
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);//MEDIANA
	
	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);//recursion
	
	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);//recursion
}

int mediana(SquareArray *anArray, int aLeftIndex, int aRightIndex)//select middle element of array and check that left<mediana<right
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;// seredne znachennya elementiv
	
	if (anArray->array[aLeftIndex].area > anArray->array[theCenter].area)
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray->array[aLeftIndex].area > anArray->array[aRightIndex].area)
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray->array[theCenter].area > anArray->array[aRightIndex].area)
	{
		swap(anArray, theCenter, aRightIndex);
	}
	
	swap(anArray, theCenter, aRightIndex - 1);
	
	return anArray->array[aRightIndex - 1].area;
}

void swap(SquareArray *anArray, int aLeftIndex, int aRightIndex)//just swap 2 elements of array
{
	float theTmp = anArray->array[aLeftIndex].area;
	anArray->array[aLeftIndex].area = anArray->array[aRightIndex].area;
	anArray->array[aRightIndex].area = theTmp;
}

