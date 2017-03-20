#include <stdio.h>
#include <stdlib.h>

int main()
{
    int denominator = 0; //знаменатель
    int value_A = 0;
    int value_B = 0;
    int faktorial = 1;
    float result = 0;

    do
    {
        printf("Enter A > 0:\n");
        scanf("%i" , &value_A);
        if( value_A <= 0)
        {
            printf("Wrong value A!\nPlease enter A again:\n");
        }
    }
    while (value_A <= 0);

    Faktorial(value_A , &faktorial); //функція знаходження факторіалу числа

    Modul(value_A , value_B , &denominator); //функція знаходження модулю числа

    Result(faktorial , denominator , &result);

    getchar();
    return 0;

}
