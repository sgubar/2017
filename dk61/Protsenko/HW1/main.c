#include "dk_tool.h"


int main(void)
 {
  
  printf("Hello :). This programm won't work if you enter a symbols or negative X or Y\n");
  printf("\nEnter X: ");	
  int x, y = 0;
  x = GetValueWithCheck();
  printf("Enter Y: ");
  y = GetValueWithCheck();
  printf("X (Columns) - %i ; Y (Rows) - %i\n", x, y);
  int arr[x][y]; int arr2[x][y];
  CreateMatrix(x, y, arr);
  PrintMatrix(x, y, arr);
  printf("\n");
  CreateMatrix(x, y, arr2);
  PrintMatrix(x, y, arr2);
  printf("\n");
  SubstractMatrix(x,y, arr, arr2);
 } 
