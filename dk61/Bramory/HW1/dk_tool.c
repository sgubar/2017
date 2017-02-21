#include "dk_tool.h"
#include <stdio.h>
 
int fact(int number)
{
    if (number < 0) return -1;
    int theResult = 1;
    while (number > 1)
    {
        theResult *= number;
        number--;
    }
    return theResult;
}


int power (int number, int power)
{
    int theResult = 1;
    while (power > 0)
    {
        theResult = theResult * number;
        power--;
    }
    return	theResult;
}

int num_scan( void )
{
	int num = 0, proof = 0;
    do
    {
        proof = scanf("%d", &num);
        fflush(stdin);
      if(proof != 1)  printf("Incorrect input, try again");
    }
    while (proof != 1);
return num;
}
