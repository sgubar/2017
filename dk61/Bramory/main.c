#include <stdio.h>
#include "dk_tool.h"
#include <conio.h>

int main()
{
    float A, B, C, Q;
    printf("Type values: A, B[>0], C: ");
    scanf("%f %f %f", &A, &B, &C);
    while(B < 0)
    {
        printf("Incorrect value for B[>0], try again");
        scanf("%f", &B);
    }

    Q = ((A*A) + (B*B)) / (B + pow(5, C)) + fact(B);
    printf("Q = %f", Q);

    getch();
    return 0;
}
