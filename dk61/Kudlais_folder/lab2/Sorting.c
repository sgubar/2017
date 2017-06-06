#include "Sorting.h"
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
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
    while(N > 0){
        if(arr[N] < arr[N-1]){
            return false;
        }
        N--;
    }
    return true;
}
void BubbleSort(int p[],int N) {
    int counter = 0;
    do {
        counter = 0;
        for (int i = 0; i < N; i++) {
            if (p[i] > p[i + 1]) {
                swap(&p[i], &p[i + 1]);
                counter++;
            }
        }
    }while(counter);//if counter is 0, than cycle will stop
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

