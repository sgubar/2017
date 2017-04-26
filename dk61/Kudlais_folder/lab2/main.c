#include <stdio.h>
#include <stdlib.h>
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
    printf("\nPress 1 for Bubble sort, 2 for Sample sort, 3 for inclusion sort");
    int key;
    while((key = getchar()) != EOF){
        switch(key){
            case 1:{
                BubbleSort(arr,N);
                break;
            }
            case 2:{
                SampleSort(arr,N);
                break;
            }
            case 3:{
                InclusionSort(arr,N);
                break;
            }
            default:
                continue;
        }
    }
    printf("\n");
    for(int i = 0; i < N; ++i)
        printf("%i; ", arr[i]);
    return 0;
    }