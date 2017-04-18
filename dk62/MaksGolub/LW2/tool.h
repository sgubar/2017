#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int LengthFile(FILE *aFile);
char *StrFile(FILE *aFile, int length);
void selectionSort(int length , char *MasFile);
void bubbleSort(int length , char *MasFile);
void insertionSort(int length , char *MasFile);
void PrintFile(int Length , char *MasFile);
