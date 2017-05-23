#include <stdio.h>
#include "dk_tool.h"
#include <string.h>
#include <stdlib.h>
void printRandomToFile(FILE *aFile, char *charArray)
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

void shellSort(anArray, int step)
{
	    int i=0 , step = anArray -> charArray / 2;

	while (step > 0)
    {
      for (i = 0; i < (anArray -> charArray - step); i++)
        {
      	  int j = i;
          while (j >= 0 && ( anArray -> charArray[j]) <( anArray -> charArray[j + step] )
            {
        		swap(  anArray -> charArray[j]) <( anArray -> charArray[j + step] );
                j--;
            }
		}
    step /= 2;
	}
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
