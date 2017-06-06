/*
 * tool.h
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#ifndef TOOL_H_
#define TOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int BinarySearch(char *String, char toFind);
char *Transform_file_text_to_str (int *InpInt);
void Print_To_File (int Lenth_of_Str,char *PStr);
void m_manualSort(char *anArray, int aLeftIndex, int aRightIndex);
void quickSort2(char *anArray, int aLeftIndex, int aRightIndex);
int m_partitionIt(char *anArray, int aLeftIndex, int aRightIndex, char aPivot);
char mediana(char *anArray, int aLeftIndex, int aRightIndex);
void swap(char *anArray, int aLeftIndex, int aRightIndex);

#endif
