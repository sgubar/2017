/*
 * tool.h
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#ifndef TOOL_H_
#define TOOL_H_
#include <stdio.h>
int *createArray(int Asize);
int fillingArray(int *AnArray, int Asize);
void WriteToFile(FILE *file, int *AnArray, int Asize, float Time);
float Sort(int *AnArray, int Asize);
int scan(int min, int max);
void bubbleSort(int anArray[], int aSize);
void selectionSort(int anArray[], int aSize);
void insertionSort(int anArray[], int aSize);
#endif
