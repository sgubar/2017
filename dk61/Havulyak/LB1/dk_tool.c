//  dk_tool.c
//  LB_1
//  Created by Stanislav Havulyak on 24/5/17.

#include "dk_tool.h"
int summ_with_pow(int A)
{
	int num=2;
	int sum=0;
	int mn;
	int i,j;
	for(i=0; i<A; i++)
	{
		mn = 1;
		for(j=0;j<=(A+i);j++)
		{
			
			mn *= num;
		}
		sum += mn;
	}
	printf("\n");
	printf("Sum result:", sum);
	printf("%i", sum);
	printf("\n");
	return sum;
	
}
