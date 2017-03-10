// main.c
// LB1
// created by I.Protsenko 03/10/17

#include <stdio.h>

int main(void) {
	
	int a, b, c; int d = 0;
	float Q;
 
	printf("Enter A(>0), B , C(!=0):"); //enter nubmers
	scanf("%i""%i""%i", &a, &b, &c);
	
	if (a > 0 && c != 0){ //cheking for invalid values
    	printf("[A : %i] [B : %i] [C : %i] [D : %i] \n", a, b, c, d);
		Q = (module(a, b, c)/pow(c, 3))*(sum(a, d)); //announce functions and compute result
		printf("Q -> (|A*C-B|/C^3)*Sum(D->A (2^D))\n"); 
		printf("Q -> %.3f", Q);
	}
	else
	{
		printf("Error. Incorrect numbers. Try again");
	}	
	
}
