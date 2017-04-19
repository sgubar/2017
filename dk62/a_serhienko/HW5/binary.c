#include <stdio.h>
#include "binary.h"
#include <stdio.h>
#include "dk_tool.h"

int binarySearch(pyramidList *aPyramidList, int aValue)
{
	int theRightLimit = aPyramidList->current_size - 1;
	int theLeftLimit = 0;
	int theResult = aPyramidList->current_size;
	int middleValue = 0;

	while (1)
	{
		int middleValue = (theLeftLimit + theRightLimit) / 2;

		if (square(&aPyramidList->arrayofPyramids[middleValue]) == aValue)
		{
			theResult = middleValue;
			printf("Searched Pyramid is located on %d position\n", theResult);
			return theResult;
			break;
		}
		else if (theLeftLimit > theRightLimit)
		{
			break;
		}
		else
		{
			if (square(&aPyramidList->arrayofPyramids[middleValue]) > aValue)
			{
				theRightLimit = middleValue - 1;
			}
			else
			{
				theLeftLimit = middleValue + 1;
			}
		}
	}
	return -1;

}