#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int Lenght_of_Str;
	char *String0 = Transform_file (&Lenght_of_Str);
	if(NULL != String0)
	{
		clock_t theStart0 = clock();
		selectionSort(Lenght_of_Str,String0);
		clock_t theEnd0 = clock();
		printf ("time of selectionSort: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
		putchar('\n');
	}
	
	char *String1 = Transform_file (&Lenght_of_Str);
	if(NULL != String1)
	{
		clock_t theStart1 = clock();
		bubbleSort(Lenght_of_Str,String1);
		clock_t theEnd1 = clock();
		printf ("time of bubbleSort : %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
		putchar('\n');
	}
	
	char *String2 = Transform_file (&Lenght_of_Str);
	if(NULL != String2)
	{
	clock_t theStart2 = clock();
	insertionSort(Lenght_of_Str,String2);
	clock_t theEnd2 = clock();
	printf ("time of insertionSort: %.10lf\n", (double)(theEnd2 - theStart2)/CLOCKS_PER_SEC);	
	putchar('\n');
	}
	
	free(String0);
	free(String1);
	free(String2);	
	
	
	return 0;
}
