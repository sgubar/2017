#include "sort_tools.h"
#include "area_tools.h"

void chooseTheKindOfSort(SquareArray *aList)//choose what kind of sort do you want to apply
{
	printf("\n\nand now choose what kind of sort do you want to apply? \n\n  press 1 for bubble sort\n\t2 for selection sort\n\t3 for insertion sort\n\nand your choise is = ");
	int what_u_want = scan(1,3);

	if(what_u_want == 1)//bubble
	{
		printf("\ncongratulations! Your choise is a BUBBLE SORT. Enjoy the result:\n\n\n ");
		sortSquareListBubble(aList);
	}
	if(what_u_want == 2)//selection
	{
		printf("\ncongratulations! Your choise is a SELECTION SORT. Enjoy the result:\n\n\n ");
		sortSquareListSelection(aList);
	}
	if(what_u_want == 3)//insertion
	{	
		printf("\ncongratulations! Your choise is an INSERTION SORT. Enjoy the result:\n\n\n ");
		sortSquareListInsertion(aList);
	}
}


void sortSquareListBubble(SquareArray *aList)// Bubble Sort
{
	int aSize = aList->size;
	int theOut = aSize - 1;
	Square theTmp;// bufer obmena
	
	for (theOut; theOut > 1; theOut --)// 1 loop
	{
		int theIn = 0;
		
		for (theIn; theIn < theOut; theIn ++)// loop in the loop
		{
			if (aList->array[theIn].area < aList->array[theIn + 1].area)
			{
				theTmp = aList->array[theIn];
				aList->array[theIn] = aList->array[theIn + 1];
				aList->array[theIn + 1] = theTmp;
			}
		}
	}


}


void sortSquareListSelection(SquareArray *aList)// Selection Sort
{
	int aSize = aList->size;
	int theOut = 0;
	for (theOut; theOut > aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;
		
		int theIn = theOut + 1;
		
		for (theIn; theIn < aSize; theIn ++)
		{
			if (aList->array[theIn].area > aList->array[theMinIndex].area)
			{
				theMinIndex = theIn;
			}
		}
	
		Square theTmp = aList->array[theOut];
		aList->array[theOut] = aList->array[theMinIndex];
		aList->array[theMinIndex] = theTmp;
	}
	
	
}

void sortSquareListInsertion(SquareArray *aList)// Insertion Sort
{
	int aSize = aList->size;
	int theOut = 1;
	
	for (theOut; theOut < aSize; theOut ++)
	{
		Square theTmp = aList->array[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && aList->array[theIn - 1].area <= theTmp.area)
		{
			aList->array[theIn] = aList->array[theIn - 1];
			-- theIn;
		}
	
		aList->array[theIn] = theTmp;
	}


}

