void Faktorial(int value_A , int *faktorial)

{
    *faktorial = 1;

    for(int i = 2; i <= value_A; i++)
    {
        *faktorial *=  i;
    }
    printf("Faktorial = %i\n", *faktorial);
}

void Modul(int value_A , int value_B , int *denominator)


{
    printf("Enter B:\n");
    scanf("%i" , &value_B);

    *denominator = (2 * value_A) + value_B;

    if (*denominator == 0)
    {
        printf("Denominator can`t be 0!\nPlease enter another values\n");
    }

    if (*denominator < 0)
    {
        *denominator = *denominator * (-1);
    }

    else
    {
        printf("Denominator:  %d\n" , *denominator);
    }

}

void Result(int factorial , int denominator , float *result)

{
    float temp2, temp3;
    temp2 = factorial;
    temp3 = denominator;
    *result = temp2 / temp3;
    printf("Q = %f\n" , *result);
}
