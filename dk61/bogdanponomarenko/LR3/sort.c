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



void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	int thePivot = anArray[aRightIndex];
	int thePartitionIndex = partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(anArray, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(anArray, thePartitionIndex + 1, aRightIndex);
}





int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex;

	while (1)
	{
		// search the bigest element
		while (anArray[++theLeft] < aPivot);

		// search the lowest element
		while (theRight > 0 && anArray[--theRight] > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			// swap elements
			int theTmp = anArray[theLeft];
			anArray[theLeft] = anArray[theRight];
			anArray[theRight] = theTmp;
		}
	}

	// swap elements
	int theTmp = anArray[theLeft];
	anArray[theLeft] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;

	return theLeft; // return break position
}
	 
	 
	
	
/*void QuickSort(int  anArray[], int first,int last)
{
	int i = first, j = last;
	int  middle = anArray[(i+j)/2];
	int tmp;
	
	 while (anArray[i]<middle)
	 {
	 	i++;
	 }
	 
	 while (anArray[j]>middle)
	 {
	 	j--;
	 }
	 
	  if (i <= j)
	  {	
	  if (anArray[j]>anArray[i])
	  {
	  tmp=anArray[i];
	  	anArray[i]=anArray[j];
	  	anArray[j]=tmp;
	  	i++;
	  	j--;
	  }
}
	  if (i < last)
    QuickSort (anArray, i,last);
  if (first > i)
    QuickSort (anArray, first , i);
	 
	 
}

*/





