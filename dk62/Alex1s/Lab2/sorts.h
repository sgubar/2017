#ifndef sorts_h
#define sorts_h

void merge(int array_size, int *array, int l, int r);
void mergesort(int array_size, int *array, int l, int m, int r);
void bubblesort(int *array, int array_size);
void selectionsort(int *array, int array_size);
void insertionsort(int *array, int array_size);
void shellsort(int *array, int array_size);
void quicksort(int *array, int first, int last);

void print_array(int *array, int array_size);
void swap(int *val1, int *val2);

#endif 
