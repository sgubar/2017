#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubblesort(int *aArray, int aSize)
{
	int i, j;
	for(j = 0; j < aSize-1; j++)
    {
	    for(i = 0; i < aSize-1-j; i++)
        {
	        if(aArray[i] > aArray[i+1])			//этот знак влияет на направление сортировки. в данном случае от меньшего к большему
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
			if(aArray[theIn] < aArray[theMinIndex])		//аналогично предыдущему комментарию
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

void swap(int *Val1, int *Val2)
{
	int tmp = *Val1;
	*Val1 = *Val2;
	*Val2 = tmp;
}
