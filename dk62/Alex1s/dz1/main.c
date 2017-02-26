#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[]) {

int lines = 0, columns = 0;
float coef = 0;
lines = enter_lines();
columns = enter_columns();
float matrix[lines][columns];
write_matrix(lines, columns, matrix);
mnoj_matrix(coef, lines, columns, matrix);
read_matrix(lines, columns, matrix);

system("pause");
return 0;
}

