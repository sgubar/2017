#ifndef dk_tool_h
#define dk_tool_h

int rows_write();
int columns_write();
int matrix1_fill(int rows, int columns, int matrix_1[rows][columns]);
int matrix1_print(int rows, int columns, int matrix_1[rows][columns]);
int matrix2_fill(int rows, int columns, int matrix_2[rows][columns]);
int matrix2_print(int rows, int columns, int matrix_2[rows][columns]);
void summ(int rows, int columns, int matrix_1[rows][columns], int matrix_2[rows][columns]);
#endif 
