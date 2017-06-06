#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"
void bubbleSort(ParpipedList *aParpiped)
{
	int theOut;
	int theIn;
	for (theOut = aParpiped->current_size - 1; theOut > 1; theOut--)
	{
		for (theIn = 0; theIn < theOut; theIn++)
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
	for (theOut = 0; theOut < aParpiped->current_size - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (theIn = theOut + 1; theIn < aParpiped->current_size; theIn++)
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

	for (theOut = 1; theOut < aParpiped->current_size; theOut++)
	{
		ParpipedPoints theTmp = aParpiped->parpipeds[theOut];
		int theIn = theOut;

		while (theIn > 0 && areaCalculation(&aParpiped->parpipeds[theIn - 1]) >= areaCalculation(&theTmp))
		{
			aParpiped->parpipeds[theIn] = aParpiped->parpipeds[theIn - 1];
			--theIn;
		}

		aParpiped->parpipeds[theIn] = theTmp;
	}
}


void swap(ParpipedList *aFigure, int aLeftIndex, int aRightIndex)
{
	ParpipedPoints theTmp = aFigure->parpipeds[aLeftIndex];
	aFigure->parpipeds[aLeftIndex] = aFigure->parpipeds[aRightIndex];
	aFigure->parpipeds[aRightIndex] = theTmp;
}


int mediana(ParpipedList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;


	if (areaCalculation(&aFigure->parpipeds[aLeftIndex]) > areaCalculation(&aFigure->parpipeds[theCenter]))
	{
		swap(aFigure, aLeftIndex, theCenter);
	}

	if (areaCalculation(&aFigure->parpipeds[aLeftIndex]) > areaCalculation(&aFigure->parpipeds[aRightIndex]))
	{
		swap(aFigure, aLeftIndex, aRightIndex);
	}

	if (areaCalculation(&aFigure->parpipeds[theCenter]) > areaCalculation(&aFigure->parpipeds[aRightIndex]))
	{
		swap(aFigure, theCenter, aRightIndex);
	}

	swap(aFigure, theCenter, aRightIndex - 1);


	return areaCalculation(&aFigure->parpipeds[aRightIndex - 1]);;
}

int m_partitionIt(ParpipedList *aFigure, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;

	while (1)
	{
		
		while (areaCalculation(&aFigure->parpipeds[++theLeft]) < aPivot);

		
		while (areaCalculation(&aFigure->parpipeds[--theRight]) > aPivot);

		if (theLeft >= theRight) 
		{
			break;
		}
		else
		{
			
			swap(aFigure, theLeft, theRight);
		}
	}

	
	swap(aFigure, theLeft, aRightIndex - 1);

	return theLeft; 
}

void quickSort2(ParpipedList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(aFigure, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(aFigure, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(aFigure, aLeftIndex, aRightIndex, thePivot);

		
		quickSort2(aFigure, aLeftIndex, thePartitionIndex - 1);

		
		quickSort2(aFigure, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(ParpipedList *aFigure, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
	{
		return;
	}

	if (2 == theSize)
	{
		if (areaCalculation(&aFigure->parpipeds[aLeftIndex]) > areaCalculation(&aFigure->parpipeds[aRightIndex]))
		{
			swap(aFigure, aLeftIndex, aRightIndex);
		}
		return;
	}
	else
	{
		
		if (areaCalculation(&aFigure->parpipeds[aLeftIndex]) > areaCalculation(&aFigure->parpipeds[aRightIndex - 1]))
		{
			swap(aFigure, aLeftIndex, aRightIndex - 1);
		}

		if (areaCalculation(&aFigure->parpipeds[aLeftIndex]) > areaCalculation(&aFigure->parpipeds[aRightIndex]))
		{
			swap(aFigure, aLeftIndex, aRightIndex);
		}

		if (areaCalculation(&aFigure->parpipeds[aRightIndex - 1]) > areaCalculation(&aFigure->parpipeds[aRightIndex]))
		{
			swap(aFigure, aRightIndex - 1, aRightIndex);
		}
	}
}
