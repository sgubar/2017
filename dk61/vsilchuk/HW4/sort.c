#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"

void sortType(pyramidsList *aPyramidsList)
{
	printf("\n\nPlease choose your type of sort:\n1 - bubbleSort,\n2 - selectionSort,\n3 - insertionSort.\n");
	int caseCounter;
	while(1)
	{
		caseCounter = NumInput();
		
		if (caseCounter > 0 && caseCounter < 4)
			break;
			
		printf("\nPlease enter another number:\n");
		fflush (stdin); 
	}	
	
	switch (caseCounter) 
	{
		case 1:
			printf("\nSorted by bubbleSort:");
			bubbleSort(aPyramidsList);
			break;
		case 2:
			printf("\nSorted by selectionSort:");
			selectionSort(aPyramidsList);
			break;
		case 3:
			printf("\nSorted by insertionSort:");
			insertionSort(aPyramidsList);
			break;		
	}
}



void swap(pyramid *aPyramidOne, pyramid *aPyramidTwo)
{
	pyramid container = *aPyramidOne;
	*aPyramidOne = *aPyramidTwo;
	*aPyramidTwo = container;
}

void bubbleSort(pyramidsList *aPyramidsList)
{
	int i, j;
	for (i = aPyramidsList -> pyramidsCounter - 1; i > 1; i--)
	{						
		for (j = 0; j < i; j++)	
		{
			if (pyramidSquare(&(aPyramidsList -> pyramids[j])) > pyramidSquare(&(aPyramidsList -> pyramids[j+1]))) 
			{
				swap(	&(aPyramidsList -> pyramids[j]) , &(aPyramidsList -> pyramids[j+1])	);				
			}
		}
	}
}

void selectionSort(pyramidsList *aPyramidsList)
{
	int theOut; int theIn;
	for (theOut = 0; theOut < aPyramidsList -> pyramidsCounter - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aPyramidsList -> pyramidsCounter; theIn ++)
		{
			if (pyramidSquare(&(aPyramidsList -> pyramids[theIn])) < pyramidSquare(&(aPyramidsList -> pyramids[theMinIndex])))
			{
				theMinIndex = theIn;
			}
		}
		swap(	&(aPyramidsList -> pyramids[theOut]) , &(aPyramidsList -> pyramids[theMinIndex]));
	}
}


void insertionSort(pyramidsList *aPyramidsList)
{
	int theOut;
	for (theOut = 1; theOut < aPyramidsList -> pyramidsCounter; theOut++)
	{
		pyramid tmpPyramid = aPyramidsList -> pyramids[theOut];
		int theIn = theOut;

		while (theIn > 0 && pyramidSquare(&(aPyramidsList -> pyramids[theIn - 1])) >= pyramidSquare(&(tmpPyramid)))
		{
			aPyramidsList -> pyramids[theIn] = aPyramidsList -> pyramids[theIn - 1];
			--theIn;
		}
		aPyramidsList -> pyramids[theIn] = tmpPyramid;
	}
}
