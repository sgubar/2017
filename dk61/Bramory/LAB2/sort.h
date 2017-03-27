#ifndef sort_h
#define sort_h

/*
	sort array
*/
void bubble_sort( int size, char *srcArray );

/*
	Searching minimal element and get sort him. 
*/
void selection_sort( int size, char *srcArray );

/*
	Sort. 
*/
//void insertion_sort( int size, char *srcArray );
void insertion_sort(char anArray[], int aSize);

/*
	More fabulous sort than insertion_sort 
*/
void shell_sort( int size, char *srcArray );

/*
	 sort
void merge_sort(int low, int high, char *srcArray, char *temp);
void merging(int low, int mid, int high, char *srcArray, char *temp) ;
*/

/*
	Function search required number in the pre-sorted array of characters
	Return 1 (true) if search is success, else return -1 (false) 
*/
int binary_search(char key, int size, char *srcArray);

/*
	Function search required number in the any array of characters
	Return 1 (true) if search is success, else return -1 (false) 
*/
int line_search(char key, int size, char *srcArray);

#endif
