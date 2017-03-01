#include <stdio.h>
#include <stdlib.h>

#include "stepeneva.h"
#include "factorial.h"


//	Q?(A^2+B^2)/(B+5^C )+B!
//Øâàþê ìàêñèì äê 61

//float stepeneva(float c);
//float faktorial(float b);

float main(void)
{
	int i, j, z;
		
	printf("your priklad is: \n (A^2 + B^2)/ (B + 5^C) \n");
			
			//ç÷èüóºìî çì³íí³
			
	printf("give me the A float pls \n");
		float a;

	scanf("%f",&a);
	
	printf("give me the B float >= 0 pls \n");
	float b;
	
		do
		{
		scanf("%f",&b);
		}
		while (b < 0);
	
	printf("give me the C float pls\n");
		float c;

	scanf("%f",&c);
	
	printf(" a= %f    b = %f	c = %f\n", a,b,c);
	float chiselnik = (a*a + b*b);
	printf("chiselnik = %f \n", chiselnik);
	
	float lol = stepeneva (c);
		printf("stepeneva = %f \n", lol);

	float znamennik = (b + lol);
		printf("znamennik = %f\n", znamennik);

	float first_dodanok = chiselnik / znamennik;
		printf("first_dodanok = %f\n", first_dodanok);

	float second_dodanok = faktorial(b);
		printf("second_dodanok = %f\n", second_dodanok);

	float final = first_dodanok+second_dodanok;
	
	printf("the result = %f", final);
	
		
}

/*float faktorial( float b)
	{
		int j;
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
	*/


	
	
	
	
	
	
	
	
