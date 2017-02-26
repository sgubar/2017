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

	int rez = 1;
	int m = 2;
	int pow = 0;
	int algebrsuma = 0;
	int i = 0; int D = 0;
	
	printf("vvedite chislo A\n");
	scanf_s("%f", &A);
	printf("vvedite chislo B\n");
	scanf_s("%f", &B);
	printf("vvedite chislo C\n");
	scanf_s("%f", &C);

	
	
vuraz = firststage(A,B,C);
algebrsuma = secondstage(A,D);
pow = thirdstage(A, rez, m);


//printf(" %.3f\n", vuraz); 
//printf("%d\n", algebrsuma);
//printf("%d\n", pow);


Q = vuraz + (algebrsuma*pow);

printf("Q=%.3f\n", Q);



	_getch();
	return 0;


}