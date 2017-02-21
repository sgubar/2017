DR1

#include <stdio.h>
                                             
#include <ctype.h>


int main( )
{
 
int a = 2; 
int b = 2;
int c = 2;
int i = 2;
int j = 2;
int k = 0;

int C[i][j];
 int A[a][b];
 int B[b][c];
 	
printf("Give me %i numbers 1 matrix, please:\n", a*b); 
	for(i = 0 ; i<a ; i++)
 {
 	for (j= 0 ; j < b ; j++)
 	{
 		scanf("%i", &A[i][j]);
	}
 }
 for(i = 0 ; i<a ; i++)
 {
 	for (j= 0 ; j < b ; j++)
 	{
 		printf("%i ", A[i][j]);

	}
	printf("\n"); 

}

   printf("Give  me %i numbers 2 matrix, please:\n", a*c); 
	
 for(i = 0 ; i<b ; i++)
 {
 	for (j= 0 ; j <c  ; j++)
 	{
 		scanf("%i", &B[i][j]);
	}
 }

 
 
for(i = 0; i < b; i++)
{
	for(j = 0; j <c; j++ )
	{
	printf("%i ", B[i][j]);
	
	}
printf("\n"); 
}

for(i = 0; i < a; i++ )
for(j = 0; j < a; j++)
{ 
 C[i][j] = 0;
 for(k = 0; k < a ; k++)
 C[i][j] += A[i][k] * B[k][j];
printf("%i ", C[i][j]);
}
       printf("\n");
}

