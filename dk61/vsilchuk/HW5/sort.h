#ifndef sort_h
#define sort_h

#include "dk_tool.h"

void sortType(FILE * ptrFile, pyramidsList *aPyramidsList);

void swap(pyramid *var1, pyramid *var2);

void bubbleSort(pyramidsList *aPyramidsList);
void selectionSort(pyramidsList *aPyramidsList);
void insertionSort(pyramidsList *aPyramidsList);

void shellSort(pyramidsList *aPyramidsList);

#endif
