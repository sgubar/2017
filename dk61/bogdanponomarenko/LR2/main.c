#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "t.h"
#include <time.h>

int main()
{


	FILE *sorted_massiv  = fopen("result.txt", "w+");//create a .txt file, where we write an array after sorting

	float Time = 0; 

	int SizeOfArray;
	
	printf("what is the size of your array? (within 1 ... 10000) = ");
	
	scanf("%d",&SizeOfArray);
	 
	int *AnArray =	createArray(SizeOfArray);

	fillingArray(AnArray, SizeOfArray);

  	Sort(AnArray,SizeOfArray);

	WriteToFile(sorted_massiv, AnArray, SizeOfArray, Time);//after sort

fclose(sorted_massiv);
}
