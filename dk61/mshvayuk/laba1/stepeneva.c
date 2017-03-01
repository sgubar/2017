#include "stepeneva.h"

float stepeneva(float c)
	{
		int i;//counter for loop
		
		float dobutok = 1;// змінна яка стане результатом обчислень
		
		if (c>0)
		{
		
			for (i = 1; i<=c; i++)
			{
			dobutok = dobutok*5;
			}
		
		}
	
		else 
	
		if(c<0)// якщо степінь від"ємний
		{
			for (i = c; i<0; i++)
			{
			dobutok = dobutok*5;
			}	
		
			dobutok = 1/dobutok;//ось відмінність з попереднім циклом
		}
		else
		
		if(c == 0)//якщо С = 0
		{
			dobutok = 1;
		}
		 return dobutok;
	}
