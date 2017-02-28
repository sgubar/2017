//  dk_tool.c
//  laba1 variant 2
//  Created by Illia Protsenko 2/28/17.

#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include "dk_tool.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int A, B, C; int D = 0; float answer;
	printf("Enter A, B, C: ");
	scanf("%i""%i""%i", &A, &B, &C);
	answer = (module(A,B,C))*(sum(A))/(pow(C, 3));
	printf("Answer: %.3f\n", answer);
	system("pause");
}
