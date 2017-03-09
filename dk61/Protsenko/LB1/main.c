#include <stdio.h>


int main(void) {
	int a, b, c; int d = 0;
	float Q;
	
	printf("Enter A (A > 0): "); //enter a
	scanf("%i", &a);
		if (a < 0)
		{
		printf("Error. A must be > 0 \n"); //cheking for error
		return 0;
		}
	
	printf("Enter B: "); //enter b
	scanf("%i", &b);

	printf("Enter C (C != 0): "); //enter c
	scanf("%i", &c); 
		if (c == 0)
    	{
   		printf("Error. C should != 0 \n"); //cheking 4 error
    	return 0;
    	}
    
    printf("Q -> (|A*C-B|/C^3)*Sum(D->A (2^D))\n"); 
	Q = (module(a,b,c)/pow(c,3))*sum(a,d); //announce functions and compute result
	printf("Q -> %.2f", Q);
	
}
