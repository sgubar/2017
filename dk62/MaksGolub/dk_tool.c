#include <stdio.h>
#include "dk_tool.h"

int func_sub_print(int h, int w, int matr1[h][w], int matr2[h][w])
{
 int result[h][w];
 int i=0, j=0;
 while (i<h)
  {
   while(j<w)
    {
     result[i][j]=matr1[i][j]-matr2[i][j];
     printf("%d ", result[i][j]);
     j++;
    } 
    j=0;
    printf("\n");
    i++;       
  } 
}
 
