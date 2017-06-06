#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *Val1, int *Val2)
{
	int tmp = *Val1;
	*Val1 = *Val2;
	*Val2 = tmp;
}

void bubblesort(int *aArray, int aSize)
{
	int i, j;
	for(j = 0; j < aSize-1; j++)
    {
	    for(i = 0; i < aSize-1-j; i++)
        {
	        if(aArray[i] > aArray[i+1])			
	            swap(&aArray[i], &aArray[i+1]);
        }
    }
}

void selectionsort(int *aArray, int aSize)
{
	int theOut;
	for(theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut, theIn;
		for(theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if(aArray[theIn] < aArray[theMinIndex])		
				theMinIndex = theIn;
		}
		swap(&aArray[theOut], &aArray[theMinIndex]);
	}
}

void insertionsort(int *aArray, int aSize)
{
	int theOut;
	for(theOut = 1; theOut < aSize; theOut++)
	{
		int theTmp = aArray[theOut];
		int theIn = theOut;
		while(theIn > 0 && aArray[theIn - 1] >= theTmp)
		{
			aArray[theIn] = aArray[theIn - 1];
			theIn--;
		}
		aArray[theIn] = theTmp;
	}
}

void shellsort(int *array, int aSize)
{
	int i = 0, j = 0, H = 1;
	
	while(H <= aSize / 3)
		H = H * 3 + 1;
	
	while(H > 0)
	{
		for(j = H; j < aSize; j++)
		{
			int tmp = array[j];
			i = j;
			
			while(i > H - 1 && array[i - H] >= tmp)
			{
				array[i] = array[i - H];
				i -= H;
			}
			array[i] = tmp;
		}
		H = (H - 1) / 3;
	}
}


int lineSearch(int val, int aSize, int *array)
{
	int i;
	for(i = 0; i < aSize; i++)
	{
		if(array[i] == val)
			return 0;
	}
	return 1;
}
