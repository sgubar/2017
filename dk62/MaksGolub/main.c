#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
int h=0, w=0;
printf("Enter size of matrix\n");
 scanf("%d", &h);
 scanf("%d", &w);
 int matr1[h][w], matr2[h][w];
 int i=0, j=0;
 printf("Enter first matrix\n");
 while(i<h)
 {
  while(j<w)
  {
   printf("[%d][%d]:", i,j);
   scanf("%d", &matr1[i][j]);
   j++;
  }
  j=0;
  i++;
 }
i=0, j=0;
 printf("Enter second matrix\n");
 while(i<h)
 {
  while(j<w)
  {
   printf("[%d][%d]:", i,j);
   scanf("%d", &matr2[i][j]);
   j++;
  }
  j=0;
  i++;
 }
 func_sub_print(h, w, matr1, matr2);
}
