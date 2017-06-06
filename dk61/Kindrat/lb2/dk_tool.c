#include "dk_tool.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

void bubbleSort(char *str, int lenght)
	{
		for (int N = lenght-1; N > 0; N --)
		{		
			int Y;
				for (int Y = 0; Y < N; Y ++)
				{			
					if (str[Y] < str[Y + 1])
					{	
					char theTmp = str[Y];
					str[Y] = str[Y + 1];
					str[Y + 1] = theTmp;
					}
				}
		}
	}
	
void selectionSort(char *str, int lenght)
{
	int N;	
	for (N = 0; N < lenght - 1; N ++)
	{
		int theMinIndex = N;
		int Y;	
		for (Y = N + 1;Y < lenght; Y ++)
		{
			if (str[Y]>str[theMinIndex])
			{				
				theMinIndex = Y;
			}
		}
		
		char theTmp = str[N];
		str[N] = str[theMinIndex];
		str[theMinIndex] = theTmp;
	}
}

void insertionSort(char *str, int lenght)
{
	int N;
	for (N = 1; N < lenght; N ++)
	{
		char theTmp = str[N];
		int Y = N;
		while (Y > 0 && (str[Y-1] >= theTmp))
		{
			str[Y] = str[Y - 1];
		}	
			str[Y] = theTmp;
	}
}
