//
// Created by Oleh on 25.03.2017.
//
#include <stdio.h>

#ifndef LW2_DK_TOOL_H
#define LW2_DK_TOOL_H

//get size of array
int getSize();

//function for get string from user
char* getString();

//get name of file
char *getNameOfFile();

//get random array
int *getArray(int size);

//make copy of array
int *makeArrayCopy(int *anArray, int size);

//get type of sort
int getTypeOfSort();

//get type of search
int getTypeOfSearch();

//get key
int getKey();

//write the result in the file
void writeIntoFile(FILE *aFile, int size, int *anArray, int *anArrayForWork, double timeSort, int searchPosition, double timeSearch, int aKey);

//destroy all arrays
void destroyAllArrays(int *anArray1, int *anArray2);

#endif //LW2_DK_TOOL_H
