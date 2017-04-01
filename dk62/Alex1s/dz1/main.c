#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[]) {

int lines = 0, columns = 0;
float coef = 0;
printf("Enter amount of lines: ");
lines = enter_value();
printf("Enter amount of columns: ");
columns = enter_value();
float matrix[lines][columns];
write_matrix(lines, columns, matrix);
printf("\nYou wrote:\n");
read_matrix(lines, columns, matrix);
mnoj_matrix(coef, lines, columns, matrix);
printf("\nResult matrix:\n");
read_matrix(lines, columns, matrix);

system("pause");
return 0;
}

