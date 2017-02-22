#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(void) {
	double A, B, C;
	printf("Enter peremennuu A:");
	scanf("%lf",&A);
	printf("Enter peremennuu B:");
	scanf("%lf",&B);
	do{	
		printf("Enter peremennuu C>0:");	
		scanf("%lf",&C);
	}while(C<=0);
	double result = (Abs(((A * C) - B))/stepen(C,3))*sum(A);	
	printf("########################\n");	
	printf("### ");
	printf("Result: %f",result);
	printf(" ###\n");
	printf("########################\n");
	return 0;
}
