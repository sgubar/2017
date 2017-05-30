#include "sort.h"

void bubbleSort(int anArray[], int aSize)
{
	int theOut = aSize - 1;

	for (theOut; theOut > 1; theOut --)
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] < anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}


void selectionSort(int anArray[], int aSize)
{
		int theOut = 0;
	for (theOut; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;

		int theIn = theOut + 1;
		for (theIn; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] > anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}


void insertionSort(int anArray[], int aSize)
{
	int theOut = 1;
	for (theOut; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] <= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}

		anArray[theIn] = theTmp;
	}
}







