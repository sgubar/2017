#include <stdio.h>
#include "Sorting.h"
main() {
    int N;
    printf("Please enter the size of array\n");
    scanf("%i", &N);
    int arr[N];
    GetValue(arr, N);
    for(int i = 0; i < N; ++i)
        printf("%i; ", arr[i]);
    int key;
    switch (key = getchar()){
        case '1':
            BubbleSort(arr, N);
            printf("array is sorted by Bubble");
            break;
        case '2':
            SampleSort(arr,N);
            printf("array is sorted by Sample");
            break;
    }
    for(int i = 0; i < N; ++i)
        printf("%i; ", arr[i]);
    }
    return 0;
}