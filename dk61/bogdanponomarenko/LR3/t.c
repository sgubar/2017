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

void Show(int *AnArray, int Asize, float Time)
{
	printf("Sorting time: % .5f seconds\n\n", Time);
	printf("Size of array is %d \n \n",Asize);
	for(int i=0;i<Asize; i++)
	{
		printf( "Number[%i] %i \n", i+1, AnArray[i]);
	}
printf( "\n \n ");
}



float Sort(int *AnArray, int Asize)
{
	int num=0;
	printf("\n\n Choose kind of sort:  \n\n 1 -- bubble \n 2 -- selection \n 3 -- insertion \n 4 -- quicksort\n\n  ");
	scanf("%d",&num);
	 
	
	float Time= clock();
	if(num == 1)
	{
		
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
  		bubbleSort(AnArray, Asize);
  	 float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f\n\n\n ", endTime);
	}
	if(num == 2)
	{
	
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
	    selectionSort(AnArray, Asize);
	   float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f\n\n\n ", endTime);

	}
	if(num == 3)
	{
	
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
		insertionSort(AnArray,Asize);
		
  		float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  	printf("\n Time of sorting %.5f \n\n\n ", endTime);
	}
	
	if(num == 4)
	{
	
		quickSort(AnArray, 0, Asize-1);
	float endTime = (clock()-Time)/CLOCKS_PER_SEC;
  		printf("\n Time of sorting %.5f seconds\n\n\n ", endTime);
	}
}






