/*
 * main.c
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#include <stdio.h>
#include "tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	float Time = 0;
	int SizeOfArray;
	FILE *sorted_massiv  = fopen("result.txt", "w+");
	printf("what is the size of your array? (within 1 ... 10000) = ");
	scanf("%d",&SizeOfArray);
	int *AnArray =	createArray(SizeOfArray);
	fillingArray(AnArray, SizeOfArray);
 	Time = Sort(AnArray,SizeOfArray);
	WriteToFile(sorted_massiv, AnArray, SizeOfArray, Time);
	fclose(sorted_massiv);
	scanf("%d",&SizeOfArray);

}
