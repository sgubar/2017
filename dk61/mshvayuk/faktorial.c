#include "faktorial.h"

float faktorial( float b)
	{
		float j;
		float result = 1;
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
