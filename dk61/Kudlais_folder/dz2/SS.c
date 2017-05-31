#include "SS.h"
#include <stdbool.h>
#include "figure.h"

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}//Unused now
void Sqswap(square *a,square *b){
    square tmp = *a;
    *a = *b;
    *b = tmp;
}
bool isSorted(square arr[], int N){
    while(N > 0){
        if(arr[N].square < arr[N-1].square){
            return false;
        }
        N--;
    }
    return true;
}
void BubbleSort(square arr[],int N) {
    int counter = 0;
    do {
         counter = 0;
        for (int i = 1; i < N; i++) {
            if (arr[i-1].square > arr[i].square) {
                Sqswap(&arr[i-1], &arr[i]);
                counter++;
            }
        }
    }while(counter);//if counter is 0, than cycle will stop
}
void SampleSort(square arr[],int N){
    int min;
    for(int j = 0 ;j < N ;++j){
        for(int i = j; i < N; i++){
            if(i==j){
                min = i;
            }
            if(arr[i].square < arr[min].square)
                min = i;
        }
        Sqswap(&arr[j], &arr[min]);
    }
}
void InclusionSort(square arr[],int N){
    for(int i = 1 ;i < N ;i++){
        int j = i;
        while(arr[j].square < arr[j-1].square && j > 0) {
            Sqswap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}
int Lsearch(square arr[],int n, int k){ //search position of number k in the array with size n
    for (int i = 0; i < n; ++i)
        if(arr[i].square == k)
            return i;
    return  -1; //in case if array (arr) doesn't have value of k
}
void Shellsort(square mas[], int n){ //sort array mas with size n by the method of Shell
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; ++i) {
            for (int j = i-gap; j >= 0 && mas[j].square > mas[j+gap].square; j -=gap)
                Sqswap(&mas[j],&mas[j+gap]);
        }
    }
}
void QuickSort(square arr[],int zero, int n){
    /*if(zero >= n)
        return;
    int wall = zero;
    int pivot = n-1;
    for (int currel = zero; currel < n-1; ++currel) {
        if (arr[pivot].square > arr[currel].square) {
            Sqswap(&arr[wall], &arr[currel]);
            wall++;
        }
    }
    Sqswap(&arr[pivot],&arr[wall]);
    wall++;;
    QuickSort(arr,zero,wall);
    QuickSort(arr,wall+1,n);*/
    int wall;
    if (zero >= n)
        return;
    Sqswap(&arr[zero],&arr[(zero+n)/2]);
    wall = zero;
    for (int i = zero+1; i <= n; ++i) {
        if(arr[i].square < arr[zero].square)
            Sqswap(&arr[++wall],&arr[i]);
    }
    Sqswap(&arr[zero],&arr[wall]);
    QuickSort(arr,zero,wall);
    QuickSort(arr,wall+1,n);
}
int BiSearch(square arr[],int n, int k){
    int min = 0;
    int max = n - 1;
    int mid;
    while(min <= max){
        mid = (min + max)/2;
        if(k < arr[mid].square)
            max = mid - 1;
        else if(k > arr[mid].square)
            min = mid + 1;
        else
            return mid;
    }
    return -1; //in case if array (arr) doesn't have value of k
}
