#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
float pow2(int number  )
{

float theResult = 1;
/*while(power > 1)
{
theResult = theResult  * power;
power --;
}
*/return number*number;

}
float fact(int number)
{
float theResult = 1;
while( number > 0 )
{
theResult *= number;
number--;
}
return theResult;
}
