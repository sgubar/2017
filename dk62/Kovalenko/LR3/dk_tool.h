#ifndef dk_tool_h
#define dk_tool_h

void bubbleSort(char tekst[], int dlinna);

void selectionSort(char tekst[], int dlinna);

void insertionSort(char tekst[], int dlinna);

void shellSort(char tekst[], int dlinna);

int binarySearch(char *tekst, int dlinna, char search);

int dlinnateksta(char *name);

char *FileToStr(void);

void PrintToFile(char *String);

#endif
