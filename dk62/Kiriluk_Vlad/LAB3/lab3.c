#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jab3.h"


void BubbleSort (char *buffer , int length)
{
    int theOut;
	for (theOut = length; theOut > 1; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut ; theIn ++)
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


void InsertionSort ( char *buffer , int length)
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

void SelectionSort(int length , char *buffer)
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


int BinarySearch(int length, char *buffer, char find)
{
	int Left = 0;
	int Right = length;
	int middle = 0;
	int Result = -1;
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(buffer[middle] == find)
		{
			Result = middle;
			break;
		}
		else
		{
			if(buffer[middle] > find)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	return Result;
}

void ShellSort( char *buffer , int length)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;


	while (theH <= length/3)
	{
		theH = theH*3 + 1;
	}


	while (theH > 0)
	{
		for (theOuter = theH; theOuter < length; theOuter ++)
		{
			int theTmp = buffer[theOuter];
			theInner = theOuter;


			while (theInner > theH-1 && buffer[theInner - theH] <= theTmp)
			{
				buffer[theInner] = buffer[theInner - theH];
				theInner -= theH;
			}

			buffer[theInner] = theTmp;
		}

		theH = (theH - 1) / 3;
	}
}


