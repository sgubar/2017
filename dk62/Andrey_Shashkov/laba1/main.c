#include <stdio.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) 

{
	int F = 0;
	int result = 0;
	int D = 0;
	int C = 0;
	printf("enter First nomber,enter Second nomber and enter nomber on hex sistem \n");
	scanf("%d %d %x", &D,&C,&F) ;
    result = AQUATION(D , C , F);
    printf("Result: %d",result);
	return 0;
}
