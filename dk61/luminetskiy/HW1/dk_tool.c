#include "dk_tool.h"
#include <stdio.h>
//a - lines
//b - columns

//Asking client to write number of lines and columns of his matrix


int number_of_lines()

{

int a = 0;
do{

	printf("Write number of lines: ");
	scanf("%i", &a);
}

while(a<2);
return a;

}




int number_of_columns()

{
int b = 0;
do

{
	printf("Write number of columns: ");
	scanf("%i", &b);
}

while(b<2);
return b;
}


//Client is writing the numbers if matrix
void write_mat(int a,int b, int mat[a][b])
{

int i=0,j=0;

printf("Write %i %i elements of matrix:\n", a,b); 

while(i<a)
{
	while(j<b)
	 {
		printf("row %i and column %i: ",i+1,j+1);
        scanf("%i", &mat[i][j]); 
		j++; 
    }
    i++; 
    j=0; 
}
}


//Client is writing the number, that he want to multiply on his matrix
void multiplicated_matrix(int a, int b, int mat[a][b],int v)

{ 
printf ("Write number that you want to multiplicate: ");                                          //  printf("Enter coefficient of result matrix: ");
                                                                                                //scanf("%f", &coef);
                                                                                                 //  int i = 0, j = 0;
                                                                                                 //  for(i = 0; i < lines; i++)
                                                                                                 //  for(j = 0; j < columns; j++)
                                                                                                 // matrix[i][j] *= coef;        //matrix[i][j] = matrix[i][j]*coef;

scanf ("%i",&v); 
	
int i = 0;
int j = 0;
for(i = 0 ; i<a ; i++) 
 
for (j= 0 ; j < b ; j++) 
 
mat[i][j] = mat[i][j] * v; 

}



//Matrix on screen
void read_mat(int a, int b, int mat[a][b])
{
int i = 0, j = 0;
for(i = 0; i < a; i++){
for(j = 0; j < b; j++)
printf("%.i ", mat[i][j]);
printf("\n");}
printf("\n");
}







//
//void read_mat(int a,int b, int mat[a][b])
//{

//printf("Write size of matrix:\n"); 
//-scanf("%i %i", &a, &b); 
////-int mat[a][b]; 

///-printf("You chose matrix %i x %i\n", a, b); 
///
//-while(i<a) 
//- 
////-while(j<b) 

/////-scanf("%i", &mat[i][j]); 
//-j++; 
//- 
//-i++; 
//


	


