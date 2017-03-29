#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
int a = 0, b = 0, c = 0, d = 0;
double q = 0;

a = enter_value(a);
b = enter_value(b);
c = enter_value(c);

q = drob(a, b, c);
for(d = 0; d <= b; d++)
q += factorial(d);

printf("Q = %.3lf\n", q);
return 0;
}
