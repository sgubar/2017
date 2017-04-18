#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"dk_tool.h"
#include"sorting.h"
#define SSize 2000
#define MSize 5000
#define LSize 10000
#define MEGASize 25000



int main()
{
	
	//arrays for time
	double ShellTime[4];
	double InsertionTime[4];
	double SelectionTime[4];
	double BubbleTime[4];

	//arrays for sorting
	char smallarray[SSize];
	char mediumarray[MSize];
	char largearray[LSize];
	char MegaArray[MEGASize];
	

	readarraysfromfile(smallarray, mediumarray, largearray, MegaArray);
	linear_search(smallarray, mediumarray, largearray, MegaArray);
        bubblesorting(smallarray, mediumarray, largearray, MegaArray,BubbleTime);
	insertionsorting(smallarray, mediumarray, largearray, MegaArray, InsertionTime);
	selectionsorting(smallarray, mediumarray, largearray, MegaArray, SelectionTime);
	shellsorting(smallarray, mediumarray, largearray, MegaArray, ShellTime);
	writearraystofile(smallarray, mediumarray, largearray, MegaArray);
	printtable(BubbleTime, InsertionTime, SelectionTime, ShellTime);
	
	


	_getch();

	return 0;

	









}
