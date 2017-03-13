#include <stdio.h>
#include "dk_tool.h"

int main() {

    float A, B, Q;
    int  correctInp;

    printf("Hello\nEqation is  A!/(|2*A+B|)\nWrite A(only positive) and B.\n");


        scanf("%f%f", &A, &B);

          if (A<0)
          {
              printf("You should write A(only positive int) and B via space in A!/(|2*A+b|) \n");
          }


    if ((2*A+B)==0)
    {
        printf("Denominator can't be zero. Write another integer\n");
    }

    Q = factorial(A)/(modul(2*A+B));

    printf("Your input are \n A=%.1f\n B=%.4f\n\n Answer is %.4f\n ", A, B, Q);

    return 0;

}
