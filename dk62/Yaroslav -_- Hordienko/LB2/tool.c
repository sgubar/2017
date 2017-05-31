/*
 * tool.c
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */
#include "tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>


void bubbleSort(int anArray[], int aSize)
{
	int theOut = aSize - 1;

	for (theOut; theOut > 1; theOut --)
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] < anArray[theIn + 1])
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
			if (anArray[theIn] > anArray[theMinIndex])
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

		while (theIn > 0 && anArray[theIn - 1] <= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}

		anArray[theIn] = theTmp;
	}
}
int *createArray(int Asize)
{
	int *AnArray = malloc(sizeof(int)*Asize);
}
int fillingArray(int *AnArray, int Asize)
{

	for(int i = 0; i < Asize; i++)
	{
		AnArray[i] = rand()% 10000;
	}
}
void WriteToFile(FILE *file, int *AnArray, int Asize, float Time)
{
	fprintf(file, "Sorting time: % .5f seconds\n\n", Time);
	fprintf(file,"Size of array is %d \n \n",Asize);
	for(int i=0;i<Asize; i++)
	{
		fprintf(file, "Number[%i] %i \n", i+1, AnArray[i]);
	}

}
float Sort(int *AnArray, int Asize)
{
	int num=0;
	printf("\n\n Choose kind of sort:  \n\n 1 -- bubble \n 2 -- selection \n 3 -- insertion \n\n  ");
	scanf("%d",&num);


	float Time= clock();
	if(num == 1)
	{

  		bubbleSort(AnArray, Asize);
  	 float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f\n\n\n ", endTime);
	}
	if(num == 2)
	{
	    selectionSort(AnArray, Asize);
	   float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f\n\n\n ", endTime);

	}
	if(num == 3)
	{
		insertionSort(AnArray,Asize);
  		float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f \n\n\n ", endTime);
  	return endTime;
	}
}
