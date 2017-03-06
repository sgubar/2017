#include <stdio.h>
#include "dk_tool.h"
#include <conio.h>

int main(int argc, char *argv[])
{
	float Q = 0;
	float A = 0;
	float B = 0;
	float C = 0;
	float vuraz = 0;
	int algebrsuma = 0;

	printf("print only int numbers that > than 0 and A shouldn't be >32\n");
	
	
	printf("print number A\n");
	scanf_s("%f", &A);
	printf("print number B\n");
	scanf_s("%f", &B);
	printf("print number C\n");
	scanf_s("%f", &C);

	
	
vuraz = firststage(A,B,C);
algebrsuma = secondstage(A);



//printf(" %.3f\n", vuraz); 
//printf("%d\n", algebrsuma);



Q = vuraz + algebrsuma;
printf("Q=%.3f\n", Q);



	_getch();
	return 0;


}