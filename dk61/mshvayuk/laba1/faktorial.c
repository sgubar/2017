#include "faktorial.h"

float faktorial( float b)
	{
		float j;// counter for loop
		
		float result = 1;// змінна яка стане результатом обчислень
		
		if(b > 0)
		{
		
			for( j = 1; j<=b; j++)
			{
				result = result*j;			
			}
		
		}
		
		else
		
		if( b == 0)
		{
			result = 1;	
		}
		return result;
	}
