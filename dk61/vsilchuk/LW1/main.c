#include "dk_tool.h"
#include <stdio.h>

int main()
{
	int A = 11, B, C;
	
	while(A>10)
		{
			printf("Enter A number, less than 10:\n");
			A = NumInput();
		}
	
	printf("Enter your B number:\n");
	B = NumInput();
		
	printf("Enter your C number, condition: (100-B-C) should not be 0:\n");
	C = NumInput();
	while(100-B-C == 0)
		{
			printf("Enter another C number:\n");
			C = NumInput();
		}
		
	printf("A: %d\t B: %d\t C: %d\n", A, B, C);
	
//	printf("Your summ is: %d\n", Sum(A));	
//	printf("Drib: %.3f\n", (float) (A+B+C)/(100-B-C));
	
	float theResult = (float) (A+B+C)/(100-B-C)+Sum(A); 	// приведение типа int к типу float, чтобы избежать усечения результата при целочисельном делении
	printf("Your lab result is: %.2f", theResult);
	
	return 0;
}

