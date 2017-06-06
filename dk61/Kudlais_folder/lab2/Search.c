#include "Search.h"
#include ".idea/Sorting.h"
int Lsearch(int arr[],int size, int k){ //search position of number k in the array with size n
    for (int i = 0; i < size; ++i)
        if(arr[i] == k)
            return i;
    return  -1; //in case if array (arr) doesn't have value of k
}
void Shellsort(int mas[], int n){ //sort array mas with size n by the method of Shell
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; ++i) {
            for (int j = i-gap; j >= 0 && mas[j] > mas[j+gap]; j -=gap)
                swap(&mas[j],&mas[j+gap]);
        }
    }
}
void QuickSort(int arr[],int zero, int n){
    int wall;
    if (zero >= n)
        return;
    swap(&arr[zero],&arr[(zero+n)/2]);
    wall = zero;
    for (int i = zero+1; i <= n; ++i) {
        if(arr[i] < arr[zero])
            Sqswap(&arr[++wall],&arr[i]);
    }
    Sqswap(&arr[zero],&arr[wall]);
    QuickSort(arr,zero,wall);
    QuickSort(arr,wall+1,n);
}
int BiSearch(int arr[],int size, int k){
    int min = 0;
    int max = size - 1;
    int mid;
    while(min <= max){
        mid = (min + max)/2;
        if(k < arr[mid])
            max = mid - 1;
        else if(k > arr[mid])
            min = mid + 1;
        else
            return mid;
    }
    return -1; //in case if array (arr) doesn't have value of k
}