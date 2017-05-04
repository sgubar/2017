#ifndef sort_tools_h
#define sort_tools_h

#include<stdio.h>
#include "area_tools.h"

void chooseTheKindOfSort(SquareArray *aList);//choose what kind of sort do you want to apply
//what_u_want - a variable what define what kind of sort will be used

void sortSquareListBubble(SquareArray *aList);// Bubble Sort

void sortSquareListSelection(SquareArray *aList);// Selection Sort

void sortSquareListInsertion(SquareArray *aList);// Insertion Sort

#endif /*sort_tools_h*/


