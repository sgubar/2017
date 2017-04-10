#include"sorting.h"
#include "dk_tool.h"
#include <string.h>
#include <stdio.h>

void BubbleSort(char *arrayforsorting)
{
	int theOut;
	for (theOut = strlen(arrayforsorting) - 1; theOut > 0; theOut--)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn++)
		{
			if (arrayforsorting[theIn] > arrayforsorting[theIn + 1])
			{
				char theTmp = arrayforsorting[theIn];
				arrayforsorting[theIn] = arrayforsorting[theIn + 1];
				arrayforsorting[theIn + 1] = theTmp;
			}
		}
	}
}

void SelectionSort(char *arrayforsorting)
{
	int theOut;
	for (theOut = 0; theOut < strlen(arrayforsorting) - 1; theOut++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1; theIn <strlen(arrayforsorting); theIn++)
		{
			if (arrayforsorting[theIn]<arrayforsorting[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = arrayforsorting[theOut];
		arrayforsorting[theOut] = arrayforsorting[theMinIndex];
		arrayforsorting[theMinIndex] = theTmp;
	}
}

void InsertionSort(char *arrayforsorting)
{
	int theOut;
	for (theOut = 1; theOut <strlen(arrayforsorting); theOut++)
	{
		char theTmp = arrayforsorting[theOut];
		int theIn = theOut;
		while (theIn > 0 && (arrayforsorting[theIn - 1] >= theTmp))
		{
			arrayforsorting[theIn] = arrayforsorting[theIn - 1];
			--theIn;
		}
		arrayforsorting[theIn] = theTmp;
	}
}

