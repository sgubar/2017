#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"
#include "sorting.h"
#define arrSize 10000
int main(void)
{
	char unsortedarray[arrSize];
	char arrayforsorting[arrSize];
	int switcher;
	


	printf("print symbols for unsortedarray\n");
	gets(unsortedarray);
	
	
	
	FILE *unsortedfile;
	fopen_s(&unsortedfile, "unsorted.txt", "w");

	PrintToFile(unsortedfile, unsortedarray);
	ReadingFromFile(unsortedfile, unsortedarray,arrayforsorting);

	printf("the amount of symbols :%d\n", strlen(arrayforsorting));
	FILE*sortedfile;
	fopen_s(&sortedfile, "sorted.txt", "w");

	printf("What kind of sorting do you want to use? Please print your number\n");
	printf("1 -----  BubbleSort\n");
	printf("2 -----  SelectionSort\n");
	printf("3 -----  InsertionSort\n");
	scanf_s("%d", &switcher);

	switch (switcher)

	{
	case 1:
		clock_t start1 = clock();
		BubbleSort(arrayforsorting);
		clock_t end1 = clock();
		PrintSortedArraytoFile(sortedfile, arrayforsorting);
		printf("time of sorting by BubbleSort: %.10lf\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
		break;

	case 2:
		clock_t start2 = clock();
		SelectionSort(arrayforsorting);
		clock_t end2 = clock();
		PrintSortedArraytoFile(sortedfile, arrayforsorting);
	
		printf("time of sorting by SelectionSort: %.10lf\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
		break;

	case 3:
		clock_t start3 = clock();
		InsertionSort(arrayforsorting);
		clock_t end3 = clock();
		PrintSortedArraytoFile(sortedfile, arrayforsorting);
		printf("time of sorting by InsertionSort: %.10lf\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
		break;


	default:
		printf("You have to select a number from 1 to 3");
		
	}

	_getch();
	
	return 0;
}

