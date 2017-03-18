#include <stdio.h>
#include "dk_tools.h"

void FillMatrix(int x, int matr[10][10]){

    int e = 0;
    int i,j;
    printf("Fill the array\n");
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
        e++;
        printf("Enter the %i element of the array: \n", e);
        scanf("%d", &matr[i][j]);
        }
    }
}

void result(int x, int matr1[10][10],int matr2[10][10],int result_matr[10][10]){
    
     int i,j,k;

    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
        	result_matr[i][j] = 0;
                for(k = 0; k < x; k++){
                    result_matr[i][j] += matr1[i][k] * matr2[k][j];
                }
        }
    }
  
}

void print_result(int x, int result_matr[10][10]){
int i,j;
printf("Array multiplication result:\n");
for(i = 0; i < x; i++){
for(j = 0; j < x; j++){
printf("%i ", result_matr[i][j]);
}
printf("\n");
}

}


