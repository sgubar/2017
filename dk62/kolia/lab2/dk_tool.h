#ifndef sort_tools_h
#define sort_tools_h

#include<stdio.h>

int *createANarray(int Asize);

int fillingANarray(int *ANarray, int Asize);

void writeANarrayInFILE(FILE *file, int *ANarray, int Asize, float spentTime);

float chooseTheKindOfSortAndSpentTime(int *ANarray, int Asize);

void bubbleSort(int anArray[], int aSize);

void selectionSort(int anArray[], int aSize);

void insertionSort(int anArray[], int aSize);



#endif
