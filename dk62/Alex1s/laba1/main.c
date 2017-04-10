#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to test my skills in programming.\n");
printf("Enter 3 integer values:\n\n");

int a, b, c, d;
double q = 0;

enter_values(&a, &b, &c);
q = drob(a, b, c);
sigma(&q, b, d);

printf("Q = %.6lf\n", q);

system("pause");
return 0;
}
