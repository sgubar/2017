//
// Created by Oleh on 25.03.2017.
//
#include <stdio.h>

#ifndef LW2_DK_TOOL_H
#define LW2_DK_TOOL_H

//get size from user
int getSize();

//get random array
int *getArray(int size);

//make copy of array
int *makeArrayCopy(int *anArray, int size);

//write all in the file
void writeIntoFile(FILE *aFile, int size, int *anArray1, int *anArray2, int *anArray3, double *timeBubbleSort, double *timeSelectionSort, double *timeInsertSort);


void destroyAllArrays(int *anArray1, int *anArray2, int *anArray3);

#endif //LW2_DK_TOOL_H
