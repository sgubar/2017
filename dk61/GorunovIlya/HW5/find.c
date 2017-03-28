#include <stdio.h>
#include "find.h"
#include <stdio.h>
#include "dk_tool.h"

int binarySearch(SphereList *aSphere, int aValue)
{
	int theRightLimit = aSphere->current_size - 1;
	int theLeftLimit = 0;
	int theResult = aSphere->current_size;
	int middleValue = 0;
	
	while(1)
	{
		int middleValue = (theLeftLimit + theRightLimit)/2;
		
		if(aSphere->spheres[middleValue].radius == aValue)
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
			if(aSphere->spheres[middleValue].radius > aValue)
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

