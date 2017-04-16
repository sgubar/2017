//
//  Sorting.h
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#define ZERO 0
#define HUNDRED 0x64                  //10
#define ONE_THOUSAND 0x3e8           //100
#define TEN_THOUSAND 0x2710         //1000
#define TWENTY_THOUSAND 0x4e20     //20000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct MassArray    //Descript of Array
{
    int *value;
    unsigned current_size;
    unsigned maxSize;
    
}theDescriptionArray;

typedef struct Times
{
    float TheTime[4];
    
}TheTypeOfTimes_ForDifferentSize;


typedef struct Clock_ListTime
{
    TheTypeOfTimes_ForDifferentSize For_Q_Sort;
    TheTypeOfTimes_ForDifferentSize For_B_Sort;
    TheTypeOfTimes_ForDifferentSize For_I_Sort;
    TheTypeOfTimes_ForDifferentSize For_S_Sort;
    
}TheArrayList;

/*---------------Types of Operation---------------*/
void quickSort(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex);  //Quick Sort
void bubbleSort(theDescriptionArray *iArray);
void selectionSort(theDescriptionArray *iArray);
void insertionSort(theDescriptionArray *iArray);
void swap(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex); //transposition two elements of array
/*-------------------------------------------*/
int line_search(theDescriptionArray *iArray ,unsigned aSize);

theDescriptionArray *createArray(unsigned aSize);
unsigned input_in_Array(theDescriptionArray *theArray , int aValue);
void destroyArray(theDescriptionArray *iArray);
float TheResultOfTimePoint(float aTime);
void TheSorts_For_DifferentArrays(theDescriptionArray *Small, theDescriptionArray *Medium, theDescriptionArray *theBig , theDescriptionArray *TheBiggest);
void FillingInTypeOfArrays(theDescriptionArray *iArray);
void Print_To_File (theDescriptionArray *ArrayOfNumbers,unsigned aSize);
void PrintfTheResultTable(TheArrayList *VariableTime);
int rrand(int range_min, int range_max);
int partitionIt(theDescriptionArray anArray[], int aLeftIndex, int aRightIndex, int aPivot);
#endif /* Sorting_h */
