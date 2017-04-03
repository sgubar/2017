#ifndef tool_h
#define tool_h

//return only numbers
int num_scan( void );

/*
	Return random symbol in [min...max]  area.
*/
int random_char (int min, int max);

/*
	Take the address (&) of 2 variables and change their values
*/
void swap (int *var1, int *var2);

/*
	Fill array with random symbols from [..] area.
*/
void fillArrayInt(int min, int max, int aSize, int *srcArray);

/*

*/
void print_array(int aSize, int *srcArray);

/*
	Get numbers from file
	Return *ptrArray, filled only with unsigned numbers.
*/
int *read_num(int *aSize, char *filename);

/*
	Put srcArray in a file
	Return 0 if it's complete else return -1
*/
int fileWrite(char *filename, int aSize, int *srcArray);

/*
	Return 0
*/
int read_filename( char* inputFile, int aSize);

//Return 0 if we found key in array, else -1
int binary_search(int key, int aSize, int *srcArray);// require sorted array
int line_search(int key, int aSize, int *srcArray);


void printArray(int A[], int aSize );


#endif
