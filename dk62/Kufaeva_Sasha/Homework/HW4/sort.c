#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"
void bubbleSort(ParpipedList *aParpiped)
{
	int theOut;
	int theIn;
	for (theOut = aParpiped->current_size - 1; theOut > 1; theOut--)
	{
		for ( theIn = 0; theIn < theOut; theIn ++)
		{
			if (areaCalculation(&aParpiped->parpipeds[theIn]) > areaCalculation(&aParpiped->parpipeds[theIn + 1]))
			{
				ParpipedPoints theTmp = aParpiped->parpipeds[theIn];
				aParpiped->parpipeds[theIn] = aParpiped->parpipeds[theIn + 1];
				aParpiped->parpipeds[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort(ParpipedList *aParpiped)
{
	int theOut;
	int theIn;
	for (theOut = 0; theOut < aParpiped->current_size - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aParpiped->current_size; theIn ++)
		{
			if (areaCalculation(&aParpiped->parpipeds[theIn]) < areaCalculation(&aParpiped->parpipeds[theMinIndex]))
			{
				theMinIndex = theIn;
			}
		
	    }
	            ParpipedPoints theTmp = aParpiped->parpipeds[theOut];
				aParpiped->parpipeds[theOut] = aParpiped->parpipeds[theMinIndex];
				aParpiped->parpipeds[theMinIndex] = theTmp;
		
	}
}

void insertionSort(ParpipedList *aParpiped)
{
	int theOut;
	
	for (theOut = 1; theOut < aParpiped->current_size; theOut ++)
	{
		ParpipedPoints theTmp = aParpiped->parpipeds[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && areaCalculation(&aParpiped->parpipeds[theIn - 1])>= areaCalculation(&theTmp))
		{
			aParpiped->parpipeds[theIn] = aParpiped->parpipeds[theIn - 1];
			-- theIn;
		}
	
		aParpiped->parpipeds[theIn] = theTmp;
	}
}

