#include <stdio.h>
#include "dk_tool.h"

int main() {

    float A, B, Q;
    int  repairInput;

    printf("Write A(only positive int!) and B via space in A!/(|2*A+B|) \n");

    begin:
    do
      {
          repairInput= scanf("%f%f", &A, &B);

          rewind(stdin); //clear buffer in scanf

          if (A<0)
          {
              printf("ERROR. You should write A(only positive int) and B via space in A!/(|2*A+b|) \n");
          }
          if (repairInput!=2)
          {
              printf("ERROR. You should write A(only positive int) and B via space in A!/(|2*A+b|) \n");
          }
          if((A-(int)A)!=0)
          {
              printf("ERROR. A should be integer!. Write A and B again\n");
          }
      }
      while (repairInput!=2 || (A-(int)A)!=0 || A<0);

    if ((2*A+B)==0)
    {
        printf("ERROR. Denominator can't be zero. Write another integer\n");
        goto begin;
    }

    Q = factorial(A)/(mod(2*A+B));

    printf("Your input are \n A=%.1f\n B=%.4f\n\n Answer is %.4f\n ", A, B, Q);

    return 0;

}

