#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
int a = 0, b = 0, c = 0, d = 0;
double q = 0;
printf("Enter A: ");
scanf("%d", &a);
printf("Enter B: ");
scanf("%d", &b);
printf("Enter C: ");
scanf("%d", &c);

q = drob(a, b, c);
for(d = 0; d <= b; d++)
q = q + factorial(d);

printf("Q = %.6lf\n", q);

return 0;
}
