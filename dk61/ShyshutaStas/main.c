#include <stdio.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) 

{
	int result = 0;
	int F = 0, D = 0, C = 0;

	printf("\nenter First nomber:");
		scanf("%d", &D) ;
	printf(" \nSecond nomber:");
		scanf ("%d",&C);
	printf("\nenter nomber on hex sistem :");
		scanf("%x", &F) ;
	
	
    result = sum_series(D , C , F);
    printf("\nresult: %d",result);
	return 0;
}
