#ifndef SORTING_C_SORTING_H
#define SORTING_C_SORTING_H
#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b);
int GetRand(void);
void GetValue(int arr[], int N);
bool check(int arr[], int N);
void BubbleSort(int arr[],int N);
void SampleSort(int arr[],int N);
void InclusionSort(int arr[],int N);
//void MergeSort(int arr[],int N);
//void MySort(int num[],int x);;
//void advancedSample(int arr[], int N)
#endif //SORTING_C_SORTING_H