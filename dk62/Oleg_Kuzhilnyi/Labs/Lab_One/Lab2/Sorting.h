//
//  Sorting.h
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#define ELEMENTS 10000 //amount of numbers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Input(FILE *aFile,int *MassOfNumber);//fuction for write in .txt file
void Output(FILE *aFile,int *MassOfNumber);//fuction for read from .txt file
void Random(int *MassOfNumber);//make a random array
void swap(int v[],int i,int j);//transposition two elements of array

/*---------------Types of sort---------------*/
void BubbleSort(int *MassOfNumber);
void SelectSort(int *MassOfNumber);
void QuickSort(int *MassOfNumber,int low,int high);
void ShellsSort(int *MassOfNumber);
/*-------------------------------------------*/


#endif /* Sorting_h */
