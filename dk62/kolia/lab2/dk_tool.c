#include "dk_tool.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int *createANarray(int Asize)
{
	int *ANarray = malloc(sizeof(int)*Asize);
}

int fillingANarray(int *ANarray, int Asize)
{
	int i = 0;
	for(i;i< Asize; i++)
	{
		ANarray[i] = rand()% 10000;
	}
}

void writeANarrayInFILE(FILE *file, int *ANarray, int Asize, float spentTime)
{
	fprintf(file, "time, what was spented on sort: % .4f seconds\n\n", spentTime);
	int i = 0;
	for(i;i<Asize; i++)
	{
		fprintf(file, " %i \n", ANarray[i]);
	}

}

float chooseTheKindOfSortAndSpentTime(int *ANarray, int Asize)
{
	printf("\n\nAnd now choose what kind of sort do you want to apply? \n\n  press 1 for bubble sort\n\t2 for selection sort\n\t3 for insertion sort\n\nand your choise is = ");
	int choice = scan(1,3);

	if(choice == 1)

		float start, the_end;
		start = clock();
		printf("\nYour choice is a BUBBLE SORT. The result:\n\n ");
  		bubbleSort(ANarray, Asize);
  		the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;
	}
	if(choice == 2)
	{
		float start, the_end;
		start = clock();
		printf("\nYour choise is a SELECTION SORT. The result:\n\n\n ");
	    selectionSort(ANarray, Asize);
	    the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;

	}
	if(choice == 3)
	{
		float start, the_end;
		start = clock();
		printf("\nYour choice is an INSERTION SORT. The result:\n\n ");
		insertionSort(ANarray,Asize);
		the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;
	}
}


void bubbleSort(int anArray[], int aSize)
{
	int theOut = aSize - 1;

	for (theOut; theOut > 1; theOut --)
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}


void selectionSort(int anArray[], int aSize)
{
		int theOut = 0;
	for (theOut; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;

		int theIn = theOut + 1;
		for (theIn; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}


void insertionSort(int anArray[], int aSize)
{
	int theOut = 1;
	for (theOut; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}

		anArray[theIn] = theTmp;
	}
}


int scan(int min, int max)
{

	int buffer;
	int q;
	do
	{
	q = scanf("%i", &buffer);

	fflush(stdin);

	if((buffer<min || buffer>max) || q!=1)
	{
		printf("\ngive me the correct number pls!");
	}

	}

	while ((buffer<min || buffer>max) || q!=1);

	return buffer;

}


