#include "binary.h"


int binarySearch(ListFigures*AFigures, int aValue)
{
    int theRightLimit = AFigures->current_size - 1;
    int theLeftLimit = 0;
    int theResult ;


    while (1)
    {
        int middleValue = (theLeftLimit + theRightLimit) / 2;

        if (Square(&AFigures->Rectangles[middleValue]) == aValue)
        {
            theResult = middleValue;
            printf("Searched Pyramid is located on %d position\n", theResult+1);
            return theResult;
            break;
        }
        else if (theLeftLimit > theRightLimit)
        {
            break;
        }
        else
        {
            if (Square(&AFigures->Rectangles[middleValue]) > aValue)
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
