#ifndef dk_tool_h
#define dk_tool_h

void fillingArrayFunction(char *anArray, int aSize);
void fileWrite(FILE *ptrFile, char *anArray, int aSize);

void sortType(FILE *ptrFile, char *anArray, int aSize);

void bubbleSort(char *anArray, int aSize);
void selectionSort(char *anArray, int aSize);
void insertionSort(char *anArray, int aSize);
void shellSort(char *anArray, int aSize);

int binarySearch(char *anArray, int aSize, char searchLetter);
int searchFunction(char *anArray, int aSize);

int NumInput(void);
char letterInput(void);

#endif
