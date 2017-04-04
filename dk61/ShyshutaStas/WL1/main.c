#include <stdio.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) 

{   
	//declare variables
	int result = 0;
	int F = 0, D = 0, C = 0;
	//enter values
	printf("\n enter First nomber:");
		scanf("%d", &D) ;
	printf(" \n Second nomber:");
		scanf ("%d",&C);
	printf("\n enter nomber on hex sistem :");
		scanf("%x", &F) ;
	
	//call feature
    result = sum_series(D , C , F);
	//output value
    printf("\nresult: %d",result);
	return 0;
}
