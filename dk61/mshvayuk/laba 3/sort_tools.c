#include "sort_tools.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
 
int *createANarray(int Asize)//create an array the specified size
{
	int *ANarray = malloc(sizeof(int)*Asize);
	return ANarray;
}

int fillingANarray(int *ANarray, int Asize)//filling an array with random numbers
{
	int i = 0;
	for(i;i< Asize; i++)
	{
		ANarray[i] = rand()% 10000;//make a diapazon [0;10000]
	}
}

void writeANarrayInFILE(FILE *file, int *ANarray, int Asize, float spentTime)//write an array into .txt file
{
	fprintf(file, "time, what was spented on sort: % f seconds\n\n", spentTime);
	int i = 0;
	for(i;i<Asize; i++)
	{
		fprintf(file, " %i \n", ANarray[i]);
	}
	
}

void writeANarrayInCSVfile(FILE *file, int *ANarray, int Asize, float spentTime)//write an array into .csv file
{
	fprintf(file, "time, spent on sort: % f seconds\n\n", spentTime);
	int i = 0;
	for(i;i<Asize; i++)
	{
		fprintf(file, "%i;", ANarray[i]);
	}
	
}

float chooseTheKindOfSortAndSpentTime(int *ANarray, int Asize)//choose what kind of sort do you want to apply and return time spending on sort
{
	printf("\n\nand now choose what kind of sort do you want to apply? \n\n  press 1 for bubble sort\n\t2 for selection sort\n\t3 for insertion sort\n\nand your choise is = ");
	int what_u_want = scan(1,3);

	if(what_u_want == 1)//bubble
	{
		float start, the_end;
		start = clock();
		printf("\ncongratulations! Your choise is a BUBBLE SORT. Enjoy the result:\n\n\n ");
  		bubbleSort(ANarray, Asize);
  		the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;
	}
	if(what_u_want == 2)//selection
	{
		float start, the_end;
		start = clock();
		printf("\ncongratulations! Your choise is a SELECTION SORT. Enjoy the result:\n\n\n ");
	    selectionSort(ANarray, Asize);
	    the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;

	}
	if(what_u_want == 3)//insertion
	{	
		float start, the_end;
		start = clock();
		printf("\ncongratulations! Your choise is an INSERTION SORT. Enjoy the result:\n\n\n ");
		insertionSort(ANarray,Asize);
		the_end = clock();
  		float timeSpentOnSort = ((the_end - start)/CLK_TCK);
  		return timeSpentOnSort;
	}
}

	
void bubbleSort(int anArray[], int aSize)//bubble sort
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


void selectionSort(int anArray[], int aSize)//selection sort
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


void insertionSort(int anArray[], int aSize)//insertion sort
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


int scan(int min, int max)// just scanf with checking on idiot
{
	
	int buffer;// variable for saving that what we scanned
	int q;// variable for checking on idiot
	do
	{
	q = scanf("%i", &buffer);
	
	fflush(stdin);// without this it willn't work correctly
	
	if((buffer<min || buffer>max) || q!=1)
	{
		printf("\ngive me the correct number pls!");	
	}		
	
	}
	
	while ((buffer<min || buffer>max) || q!=1);
	
	return buffer;	

}
