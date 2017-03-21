#include "dk_tool.h"


void MulMatrix(int matrix1[10][10], int matrix2[10][10], int rozmir){
    int mass3[10][10]={0};
    int x, y, j, n, i, q, m;
x=0;
i=0;
j=0;
n=0;
m=0;
while (x<rozmir){
y=0;
while(y<rozmir) {
m=0;
j=0;
q=0;
mass3[x][y] = 0;
while (q<rozmir){
mass3[x][y]=mass3[x][y]+(matrix1[i][j]*matrix2[m][n]);
m++;
j++;
q++;
}
n++;
y++;
}
i++;
n=0;
x++;
}
printf("Multip of matrix:\n");
x=0;
while (x<rozmir) {
y = 0;
while (y<rozmir) {
printf(" %i ", mass3[x][y]);
y++;
}
printf("\n");
x++;
}
}









