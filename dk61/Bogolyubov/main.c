#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[]){
	int rows = 0;
	int columns = 0;
	rows = rows_write();
	columns = columns_write();
int matrix_1[rows][columns];
matrix1_fill(rows, columns, matrix_1);
matrix1_print(rows, columns, matrix_1);
int matrix_2[rows][columns];
matrix2_fill(rows, columns, matrix_2);
matrix2_print(rows, columns, matrix_2);
summ(rows, columns, matrix_1, matrix_2);
}
