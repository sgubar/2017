// dk_tool.c
// LB1
// created by I.Protsenko 03/10/17

#include "dk_tool.h"

int module(int a, int b, int c) //module function
{
	printf("Now we computing |A*C-B| \n");
	printf("|A*C-B|: ");  
	int module_result;
	module_result = fabs(((a*c)-b)); 
	printf("%i \n", module_result);
	return module_result;	
}


int power(int d) //power function
{
	int power_result = 0;
	power_result = pow(2, d);
	return power_result;
}

int sum(int a, int d) //sum function
{
	printf("Now we computing (Sum D -> A (2^D)) \n");
	int sum = 0;
	for (d = 0; d <= a; d++){
	    sum += power(d);
	}
	printf("Sum result : %i\n", sum);
	return sum;
}

