#include <stdio.h>
#include "dk_tool.h"
#include "sorting.h"
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sort = 0;
	int size = 0;//size of pyramidlist
	int numofpyr = 0;//mount of pyramids that you want to have


	printf("print the size of pyramid array\n");
	scanf_s("%d", &size);
	
	
	printf("print how much pyramids do you want(not bigger than %d)\n", size);
	scanf_s("%d", &numofpyr);

	FILE *aFile;
	fopen_s(&aFile, "data.json", "w");
	pyramidList *aPyramidList = createPyramidList(size);//creating pyramid list with some size


	for (int i = 0; i < numofpyr; i++)//creating 'numofpyr' pyramids
		addPyramid(aPyramidList);
		
	printf("What kind of sorting do you want to use? Please print your number\n");
	printf("1 -----  BubbleSort\n");
	printf("2 -----  SelectionSort\n");
	printf("3 ----- InsertionSort\n");

	scanf_s("%d", &sort);
	
	

	printf("------BEFORE SORTING------\n");
	printPyramidList(aPyramidList);//printing pyramid list
	

	switch (sort) {
	case 1:
		Bubble_Sort_List(aPyramidList);
		
		break;

	case 2:
		Selection_Sort_List(aPyramidList);
	
		break;

	case 3:
		Insertion_Sort_List(aPyramidList);
		break;

	default:
		printf("You have to select a number from 1 to 3");
	}
	printf("-----AFTER SORTING-----\n");
	printPyramidList(aPyramidList);


	writePyramidList(aFile,aPyramidList);//print pyramid list in file
	destroyAllPyramid(aPyramidList);//deleting all pyramids

	_getch();

	return 0;
}