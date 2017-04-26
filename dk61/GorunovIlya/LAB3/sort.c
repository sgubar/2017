#include <stdio.h>
#include "dk_tool.h"
#include <string.h>


void bubbleSort(char *anArray)
{
	int theOut;
	int theIn;
	for ( theOut = strlen(anArray) - 1; theOut > 1; theOut --)
	{
		for (theIn = 0; theIn < theOut; theIn ++)
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

void selectionSort(char* anArray)
{
	int theOut;
	int theIn;
	for (theOut = 0; theOut < strlen(anArray) - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn <strlen(anArray); theIn ++)
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

void insertionSort(char *anArray)
{
	int theOut;
	for (theOut = 1; theOut < strlen(anArray); theOut ++)
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


void quickSort(char *anArray, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; 
	}
	
	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
	

	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
	
	
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}


int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;
	
	while (1)
	{
		
		while (anArray[++theLeft] < aPivot);
	
		
		while (theRight > 0 && anArray[--theRight] > aPivot);
	
		if (theLeft >= theRight) 
		{
			break;
		}
		else
		{
			
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
	
	return theLeft; 
}

