#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "dk_tool.h"

int main(void)
{

	FILE *after_sort  = fopen("afterSort.txt", "w+");//create a .txt file, where we write an array after sorting

	float spentTime = 0;

	printf("what is the size of your array? (must be > 1) = ");
	int sizeANarray = scan(1,50000);

	int *ANarray =	createANarray(sizeANarray);

	fillingANarray(ANarray, sizeANarray);

  	spentTime = chooseTheKindOfSortAndSpentTime(ANarray,sizeANarray);

	writeANarrayInFILE(after_sort, ANarray, sizeANarray, spentTime);//after sort


	printf("\n that's all, please check the .txt files to look on result");

}
