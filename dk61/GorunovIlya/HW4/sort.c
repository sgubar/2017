#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"

void bubbleSort(SphereList *aSphere)
{
	int theOut;
	int theIn;
	for (theOut = aSphere->current_size - 1; theOut > 1; theOut--)
	{
		for ( theIn = 0; theIn < theOut; theIn ++)
		{
			if (aSphere->spheres[theIn].radius > aSphere->spheres[theIn + 1].radius)
			{
				SpherePosition theTmp = aSphere->spheres[theIn];
				aSphere->spheres[theIn] = aSphere->spheres[theIn + 1];
				aSphere->spheres[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort(SphereList *aSphere)
{
	int theOut;
	int theIn;
	for (theOut = 0; theOut < aSphere->current_size - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aSphere->current_size; theIn ++)
		{
			if (aSphere->spheres[theIn].radius < aSphere->spheres[theMinIndex].radius)
			{
				theMinIndex = theIn;
			}
		}
	
		SpherePosition theTmp = aSphere->spheres[theOut];
		aSphere->spheres[theOut] = aSphere->spheres[theMinIndex];
		aSphere->spheres[theMinIndex] = theTmp;
	}
}

void insertionSort(SphereList *aSphere)
{
	int theOut;
	
	for (theOut = 1; theOut < aSphere->current_size; theOut ++)
	{
		SpherePosition theTmp = aSphere->spheres[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && aSphere->spheres[theIn - 1].radius >= theTmp.radius)
		{
			aSphere->spheres[theIn] = aSphere->spheres[theIn - 1];
			-- theIn;
		}
	
		aSphere->spheres[theIn] = theTmp;
	}
}





void bubbleSort2(SphereList *aSphere)
{
	int theOut;
	int theIn;
	for (theOut = aSphere->current_size - 1; theOut > 1; theOut--)
	{
		for ( theIn = 0; theIn < theOut; theIn ++)
		{
			if (areaCalculation(&aSphere->spheres[theIn]) > areaCalculation(&aSphere->spheres[theIn + 1]))
			{
				SpherePosition theTmp = aSphere->spheres[theIn];
				aSphere->spheres[theIn] = aSphere->spheres[theIn + 1];
				aSphere->spheres[theIn + 1] = theTmp;
			}
		}
	}
}

void selectionSort2(SphereList *aSphere)
{
	int theOut;
	int theIn;
	for (theOut = 0; theOut < aSphere->current_size - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (theIn = theOut + 1; theIn < aSphere->current_size; theIn ++)
		{
			if (areaCalculation(&aSphere->spheres[theIn]) < areaCalculation(&aSphere->spheres[theMinIndex]))
			{
				theMinIndex = theIn;
			}
		}
	
		SpherePosition theTmp = aSphere->spheres[theOut];
		aSphere->spheres[theOut] = aSphere->spheres[theMinIndex];
		aSphere->spheres[theMinIndex] = theTmp;
	}
}

void insertionSort2(SphereList *aSphere)
{
	int theOut;
	
	for (theOut = 1; theOut < aSphere->current_size; theOut ++)
	{
		SpherePosition theTmp = aSphere->spheres[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && areaCalculation(&aSphere->spheres[theIn - 1])>= areaCalculation(&theTmp))
		{
			aSphere->spheres[theIn] = aSphere->spheres[theIn - 1];
			-- theIn;
		}
	
		aSphere->spheres[theIn] = theTmp;
	}
}


