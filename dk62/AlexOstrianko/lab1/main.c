#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"

int main(void) {
	double A, B, C;	
	printf("(MENSHE 4 CIFER)Enter peremennuu A:");
	vvod(&A);	
	printf("(MENSHE 4 CIFER)Enter peremennuu B:");	
	vvod(&B);	
	do{	
		printf("(MENSHE 4 CIFER)Enter peremennuu C>0:");	
		vvod(&C);	
	}while(C<=0);
	double result = (Abs(((A * C) - B))/stepen(C,3))*sum(A);	
	printf("########################\n");	
	printf("### ");
	printf("Result: %f",result);
	printf(" ###\n");
	printf("########################\n");
	return 0;
}
