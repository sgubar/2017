
#ifndef dk_tool_h
#define dk_tool_h


int fact(int number)
{
    int theResult =1;
    while( number > 0 )
    {
    theResult *= theResult * number;
    number--;
    
	}
return theResult;




int pow(int number , int power )
int theResult = 1;
while(number > 1)
{
theResult *= theResult  * power;
power --;
}
return theResult

}
#endif
