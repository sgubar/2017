#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LengthFile(FILE *aFile);
char *StrFile(FILE *aFile, int length);
void selectionSort(int length , char *MasFile);
void bubbleSort(int length , char *MasFile);
void insertionSort(int length , char *MasFile);
void shellSort(int length , char *MasFile);
int BinarySearch(int length, char *MasFile, int find);
void PrintFile(int Length , char *MasFile);
