void Factorial(int Avalue, int *factorial)
{
    *factorial = 1;

    for(int i = 2; i <= Avalue; i++)
    {
        *factorial *= i;
    }
    printf("factorial = %i\n", *factorial);

}



void Modul(int Avalue, int Bvalue, int *ModuledDenominator, int *denominator)
{

    *denominator = 2 * Avalue + Bvalue;

    if(*denominator == 0)
    {
        printf("denominator can't be 0\n");
    }
    else
    {
        printf("denominator = %i\n", *denominator);
    }


    if(*denominator < 0)
    {
        *ModuledDenominator = *denominator * (-1);
    }
    else if(*denominator > 0)
    {
        *ModuledDenominator = *denominator;
    }

    if(*denominator == 0)
    {
        printf("restart program and enter another values\n");
    }
    else
    {
        printf("Modul denominator = %i\n", *ModuledDenominator);

    }


}


void Result(int factorial, int *denominator, int *ModuledDenominator, float *result)
{

    if(*denominator != 0)
    {
        *result = (float)factorial / *ModuledDenominator;
        printf("your result is %.3f\n", *result);
    }
    else
        printf("denominator = 0, error");


}

