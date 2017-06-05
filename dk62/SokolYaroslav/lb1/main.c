#include <stdio.h>
#include "labdk_tool.h"

int main(void)
{
    int A,B,C=0;
    printf("Vvedite chislo A(ot -1000 do 1000) = ");
	proverka(A,1000);
    printf("Vvedite chislo B(ot -10 do 10) = ");
	proverka(B,10);
    printf("Vvedite chislo C(ot -1000 do 1000) = ");
	proverka(C,1000);
    program(A,B,C);
}
