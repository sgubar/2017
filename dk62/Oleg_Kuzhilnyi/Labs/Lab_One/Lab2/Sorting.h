//
//  Sorting.h
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#define aSizeOf 10000 //amount of numbers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Input(FILE *aFile,int *MassOfNumbers,int aSize);//fuction for write in .txt file
void Output(FILE *aFile,int *MassOfNumbers,int aSize);//fuction for read from .txt file
void Random(int *MassOfNumbers,int aSize);//make a random array
void swap(int v[],int i,int j);//transposition two elements of array

/*---------------Types of sort---------------*/
void BubbleSort(int *MassOfNumbers,int aSize);
void SelectSort(int *MassOfNumbers,int aSize);
void QuickSort(int *MassOfNumbers,int low,int high);
void ShellsSort(int *MassOfNumbers,int aSize);
/*-------------------------------------------*/


#endif /* Sorting_h */
