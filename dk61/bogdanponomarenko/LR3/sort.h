#ifndef sort_h
#define sort_h

#include <stdio.h>

void bubbleSort(int anArray[], int aSize);

void selectionSort(int anArray[], int aSize);

void insertionSort(int anArray[], int aSize);

int partitionIt(int anArray[], int aLeftIndex, int aRightIndex, int aPivot);

void quickSort(int anArray[], int aLeftIndex, int aRightIndex);

//void QuickSort(int anArray[], int first,int last);
#endif 



