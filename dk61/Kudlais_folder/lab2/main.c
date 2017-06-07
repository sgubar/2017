#include <stdio.h>
#include <stdlib.h>
#include ".idea/Sorting.h"
#include "Search.h"

int main(void){
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
    while((key = getchar())){
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
            case 4:{
                Shellsort(arr,N);
                break;
            }
            case 5:{
                QuickSort(arr,0,N);
                break;
            }
            case 6:{
                int find;
                printf("Which number do you want to find.\n");
                find = Lsearch(arr,N,find);
                char* additional = (find == -1) ? " (did not find)": (find == 0) ? "st": (find == 1) ? "nd": (find == 2) ? "rd" : "th";
                printf("Your value is in the %i%s place.\n",find,additional);
                break;

            }
            default:
                break;
        }
    }
    printf("\n");
    for(int i = 0; i < N; ++i) {
        printf("%i; ", arr[i]);
    }
    if (!check(arr,N))
        return 0;
    printf("Now you may use binary search.\n");
    int search;
    printf("Which number do you want to find");
    scanf("%s",search);
    search = BiSearch(arr,N,search);
    char* add_al = (search == -1) ? " (did not find)": (search == 0) ? "st": (search == 1) ? "nd": (search == 2) ? "rd" : "th";
    printf("Your value is in the %i%s place.\n",search,add_al);
    FIlE* file = fopen("New.txt","a+");
    if(file != NULL){
        for (int i = 0; i < N; ++i) {
            fprintf(file," %i ",arr[i]);
            fflush(file);
        }
    }
    return 0;
}