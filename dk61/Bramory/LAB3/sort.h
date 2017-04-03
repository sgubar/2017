#ifndef sort_h
#define sort_h

/*
	sort array
*/
void bubble_sort( int aSize, int *srcArray );

/*
	Searching minimal element and get sort him. 
*/
void selection_sort( int aSize, int *srcArray );

/*
	Sort. 
*/
//void insertion_sort( int aSize, int *srcArray );
void insertion_sort(int aSize, int *anArray);

/*
	More fabulous sort than insertion_sort 
*/
void shell_sort( int aSize, int *srcArray );

void quick_sort(int A[], int b0, int e0);

#endif
