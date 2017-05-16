#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

void bubblesort(int *aArray, int aSize)
{
	for(int j = aSize-1; j > 0; j--)
    {
		for(int i = 0; i < j; i++)
        {
	        if(aArray[i] > aArray[i+1])
	        {
				swap(&aArray[i], &aArray[i+1]);
			}
        }
    }
}

void selectionsort(int *aArray, int aSize)
{
	for(int theOut = 0; theOut < aSize - 1; theOut++)
	{
		int theMinIndex = theOut;
		for(int theIn = theOut + 1; theIn < aSize; theIn++)
		{
			if(aArray[theIn] < aArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}
		swap(&aArray[theOut], &aArray[theMinIndex]);
	}
}
