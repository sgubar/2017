#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "figure.h"
#include "SS.h"
int main() {
    int n;
    printf("Quantity of figures\n");
    scanf("%i",&n);
    square *ptr = (square*) malloc(sizeof(square)*n);
    for (int k = 0; k < n; ++k) {
        printf("Square number %i",k+1);
        MakeSquare(&ptr[k]);
    }
    for (int i = 0; i < n; ++i) {
        ptr[i].square = Squareof(ptr[i]);
    }
    printf("Press 1 for Quick sort\n\nPress 2 for Shall sort\n\nPress 3 for Bubble sort\n\nPress 4 for Inclusion sort\n\nPress 5 for Sample sort\n\nPress 6 to find the value by Linear search\n\nPress 7 to print the figure on the screen\n");
    int c;
    goto novalue;
    novalue://spagnetti
    c = getchar();
    switch(c){
        case '1': {
            QuickSort(ptr, 0, n);
            printf("Sorted by Quick sort.\n");
            break;
        }
        case '2':{
            Shellsort(ptr,n);
            printf("Sorted by Shall\n");
            break;
        }
        case '3':{
            BubbleSort(ptr,n);
            printf("Sorted by Bubble sort\n");
            break;
        }
        case '4':{
            InclusionSort(ptr,n);
            printf("Sorted by Inclusion\n");
            break;
        }
        case '5':{
            SampleSort(ptr,n);
            printf("Sorted by Sample sort\n");
        }
        case '6':{
            int found = -1;
            int x;
            while (found == -1) {
                printf("Which value you want to find?\n");
                scanf("%i", &x);
                found = Lsearch(ptr, n, x);
                if (found == -1) {
                    printf("Value doesn't exist in this list, try again\n");
                }
                printf("Number %i is in position %i\n",x,found+1);
            }
        }
        case '7':
            PrintFigures(ptr,n);
        default:
            goto novalue; //I love spagnetti

    }
    printf("Now you have some new possibilities\n\nPress 1 to find some value by Binary search\n\nPress 2 to  print the figures on the screen\n\nPress 3 to print into the file int txt format\n\nOr press any other bottom to clear the memory and exit now!\n");
    scanf("%i",&c);
    if(c == 1) {
        if(!isSorted(ptr,n)){
            printf("You can not use binary search! You have to sort your array first!\n");
            goto novalue; //spagnetti
        }
        int fnd = -1;
        int xi;
        while (fnd == -1) {
            printf("Which value you want to find?\n");
            scanf("%i", &xi);
            fnd = BiSearch(ptr, n, xi);
            if (fnd == -1) {
                printf("Value doesn't exist in this list, try again\n");
            }
            printf("Number %i is in position %i\n", xi, fnd + 1);
        }
    }
    else if(c == 2)
        PrintFigures(ptr,n);
    else if(c == 3){
        char filename[100];
        printf("Please give the name of file(without the type of file)\n");
        scanf("%s",filename);
        int str = strlen((filename));
        filename[str+1] = 't';
        filename[str+2] = 'x';
        filename[str+3] = 't';
        filename[str+4] = '\0';
        bool access = false;
        while (!access){
            access = JSON(ptr,n,filename);
            if(!access)
                printf("File %s does not exist\n",filename);
            else
                ("Figures printed into the file\n");
        }
    }

    printf("Let's clean it!");
    free(ptr);
    return 0;
}