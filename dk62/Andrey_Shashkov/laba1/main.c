#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) 

{
	int b = 0;
	int k = 0;
	int D = 0;
	int C = 0;
	printf ( "Plese, enter First nomber: \n");
    scanf("%d", &D) ;
	printf ( "Plese, enter Second nomber: \n");
    scanf("%d", &C) ;
    printf ( "Plese, enter nomber on  16 poinet: \n");
    scanf("%x", &b) ;
    
  k = AQUATION(D, C ,b);
  printf("Result: %d",k);
	return 0;
}
