#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef laba3_h
#define laba3_h

void swap(char *line, int LeftElem, int RightElem);
int BinarySearch(char *line, char find);
void quicksort(char *line, int LeftElem, int RightElem);
int LookFile(FILE *afile);
void ReadFile(FILE *afile, char *line);

#endif

