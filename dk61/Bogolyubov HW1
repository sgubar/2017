//created by Igor Bogolyubov (DK-61)
//the sum of two matrices (var.№3)
#include <stdio.h>

int main(){
int x = 0;
int y = 0;
printf("Hello!\n");
printf("Enter here the number of rows: ");
scanf("%i",&x);
printf("Enter here the number of columns: ");
scanf("%i",&y);
int matrix_1[x][y];
int matrix_2[x][y];
int row=0;
int col=0;
int all_count = x*y;
printf("Please enter %i numbers for first matrix here: \n", all_count);
for (row=0; row<x; row++){
for (col=0; col<y; col++){
scanf("%d", &matrix_1[row][col]);
}
}
printf("Please enter %i numbers for second matrix here: \n", all_count);
for (row=0; row<x; row++){
for (col=0; col<y; col++){
scanf("%d", &matrix_2[row][col]);
}
}
printf("Your first matrix is\n");
for (row=0; row<x; row++) {
for (col=0; col<y; col++) {
printf("[%d]",matrix_1[row][col]);
}
printf ("\n");
}
printf("Your second matrix is\n");
int sum[row][col];
for (row=0; row<x; row++) {
for (col=0; col<y; col++) {
printf("[%d]",matrix_2[row][col]);
}
printf ("\n");
}
{
}
printf("The result of the sum\n");
for (row=0; row<x; row++) {
for (col=0; col<y; col++) {
sum[row][col] = matrix_1[row][col] + matrix_2[row][col];
printf("[%d]", sum[row][col]);
}
printf ("\n");
}
}
