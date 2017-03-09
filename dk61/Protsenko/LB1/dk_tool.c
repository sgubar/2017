#include "dk_tool.h"

int module(int a, int b, int c) //module function
{
	printf("|A*C-B|: ");  
	int module_result;
	module_result = fabs(((a*c)-b)); 
	printf("%i \n", module_result);
	return module_result;	
}


int power(int d) //power function
{
	int power_result;  
	power_result = pow(2, d);
	return power_result;		
}

int sum(int a, int d) //summ function
{
	int power_a = power(d);
		for(int i = 0; i < a; i++)
		{
			power_a++;
		}
	printf("Sum D->A (2^D) : %i \n", power_a);
	return power_a;
}

