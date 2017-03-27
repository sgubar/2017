#ifndef tool_h
#define tool_h

/*
	Return random symbol in [min...max]  area.
*/
char random_char (char min, char max);

/*
	Take the address (&) of 2 variables and change their values
*/
void swap (char *var1, char *var2);

/*
	Fill array with random symbols from [..] area.
*/
void fillArrayChar(char min, char max, int size, char *srcArray);

/*

*/
void print_array(int size, char *srcArray);

/*
	Get text From File
	Return *ptrArray, filled only with alpha (a-z, A-Z).
*/
char *scan_text(int *size, char *filename);

/*
	Put srcArray in a file
	Return 0 if it's complete else return -1
*/
int fileWrite(char *filename, int size, char *srcArray);

/*
	Return 0
*/
int read_filename( char* inputFile, int aSize);


#endif
