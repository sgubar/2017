#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>


#include "dk_tool.h"

void Vivod (int Lenth,char *PStr){
	int i =0;
	printf("\n");
	while(i<Lenth)
	{
		printf("%c",PStr[i]);
		i++;
	}
}

void selectionSort(int lenth ,char *string)
{
	int theOut;
	for (theOut = 0; theOut < lenth - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < lenth; theIn ++)
		{
			if (string[theIn]<string[theMinIndex])
			{				
				theMinIndex = theIn;
			}
		}
	
		char theTmp = string[theOut];
		string[theOut] = string[theMinIndex];
		string[theMinIndex] = theTmp;
	}
}

void bubbleSort(int lenth, char *string)
{
	int theOut;
	for (theOut = lenth-1; theOut > 0; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (string[theIn] > string[theIn + 1])
			{
				char theTmp = string[theIn];
				string[theIn] = string[theIn + 1];
				string[theIn + 1] = theTmp;
			}
		}
	}
}

void insertionSort(int lenth, char *string)
{
	int theOut;
	for (theOut = 1; theOut < lenth; theOut ++)
	{
		char theTmp = string[theOut];
		int theIn = theOut;
		while (theIn > 0 && (string[theIn-1] >= theTmp))
		{
			string[theIn] = string[theIn - 1];
			-- theIn;
		}	
			string[theIn] = theTmp;
	}
}









