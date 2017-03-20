#include <stdio.h>
#include "sort.h"
#include "tool.h"

//Sort
void Bubble_Sort_List(FigureList *aList)
{
		int i, j, result;
	for (i = 1; i < aList->current_size; i++)
	{
		result = 0; 						//	flag: sorted
		for (j = 1; j < aList->current_size-i+1; j++)   
		{
	          if ( Square( &aList->circles[j] ) > Square( &aList->circles[j-1] ) )
	        {
				swap(&aList->circles[j], &aList->circles[j-1]);
	        	result ++; 					//	flag: not sorted
	        }
		}	
		if(!result) break;
	}
}

void Selection_Sort_List(FigureList *aList)
{
		int theIn, theOut, max, temp;
	    for (theIn = 0; theIn < aList->current_size; theIn++)   
    {
        max = theIn;
        for (theOut = theIn+1; theOut < aList->current_size; theOut++)
        {
            if ( Square( &aList->circles[theOut] ) > Square( &aList->circles[max] ) )
                max = theOut;
		}
            if ( max != theIn)      //if it's not sorted
				swap( &aList->circles[theIn], &aList->circles[max]);
    }	
}


void Insertion_Sort_List(FigureList *aList)
{
	int theOut;
	for ( theOut = 1; theOut < aList->current_size; theOut ++)
	{
		Circle tmpCircle = aList->circles[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && Square( &aList->circles[theIn - 1] ) <= Square( &tmpCircle) )
		{
			aList->circles[theIn] = aList->circles[theIn - 1];
			-- theIn;
		}
		aList->circles[theIn] = tmpCircle;
	}
}


