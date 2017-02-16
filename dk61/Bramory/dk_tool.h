#ifndef dk_tool_h
#define dk_tool_h

int fact(int number)
{
    if (number < 0) return -1;
    int theResult = 1;
    while (number != 1)
    {
        theResult *= number;
        number--;
    }
    return theResult;
}

/*
int transp(char matr[][] );
{
	int theResult = 0;

	return	theResult;
}
*/

int pow (int number, int power)
{
    int theResult = 1;
    while (power > 0)
    {
        theResult = theResult * number;
        power--;
    }
    return	theResult;
}
#endif
