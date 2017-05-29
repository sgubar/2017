#include <stdio.h>
#include "dk_tool.h"
#include <string.h>
#include <stdlib.h>
#define IG_SIZE 500

void writeRandomToFile(FILE *aFile, char *charArray)
{

	if (aFile == NULL)
	{
	printf("Can not open file.\n");
    }

	fputs(charArray,aFile);

	fclose(aFile);

}

int readFromFile( char*charArray,char * sortingArray)
{
	FILE *theFile = fopen("random.txt","r");
	if(theFile == NULL)
	{
		printf("Your file is not found!\n");
		return -1;
	}
	else
	fgets(sortingArray,strlen(charArray),theFile);
	fclose(theFile);
	return 0;

}

int printToFile(FILE *aFile , char* sortedArray)
{

	if(sortedArray == NULL)
	{
		return -2;
	}
	fputs(sortedArray,aFile);
	fclose(aFile);
}

char symbolScanf(void)
{
	char someSymbol;
	printf("Enter a symbol which tou want to find: ");
	do
	{
	    int theTmp = scanf(" %c",&someSymbol);
	    if(theTmp == 1)
	    {
		    break;
	    }
	    printf("Please,try again: ");
	    fflush(stdin);
    }
	while(1);
	return someSymbol;
}

int binarySearch(char *anArray, char aValue, int aSize)
{
	int theRightLimit = aSize - 1;
	int theLeftLimit = 0;
	int theResult = -1;
	int middleValue = 0;

	while(1)
	{
		int middleValue = (theLeftLimit + theRightLimit)/2;

		if(anArray[middleValue] == aValue)
		{
			theResult = middleValue;
			break;
		}
		else if(theLeftLimit > theRightLimit)
		{
			break;
		}
		else
		{
			if(anArray[middleValue] > aValue)
			{
				theRightLimit = middleValue - 1;
			}
			else
			{
				theLeftLimit = middleValue + 1;
			}
		}
	}
	return theResult;

}

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
				char theTmp = anArray[theIn];
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

		char theTmp = anArray[theOut];
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

void shellSort(char *anArray, int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}
