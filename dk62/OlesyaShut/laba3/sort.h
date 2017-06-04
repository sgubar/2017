#ifndef sort_h
#define sort_h

void swap(int *Val1, int *Val2);

void bubblesort(int *array, int aSize);
void selectionsort(int *array, int aSize);
void insertionsort(int *array, int aSize);
void shellsort(int *array, int aSize);
void quicksort(int *array, int first, int last);

int lineSearch(int val, int aSize, int *array);

#endif
