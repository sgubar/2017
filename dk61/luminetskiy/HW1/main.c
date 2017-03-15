#include <stdio.h> 
#include "dk_tool.h"
#include <stdlib.h>
int main() 
{ 
int a=0; 
int b=0; 


int v=0; 
a=number_of_lines();
b=number_of_columns();
int mat[a][b];
write_mat(a, b, mat);
printf(" Your matrix:\n");
read_mat(a, b, mat);                                                         
multiplicated_matrix( a,  b, mat,v);                                                             
printf("Result of your matrix:\n");    
read_mat(a, b, mat);                                                        
system("pause");
return 0;                                                                    
}                                                               







