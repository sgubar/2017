/*
 * main.c
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#include <stdio.h>
#include "tool.h"
#include <stdlib.h>
#include <time.h>

int main(void){
	int Lenth_of_Str;
	char *String0 = Transform_file_text_to_str (&Lenth_of_Str);
	if(NULL != String0){
	clock_t theStart0 = clock();
	quickSort2(String0,  0,  Lenth_of_Str);
	clock_t theEnd0 = clock();
	printf ("time of selectionSort: %.10lf\n", (double)(theEnd0 - theStart0)/CLOCKS_PER_SEC);
	putchar('\n');
	Print_To_File(Lenth_of_Str,String0);
	clock_t theStart1 = clock();
	int Result_of_serach = BinarySearch(String0, 'a');
	clock_t theEnd1 = clock();
	printf ("time of binary search: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
	if(-1 == Result_of_serach)
		printf("\nNot found\n");
	else
		printf("\nFound in the %i position \n",Result_of_serach+1);
	free(String0);
	}
	return 0;
}
