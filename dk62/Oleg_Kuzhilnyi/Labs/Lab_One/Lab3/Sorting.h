//
//  Sorting.h
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#define AMOUNT 10000
#define ZERO 0 //amount of numbers
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


/*---------------Types of sort---------------*/
void QuickSort(theDescriptionArray *MassOfNumbers,int left,int right);  //Quick Sort
void bubbleSort(theDescriptionArray *iArray);
void selectionSort(theDescriptionArray *iArray);
void insertionSort(theDescriptionArray *iArray);
void swap(theDescriptionArray *srcArray,int x,int y);//transposition two elements of array
/*-------------------------------------------*/
int line_search(theDescriptionArray *iArray ,int aSize);

theDescriptionArray createArray(unsigned aSize);
unsigned input_in_Array(theDescriptionArray *theArray , int aValue);

void Print_To_File (int aSize,theDescriptionArray *MassOfNumbers);


//void printArray(theDescriptionArray *theArray);

#endif /* Sorting_h */
