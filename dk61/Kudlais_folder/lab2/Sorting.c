#include "Sorting.h"
#include <stdlib.h>
#include <stdbool.h>
#define MAXVALUE 10001
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int GetRand(void){
    int out = rand()% MAXVALUE + 0;
    return out;
}
void GetValue(int arr[], int N){
    while(N >= 0){
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
void BubbleSort(int arr[],int N){//Debug
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
    int min;
    for(int j = 0 ;j < N ;++j){
        for(int i = j; i < N; i++){
            if(i==j){
                min = i;
            }
            if(arr[i] < arr[min])
                min = i;
        }
        swap(&arr[j], &arr[min]);
    }
}
void InclusionSort(int arr[],int N){
    for(int i = 1 ;i < N ;i++){
        int j = i;
        while(arr[j] < arr[j-1] && j > 0) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}
/*void MergeSort(int arr[],int N){ Frozen until the end of atestation week
    int step = 1;
    int k;
    for(int i = 0; i < N ; i++){
        k = i;


    }
}*/
