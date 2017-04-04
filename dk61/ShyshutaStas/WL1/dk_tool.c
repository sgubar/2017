#include "dk_tool.h"
int sum_series(int D,int C,int F)
{   
    int result = 0;
    int A = 1;
    while(A <= D)
	{
	result = A * (F - C) + result;
	A++;
    } 
    return result; 
}
