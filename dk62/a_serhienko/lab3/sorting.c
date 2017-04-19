#include "sorting.h"
#include "dk_tool.h"
#include <stdio.h>	
#include <string.h>
void ShellSort(char * array, int size)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 

				 
	while (theH <= size / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}

	
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < size; theOuter++)
		{
			char theTmp = array[theOuter];
			theInner = theOuter;

			
			while (theInner > theH - 1 && array[theInner - theH] >= theTmp)
			{
				array[theInner] = array[theInner - theH];
				theInner -= theH;
			}

			array[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
}



void BubbleSort(char *array,int size)
{
	int theOut;
	for (theOut = size - 1; theOut > 0; theOut--)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn++)
		{
			if (array[theIn] > array[theIn + 1])
			{
				char theTmp = array[theIn];
				array[theIn] = array[theIn + 1];
				array[theIn + 1] = theTmp;
			}
		}
	}
}

void SelectionSort(char * array,int size)
{
	int theOut;
	for (theOut = 0; theOut < size - 1; theOut++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1; theIn <size; theIn++)
		{
			if (array[theIn]<array[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = array[theOut];
		array[theOut] = array[theMinIndex];
		array[theMinIndex] = theTmp;
	}
}

void InsertionSort(char *array, int size)
{
	int theOut;
	for (theOut = 1; theOut <size; theOut++)
	{
		char theTmp = array[theOut];
		int theIn = theOut;
		while (theIn > 0 && (array[theIn - 1] >= theTmp))
		{
			array[theIn] = array[theIn - 1];
			--theIn;
		}
		array[theIn] = theTmp;
	}
}