//  main.c
//  dz1 
//  Created by Illia Protsenko on 3/1/17.

#include <stdio.h>
#include "dk_tool.h"
#include "dk_tool.h"

int main(void){
	int x, y;
	printf("Enter number of rows: ");
	scanf("%i", &x);
	printf("Enter number of columns: ");
	scanf("%i", &y);
	int arr[x][y], arr2[x][y], diff[x][y];
	filling_matrix(x, y, arr, arr2);
	display_matrix(x, y, arr, arr2);
	matrix_diff(x, y, arr, arr2, diff);
}
