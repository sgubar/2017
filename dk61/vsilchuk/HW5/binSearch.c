#include <stdio.h>
#include "dk_tool.h"
#include "binSearch.h"

int binSearch(pyramidsList *aPyramidsList, float searchValue)
{
	int low, high, middle;
    low = 0;
    high = aPyramidsList -> pyramidsCounter - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (searchValue < pyramidSquare(&(aPyramidsList -> pyramids[middle])))
            high = middle - 1;
        else if (searchValue > pyramidSquare(&(aPyramidsList -> pyramids[middle])))
            low = middle + 1;
        else 
            return middle;
    }
    return -1;
}

