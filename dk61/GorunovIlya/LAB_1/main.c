#include <stdio.h>
#include "dk_tool.h"
int main(void)
{
	
	int firstNumberIn10 = enterNumberIn10();
	int secondNumberIn10= enterNumberIn10();
	int numberIn16 = enterNumberIn16();
	
	int result = theSum(firstNumberIn10, numberIn16,secondNumberIn10);
	printf("The result is %d: ", result);
}
