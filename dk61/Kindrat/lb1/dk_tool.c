#include "test.h"

int module(int a, int b, int c, int module_result) 
{
	module_result = ((a*c)-b);
	if(module_result < 0)
	{
		module_result = module_result *-1;
	} 
	return module_result;	
}

int step_c(int c)
	{
    	int box_c = c*c*c;
    	return box_c;
	}

int sum(int a, int d, int box) 
{
	for (d = 0; d <=a; d++)
	{
		int i = 1;
		int result = 1;
		while(i<=d)
		{
			result=2*result;
			i++;
		}
		box+=result;
	} return box;
}   
