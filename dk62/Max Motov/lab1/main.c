#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int Avalue = 0;
    int Bvalue = 0;
    int factorial = 0;
    int denominator = 0; //знаменатель
    int ModuledDenominator = 0;
    float result = 0;



    do
    {
        printf("Enter integer positive A\n");
        scanf("%i", &Avalue);
    }
    while(Avalue < 0);

    printf("Enter integer B\n");
    scanf("%i", &Bvalue);

    Factorial(Avalue, &factorial);

    Modul(Avalue, Bvalue, &ModuledDenominator, &denominator);

    Result(factorial, &denominator, &ModuledDenominator, &result);

    getchar();
}
