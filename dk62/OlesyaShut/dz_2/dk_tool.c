#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

#define M_PI 3.14159265358979323846


koordunatu* xy_koordunatu()



void enter(koordunatu *AA)
{
	if(NULL != AA)
	{
		printf("Enter x koordinate: ");
		scanf("%f",&AA->x_koordunatu);
		
		printf("\nEnter y koordinate: ");
		scanf("%f",&AA->y_koordunatu);
		
		AA->radius = proverka();
	}
}


float proverka()
{
	float rez;
	do{
		printf("\nEnter radius : ");
		scanf("%f", &rez);
	}while(rez <= 0);

	return rez;
}


float calculate(koordunatu *AAA)
{
	float rezultat = M_PI * AAA->radius * AAA->radius;

	if(rezultat<0) 
		rezultat *= (-1);

	return rezultat; 
}
