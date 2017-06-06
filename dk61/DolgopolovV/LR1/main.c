#include "LR.h"

int main(void)
{
    int A = 0;
    int B = 0;
    
    int Znamenatel = 0; 
    int factorial = 0;
    int ModuledZnamenatel = 0;
    float result = 0;



    do
    {
        printf("positive number A\n");
        scanf("%i", &A);
    }
    while(0 >= A);

    printf("number B\n");
    scanf("%i", &B);

    Factorial(A, &factorial);

    Modul(A, B, &ModuledZnamenatel, &Znamenatel);

    Result(factorial, &Znamenatel, &ModuledZnamenatel, &result);
}
