#include <stdio.h>
#include ".idea/Sorting.h"

int main(void) {
    int N;
    printf("Please enter the size of array\n");
    scanf("%i", &N);
    int arr[N];
    GetValue(arr, N);
    for(int i = 0; i < N; ++i) {
        printf("%i; ", arr[i]);
    }
    printf("\n");
    BubbleSort(arr, N);
    printf("\n");
    for(int i = 0; i < N; ++i)
        printf("%i; ", arr[i]);
    return 0;
    }