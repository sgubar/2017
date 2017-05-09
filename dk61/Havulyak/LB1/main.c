//  main.c
//  LB_1
//  Created by Stanislav Havulyak on 24/5/17.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int A;
	double B, C;
	printf("Enter the A, B, C:\n");
	scanf("%i""%lf""%lf",&A, &B, &C);
	double finale = ((A+B+C)/(100-B-C))+(summ_with_pow(A));
	printf("Result:");
	printf("%lf", finale);
	return 0;
	
}
