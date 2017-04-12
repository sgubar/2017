//
// Created by Oleh on 25.03.2017.
//
#include <stdio.h>

#ifndef LW2_DK_TOOL_H
#define LW2_DK_TOOL_H

typedef struct arrayWithT
{
    int *anArray;
    double time;
}arrayWithT;

//get information from user
int getSize();
char *getNameOfFile();
char* getString();

//get random array
int *getArray(int size);

//make copy of array
int *makeArrayCopy(int *anArray, int size);

//write all in the file
void writeIntoFile(FILE *aFile, int size, int *anArray, arrayWithT *anArrayWithTBub, arrayWithT *anArrayWithTSelect, arrayWithT *anArrayWithTInsert, arrayWithT *anArrayWithTShell, arrayWithT *anArrayWithTQuick);

//destroy all arrays
void destroyAllArrays(int *anArray, int *anArray1, int *anArray2, int *anArray3, int *anArray4, int *anArray5);

#endif //LW2_DK_TOOL_H
