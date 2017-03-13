//
//  SimpleSort.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/7/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "SimpleSort.h"

void bubbleSort(int anArray[], int aSize)
{
	for (int theOut = aSize - 1; theOut > 1; theOut --)
	{
		for (int theIn = 0; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
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
	for (int theOut = 0; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (int theIn = theOut + 1; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
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
	for (int theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}
	
		anArray[theIn] = theTmp;
	}
}
