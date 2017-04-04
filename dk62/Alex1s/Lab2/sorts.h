#ifndef sorts_h
#define sorts_h

void merge(int rzmr, int *array, int l, int r);
void mergesort(int rzmr, int *array, int l, int m, int r);

void bubblesort(int *array, int rzmr);
void selectionsort(int *array, int rzmr);
void insertionsort(int *array, int rzmr);

void shellsort(int *array, int rzmr);
void quicksort(int *array, int first, int last);

void print_array(int *array, int rzmr);
void swap(int *val1, int *val2);

#endif 
