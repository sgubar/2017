#include "stepeneva.h"

float stepeneva(float c)
	{
		int i;
		float dobutok = 1;
		if (c>0)
		{
		
			for (i = 1; i<=c; i++)
			{
			dobutok = dobutok*5;
			}
		
		}
		else 
	
		if(c<0)
		{
			for (i = c; i<0; i++)
			{
			dobutok = dobutok*5;
			}	
			dobutok = 1/dobutok;
		}
		else
		
		if(c == 0)
		{
			dobutok = 1;
		}
		 return dobutok;
	}
