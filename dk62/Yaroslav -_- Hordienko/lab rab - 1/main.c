#include <stdio.h>
#include <stdlib.h>
#include "funk.h"



void main()
{
    struct ABCQ *p;
    p = &rivnyannya;

    enter_peremennye(p);
    result (p);
    printf("Result uravneniya = %f", p->Q);

  }
