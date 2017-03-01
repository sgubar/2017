//	Завдання: (A^2+B^2)/(B+5^C )+B!
//Шваюк максим дк 61

#include <stdio.h>
#include <stdlib.h>

#include "stepeneva.h"
#include "faktorial.h"

float main(void)
{		
	printf("your priklad is: \n (A^2 + B^2)/ (B + 5^C) \n");
			
			//зчиьуємо змінні
			
	printf("give me the A float pls \n");
		float a;

	scanf("%f",&a);
	
	printf("give me the B float >= 0 pls \n");
	float b;
	
		do
		{
		scanf("%f",&b);//цикл, який не дає ввести В<0
		}
		while (b < 0);
	
	printf("give me the C float pls\n");
		float c;

	scanf("%f",&c);
	
	printf(" a= %f    b = %f	c = %f\n", a,b,c);
	
	float chiselnik = (a*a + b*b);// A^2 + B^2
	printf("chiselnik = %f \n", chiselnik);
	
	float stepin = stepeneva (c);// 5^C
		printf("stepeneva = %f \n", stepin);

	float znamennik = (b + stepin);// B + 5^C
		printf("znamennik = %f\n", znamennik);

	float first_dodanok = chiselnik / znamennik;// (A^2+B^2)/(B+5^C )
		printf("first_dodanok = %f\n", first_dodanok);

	float second_dodanok = faktorial(b);// B!
		printf("second_dodanok = %f\n", second_dodanok);

	float final = first_dodanok+second_dodanok;
	
	printf("the result = %f", final);
	
		
}
