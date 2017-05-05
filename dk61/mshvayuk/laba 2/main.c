#include <stdio.h>
#include<stdlib.h>
#include <time.h>
 
#include "sort_tools.h"

int main(void)
{
	FILE *before_sort = fopen("beforeSort.txt", "w+");//create a .txt file, where we write an array before sorting
	FILE *after_sort  = fopen("afterSort.txt", "w+");//create a .txt file, where we write an array after sorting
	FILE *CSV_before_sort = fopen("beforeSort.csv", "w+");//create a .csv file, where we write an array before sorting
	FILE *CSV_after_sort = fopen("afterSort.csv", "w+");//create a .csv file, where we write an array after sorting

	float spentTime = 0;

	printf("what is the size of your array? (min = 1, max = 20000) = ");
	int sizeANarray = scan(1,20000);
	
	int *ANarray =	createANarray(sizeANarray);
	
	fillingANarray(ANarray, sizeANarray);
	
	writeANarrayInFILE(before_sort, ANarray, sizeANarray, spentTime);// before sort
	writeANarrayInCSVfile(CSV_before_sort, ANarray, sizeANarray, spentTime);
	
  	spentTime = chooseTheKindOfSortAndSpentTime(ANarray,sizeANarray);
  	
	writeANarrayInFILE(after_sort, ANarray, sizeANarray, spentTime);//after sort
	writeANarrayInCSVfile(CSV_after_sort, ANarray, sizeANarray, spentTime);

	
	printf("\n that's all, please check the .txt files to look on result");
	
}
