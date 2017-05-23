#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"



int main(int argc, char *argv[])
{
	FILE *aFile = fopen("random.txt","w");
	FILE *sortedFile = fopen("SortedFile.txt","w");
	char *charArray[IG_SIZE];
	char *sortingArray[IG_SIZE];

	printf("Enter some text: ");

	gets(charArray);

	printRandomToFile(aFile,charArray);


	printf("Please,select a type of sort:\n1.Selection sort,\n2.Insertion sort,\n3.Bubble sort,\n4.Shell sort.\n");

	int a;
	do
	{
	    int theTmp = scanf("%d",&a);
	    if(theTmp == 1)
	    {
		    break;
	    }
	    printf("Please,try again: ");
	    fflush(stdin);
    }
	while(1);

    float StartTime = clock();
	switch(a)
	{
		case 1:

	        readFromFile(charArray,sortingArray);
			selectionSort(sortingArray);
		    float selectionEnd = clock() - StartTime;
			printf("The time of Selection sorting is:%.0f\n",selectionEnd);
			printToFile(sortedFile,sortingArray);
			break;

		case 2:

			readFromFile(charArray,sortingArray);
			insertionSort(sortingArray);
			float insertionEnd = clock() - StartTime;
			printf("The time of Insertion sorting is:%.0f\n",insertionEnd);
			printToFile(sortedFile,sortingArray);
			break;

		case 3:

		    readFromFile(charArray,sortingArray);
			bubbleSort(sortingArray);
			float bubbleEnd = clock() - StartTime;
	        printf("The time of Bubble sorting is:%.0f\n",bubbleEnd);
	        printToFile(sortedFile,sortingArray);
	        break;

		case 4:
			readFromFile(charArray,sortingArray);
			shellSort(sortingArray,0,strlen(sortingArray) - 1);
			float quickSortEnd = clock() - StartTime;
	        printf("The time of Shell sorting is:%.0f\n",quickSortEnd);
	        printToFile(sortedFile,sortingArray);
	        break;

	}

