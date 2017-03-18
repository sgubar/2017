#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include "dk_tool.h"

int main(void) {
	double A, B, C;	
	printf("(MENSHE 4 CIFER, BOL'SHE NULYA) Enter peremennuu A:");
	vvod(&A);	
	printf("(MENSHE 4 CIFER, BOL'SHE NULYA) Enter peremennuu B:");	
	vvod(&B);
	printf("(MENSHE 4 CIFER, BOL'SHE NULYA) Enter peremennuu C>0:");
	do{	
		vvod(&C);
		if(C<0)
			printf("Chislo doljno bit' bol'she nulya: ");
	}while(C<0);
	double result = (Abs(((A * C) - B))/stepen(C,3))*sum(A);
    putchar ('\n');
	printf("Result: %f",result);
	return 0;
}
