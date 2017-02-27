#include <stdio.h>
 #include <conio.h>                                            
#include <ctype.h>


int main( )
{
 
int a = 2; 
int b = 2;
int c = 2;
int i = 2;
int j = 2;
int k = 0;
int  C[i][j] = 0;
int C[i][j];
 int A[a][b];
 int B[b][c];
 	
printf("Give me %i numbers 1 matrix, please:\n", a*b); 
matrix1( a, b, A);
vivod_matrix1(a ,b ,A);

   printf("Give  me %i numbers 2 matrix, please:\n", a*c); 
 matrix2( b, c, B); 	
vivod_matrix2(b , c , B);
result(C , B, A);
vivod_result(C , B, A);



 
 
