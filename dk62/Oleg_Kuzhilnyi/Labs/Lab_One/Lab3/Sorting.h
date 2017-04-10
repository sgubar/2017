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
#define TEN 0xA //10
#define HUNDRED 0x64    //100
#define ONE_THOUSAND 0x3E8      //1000
#define TEN_THOUSAND 0x2710      //10000

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


/*---------------Types of Operation---------------*/
void QuickSort(theDescriptionArray *MassOfNumbers,int left,int right);  //Quick Sort
void bubbleSort(theDescriptionArray *iArray);
void selectionSort(theDescriptionArray *iArray);
void insertionSort(theDescriptionArray *iArray);
void swap(theDescriptionArray *srcArray,int x,int y);//transposition two elements of array
/*-------------------------------------------*/
int line_search(theDescriptionArray *iArray ,int aSize);

theDescriptionArray createArray(unsigned aSize);
unsigned input_in_Array(theDescriptionArray *theArray , int aValue);
void destroyArray(theDescriptionArray *iArray);

void Print_To_File (int aSize,theDescriptionArray *MassOfNumbers);

#endif /* Sorting_h */
