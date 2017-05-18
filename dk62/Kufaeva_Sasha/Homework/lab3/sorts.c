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

void insertionsort(int *aArray, int aSize)
{
	for(int theOut = 1; theOut < aSize; theOut++)
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

void shellsort(int *aArray, int aSize)
{
	int theIn, H = 1;
	
	while(H <= aSize / 3)
	{
		H = H * 3 + 1;
	}
	
	while(H > 0)
	{	
		for(int theOut = H; theOut < aSize; theOut++)
		{
			int tmp = aArray[theOut];
			theIn = theOut;
			
			while(theIn > H - 1 && aArray[theIn - H] >= tmp)
			{
				aArray[theIn] = aArray[theIn - H];
				theIn -= H;
			}
			aArray[theIn] = tmp;
		}
		H = (H - 1) / 3;
	}
}

void quicksort(int *aArray, int first, int last)
{
	int theIn = first, theOut = last, c = aArray[(first + last) / 2];
	do{
		while(aArray[theIn] < c)
		{
			theIn++;
		}
	    while(aArray[theOut] > c)
	    {
			theOut--;
		}
		
		if(theIn <= theOut)
		{
			if(aArray[theIn] > aArray[theOut])
			{
				swap(&aArray[theIn], &aArray[theOut]);
			}
			theIn++;
			theOut--;
		}
	}while(theIn <= theOut);
	
	if(theIn < last)
	{
		quicksort(aArray, theIn, last);
	}
	if(first < theOut)
	{
		quicksort(aArray, first, theOut);
	}
}

void swap(int *tmp1, int *tmp2)
{
	int tmp = *tmp1;
	*tmp1 = *tmp2;
	*tmp2 = tmp;
}

int linesearch(int *aArray, int aSize, int val)
{
for(int i = 0; i < aSize; i++)
{
	if(aArray[i] == val)
	{
		return 0;
	}
}
return -1;
}

int binarysearch(int *aArray, int aSize, int val)
{
int middle, lower = 0, upper = aSize - 1;
while(lower <= upper)
{
	middle = (lower + upper) / 2;
	
	if(aArray[middle] == val)
	{
		return 0;
	}
	
	else if(aArray[middle] < val)
	{
		lower = middle + 1;
	}
	
	else
	{
		upper = middle - 1;
	}
}
return -1;
}
