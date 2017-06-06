#ifndef Sort_h
#define Sort_h

void swap(DoubleList *aList, int aLeftIndex, int aRightIndex);
int mediana(DoubleList *aList, int aLeftIndex, int aRightIndex);
int m_partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort2(DoubleList *aList, int aLeftIndex, int aRightIndex);
void m_manualSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

#endif
