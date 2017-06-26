#ifndef QuickSort_h
#define QuickSort_h

#include <stdlib.h>
#include <stdio.h>

void swap(DoubleList *aList, int aLeftIndex, int aRightIndex);
double mediana(DoubleList *aList, int aLeftIndex, int aRightIndex);
int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, double aPivot);
void quickSort2(DoubleList *aList, int aLeftIndex, int aRightIndex);
void m_manualSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

#endif
