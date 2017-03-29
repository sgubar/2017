#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
float pow2(int number  )
{

int theResult = 1;
/*while(power > 1)
{
theResult = theResult  * power;
power --;
}
*/return number*number;

}
int fact(int number)
{
int theResult = 1;
while( number > 0 )
{
theResult *= number;
number--;
}
return theResult;
}
