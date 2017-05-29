#include "t.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int *createArray(int Asize)
{
	int *AnArray = malloc(sizeof(int)*Asize);
}

int fillingArray(int *AnArray, int Asize)
{
	int i = 0;
	for(i;i< Asize; i++)
	{
		AnArray[i] = rand()% 10000;
	}
}

void WriteToFile(FILE *file, int *AnArray, int Asize, float Time)
{
	fprintf(file, "Sorting time: % .10f seconds\n\n", Time);


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
	 
	
	
	if(num == 1)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
  		bubbleSort(AnArray, Asize);
  		end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;
	}
	if(num == 2)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
	    selectionSort(AnArray, Asize);
	    end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;

	}
	if(num == 3)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
		insertionSort(AnArray,Asize);
		end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;
	}
}





