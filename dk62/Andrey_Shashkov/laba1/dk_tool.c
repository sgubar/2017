#include "dk_tool.h"
int AQUATION(int D,int C,int b)
{   
    int result = 0;
    int A = 1;
    while(A <= D)
	{
	result = A * (b - C) + result;
	A++;
    } 
    return result; 
}
