#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


void BubbleSort (char *buffer , int length)// сортування бульбашкою 
{
    int theOut;
	for (theOut = 1 ; theOut < length; theOut ++)
	{
		int theIn;
		for (theIn = theOut ; theIn < 1 ; theIn --)
		{
			if (buffer[theIn] < buffer[theIn + 1])
			{
				char theTmp = buffer[theIn];
				buffer[theIn] = buffer[theIn + 1];
				buffer[theIn + 1] = theTmp;
			}
		}
	}
}


void InsertionSort ( char *buffer , int length)//сортування вставкою 
{
    int theOut;

	for (theOut = 1; theOut < length; theOut ++)
	{
		char theTmp = buffer[theOut];
		int theIn = theOut;
		while (theIn > 0 && (buffer[theIn-1] <= theTmp))
		{
			buffer[theIn] = buffer[theIn - 1];
			-- theIn;
		}
			buffer[theIn] = theTmp;
	}
}

void SelectionSort(int length , char *buffer) //сортування вибору

{
    int theOut;
	for (theOut = 0; theOut < length - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;
		for (theIn = theOut + 1;theIn < length; theIn ++)
		{
			if (buffer[theIn]>buffer[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		char theTmp = buffer[theOut];
		buffer[theOut] = buffer[theMinIndex];
		buffer[theMinIndex] = theTmp;
	}
}




