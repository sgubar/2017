#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main(int argc, char *argv[]) {
int a = 0, b = 0, c = 0, d = 0;
double q = 0;
  
printf("Enter A: ");
scanf("%d", &a);
printf("Enter B: ");
scanf("%d", &b);
printf("Enter C: ");
scanf("%d", &c);

q = drob(a, b, c);         //the first part of the formula
for(d = 0; d <= b; d++)    //the second part of the formula
q = q + factorial(d);

printf("Q = %.6lf\n", q);  //print result with 6 numbers after point

return 0;
}
