#include "dk_tool.h"
#include <stdio.h>

void matrix1( int a ,  int b , int  A[a][b]) 
{
int i;
int j;
int c;
	for(i = 0 ; i<a ; i++)
 {
 	for (j= 0 ; j < b ; j++)
 	{
 		scanf("%i", &A[i][j]);
	}
 }

}
 
 void vivod_matrix1(int a, int b, int A[a][b]) 
{
 int i;
 int j;
 for(i = 0 ; i<a ; i++)
 {
 	for (j= 0 ; j < b ; j++)
 	{
 		printf("%i ", A[i][j]);

	}
	printf("\n"); 
}
} 
void matrix2( int b, int c, int B[b][c]) 
 {
 int i;
 int j;


 	for(i = 0 ; i < b ; i++)
 {
 	for (j= 0 ; j < c ; j++)
 	{
     scanf("%i ", & B[i][j]);
}
}
}
void vivod_matrix2( int b, int  c, int B[b][c])
{
int i;
int j;
for(i = 0; i < b; i++)
{
	for(j = 0; j <c; j++ )
	{
	printf("%i ", B[i][j]);
	
	}
printf("\n"); 
}
printf("\n");
}
void result(int j ,int i ,  int a, int b , int c, int  A[a][b],int B[b][c], int  C[i][j])
{
int k;




for(i = 0; i < a; i++ )
for(j = 0; j < b; j++)
{ 
  C[i][j] = 0;
  for(k = 0; k < c ; k++)
 C[i][j] += A[i][k] * B[k][j];
} 

for (i = 0; i < a; i++)
{
    for (j = 0; j < a; j++)
        printf("%3d ", C[i][j]);
    printf("\n");
}
}


