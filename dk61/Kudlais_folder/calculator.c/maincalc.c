#include <stdio.h>
#include "dk_tool_hz.h"

int main() {
	int A = 0;
	int B = 50;
	int C = 50;
	//значення зміним надаються такі, щоб ввійти в цикли
	while(A <= 0){
		printf("Please take the meaning of number A:");
	    scanf("%i", &A);
	}
	while((B + C) == 100){
		printf("Remember that B + C must not be equaled 100\n");
		printf("Please take the meaning of number B:");
		scanf("%i", &B);
		printf("Please take the meaning of number C:");
		scanf("%i", &C);
	}
	//цикли необхідні, щоб користувач не зміг залишити неправильні значення
	float answer = sum(A) + (A + B + C)/(100 - B - C);
	printf("The answer is %.3f", answer);
	return 0;
}