#ifndef sort_h
#define sort_h
#include "dk_tool.h"
void bubbleSort(ParpipedList *aParpiped);
void selectionSort(ParpipedList *aParpiped);
void insertionSort(ParpipedList *aParpiped);
void m_manualSort(ParpipedList *aParpiped, int aLeftIndex, int aRightIndex);
void quickSort2(ParpipedList *aParpiped, int aLeftIndex, int aRightIndex);
int m_partitionIt(ParpipedList  *aParpiped, int aLeftIndex, int aRightIndex, int aPivot);
int mediana(ParpipedList  *aParpiped, int aLeftIndex, int aRightIndex);
void swap(ParpipedList  *aParpiped, int aLeftIndex, int aRightIndex);

#endif
