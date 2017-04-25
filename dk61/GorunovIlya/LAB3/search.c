#include <stdio.h>
#include "dk_tool.h"

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
