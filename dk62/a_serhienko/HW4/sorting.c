#include <stdio.h>
#include "sorting.h"
#include "dk_tool.h"

//Sort
void Bubble_Sort_List(pyramidList *aPyramidList)
{
	int i, j, result;
	for (i = 1; i < aPyramidList->current_size; i++)
	{
		result = 0; 						
		for (j = 1; j < aPyramidList->current_size - i + 1; j++)
		{
			if (square(&aPyramidList->arrayofPyramids[j]) > square(&aPyramidList->arrayofPyramids[j - 1]))
			{
				swap(&aPyramidList->arrayofPyramids[j], &aPyramidList->arrayofPyramids[j - 1]);
				result++; 					
			}
		}
		if (!result)
			break;
	}
}

void Selection_Sort_List(pyramidList *aPyramidList)
{
	int theIn, theOut, max, temp;
	for (theIn = 0; theIn < aPyramidList->current_size; theIn++)
	{
		max = theIn;
		for (theOut = theIn + 1; theOut < aPyramidList->current_size; theOut++)
		{
			if (square(&aPyramidList->arrayofPyramids[theOut]) > square(&aPyramidList->arrayofPyramids[max]))
				max = theOut;
		}
		if (max != theIn)      //if it's not sorted
			swap(&aPyramidList->arrayofPyramids[theIn], &aPyramidList->arrayofPyramids[max]);
	}
}


void Insertion_Sort_List(pyramidList *aPyramidList)
{
	int theOut;
	for (theOut = 1; theOut < aPyramidList->current_size; theOut++)
	{
		pyramid tempPyramid = aPyramidList->arrayofPyramids[theOut];
		int theIn = theOut;

		while (theIn > 0 && square(&aPyramidList->arrayofPyramids[theIn - 1]) <= square(&tempPyramid))
		{
			aPyramidList->arrayofPyramids[theIn] = aPyramidList->arrayofPyramids[theIn - 1];
			--theIn;
		}
		aPyramidList->arrayofPyramids[theIn] = tempPyramid;
	}
}
