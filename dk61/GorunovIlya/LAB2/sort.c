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

void quickSort(int anArray[], int aLeftIndex, int aRightIndex)
{
    int theSize = aRightIndex - aLeftIndex + 1;
    
    if (theSize <= 3)
    {
        m_manualSort(anArray, aLeftIndex, aRightIndex);
    }
    else
    {
        int thePivot = mediana(anArray, aLeftIndex, aRightIndex);
        int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);
        
        //left part sorting
        quickSort(anArray, aLeftIndex, thePartitionIndex - 1);
        
        //right part sorting
        quickSort(anArray, thePartitionIndex + 1, aRightIndex);
    }
}
int mediana(int anArray[], int aLeftIndex, int aRightIndex)
{
    int theCenter = (aLeftIndex + aRightIndex) / 2;
    
    if (anArray[aLeftIndex] > anArray[theCenter])
    {
        swap(anArray, aLeftIndex, theCenter);
    }
    
    if (anArray[aLeftIndex] > anArray[aRightIndex])
    {
        swap(anArray, aLeftIndex, aRightIndex);
    }
    
    if (anArray[theCenter] > anArray[aRightIndex])
    {
        swap(anArray, theCenter, aRightIndex);
    }
    
    swap(anArray, theCenter, aRightIndex - 1);
    
    return anArray[aRightIndex - 1];
}
