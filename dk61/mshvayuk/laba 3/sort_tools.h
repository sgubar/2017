#ifndef sort_tools_h
#define sort_tools_h

#include<stdio.h>

int *createANarray(int Asize);//create an array the specified size

int fillingANarray(int *ANarray, int Asize);//filling an array with random numbers

void writeANarrayInFILE(FILE *file, int *ANarray, int Asize, float spentTime);//write an array into .txt file

void writeANarrayInCSVfile(FILE *file, int *ANarray, int Asize, float spentTime);//write an array into .csv file

float chooseTheKindOfSortAndSpentTime(int *ANarray, int Asize);//choose what kind of sort do you want to apply and return time spending on sort

void bubbleSort(int anArray[], int aSize);//bubble sort

void selectionSort(int anArray[], int aSize);//selection sort

void insertionSort(int anArray[], int aSize);//insertionsort

int scan(int min, int max);// just scanf with checking on idiot


#endif /*sort_tools_h*/

