#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h" 


int main () 
{
	int C, D, B, R, f;
	char F[1000];
	

		printf("Please enter the number  D:");
		scanf("%d", &D);
		printf("Please enter the number  C:");
		scanf("%d", &C);
		printf("Please enter the number  F in hex format:");
		scanf("%x", &f);
		printf("Q = sum from A=1 to D (A*(F16 - C))= %d ",MakeQm( f, D, C ));

	return 0;
}
