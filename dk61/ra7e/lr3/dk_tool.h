#ifndef dk_tool_h
#define dk_tool_h
#define IG_SIZE 500

int readFromFile( char*charArray, char* arrayforsorting);
void printRandomToFile(FILE *aFile, char *charArray);
void bubbleSort(char *anArray);
void selectionSort(char *anArray);
void insertionSort(char *anArray);
void shellSort(char *anArray);
int printToFile(FILE *aFile,char* sortedArray);s
int binarySearch(char *anArray, char aValue, int aSize);



#endif
