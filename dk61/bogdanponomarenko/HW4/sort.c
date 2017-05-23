#include <stdio.h>
#include "sort.h"
#include "t.h"

void Bubble_Sort(ListFigures *aFigures)
{
    int i, j, result;
    for (i = 1; i < aFigures->current_size; i++)
    {
        result = 0;
        for (j = 1; j < aFigures->current_size - i + 1; j++)
        {
            if (Square(&(aFigures->Rectangles[j])) > Square(&(aFigures->Rectangles[j - 1])))
            {
                swap(&(aFigures->Rectangles[j]), &(aFigures->Rectangles[j - 1]));
                result++;
            }
        
        if (!result)
			break;
}
}
};

void Selection_Sort(ListFigures *aFigures)
{
    int theIn, theOut, max, temp;
    for (theIn = 0; theIn < aFigures->current_size; theIn++)
    {
        max = theIn;
        for (theOut = theIn + 1; theOut < aFigures->current_size; theOut++)
        {
            if (Square(&aFigures->Rectangles[theOut]) > Square(&aFigures->Rectangles[max]))
                max = theOut;
        }
        if (max != theIn)      //if it's not sorted
            swap(&aFigures->Rectangles[theIn], &aFigures->Rectangles[max]);
    }
};


void Insertion_Sort(ListFigures *aFigures)
{
    for (int theOut = 1; theOut < aFigures->current_size; theOut++)
    {
    	Rectangle tempRectangle = aFigures->Rectangles[theOut];
        int theIn = theOut;

        while (theIn > 0 && Square(&aFigures->Rectangles[theIn - 1]) <= Square(&tempRectangle))
        {
            aFigures->Rectangles[theIn] = aFigures->Rectangles[theIn - 1];
            --theIn;
        }
        aFigures->Rectangles[theIn] = tempRectangle;
    }
};
