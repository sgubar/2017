#ifndef sorting_h
#define sorting_h
#include <stdio.h>

void ShellSort(char * array, int size);
void BubbleSort(char * array, int size);
void SelectionSort(char * array,int size);
void InsertionSort(char * array, int size);
void quickSort(char* anArray, int aLeftIndex, int aRightIndex);
int partitionIt(char *anArray, int aLeftIndex, int aRightIndex, int aPivot);
#endif