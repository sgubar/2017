#include "Sorting.h"
#include <stdlib.h>
#include <stdbool.h>
#define MAXVALUE 10001
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int GetRand(void){
    int out = rand()% MAXVALUE;
    return out;
}
void GetValue(int arr[], int N){
    while(N > 0){
        arr[N] = GetRand();
        --N;
    }
}
bool check(int arr[], int N){
    bool isSorted = true;
    while(N > 0){
        if(arr[N] < arr[N-1]){
            isSorted = false;
            break;
        }
    }
    return (isSorted == true ? true : false);
}
void BubbleSort(int arr[],int N){
    for(int cont = 0 ; ; ){
        for(int i = 0; i < N; ++i){
            if(arr[N] > arr[N+1]) {
                swap(&arr[N], &arr[N - 1]);
                cont++;
            }
        }
        if(cont <= 1){
            break;
        }
    }
}
void SampleSort(int arr[],int N){
    for(int j = 0 ;j < N ;j++ ){
        int min;
        int i;
        for(i = j; i < N; i++){
            if(arr[i] > arr[i+1]) {
                min = i + 1;
                ++i;
            }
        }
        swap(&arr[j], arr[i]);
    }
}
void InclusionSort(int arr[],int N){
}
void MergeSort(int arr[],int N){

}
