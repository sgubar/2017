#include <stdio.h>
#include "dk_tool.h"
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	
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
		

	printPyramidList(aPyramidList);//printing pyramid list
	writePyramidList(aFile,aPyramidList);//print pyramid list in file
	destroyAllPyramid(aPyramidList);//deleting all pyramids

	_getch();

	return 0;
}