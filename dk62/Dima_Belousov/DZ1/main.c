#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "dk_tools.h"

int main(int argc, char *argv[])
{
int N;
int matr1[10][10];
int matr2[10][10];
int result_matr[10][10];

printf("Enter array size: \n");
scanf("%i", &N);




FillMatrix(N,matr1);
FillMatrix(N,matr2);
result(N,matr1,matr2,result_matr);
print_result(N,result_matr);


return 0;
}

