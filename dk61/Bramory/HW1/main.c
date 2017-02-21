#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"

int main()
{
    int A, B = -1, C;
    float Q;
    printf("Type values: A, B[>0], C\n");
    printf("Type 1 number each time: \n");
   	 while(B < 0)
  	  {
        A = num_scan();
        B = num_scan();
        C = num_scan();
        if (B < 0) 
		   printf("Incorrect value for B[>0], try again");
   	 }

    Q = ((A*A) + (B*B)) / (float)(B + power(5, C)) + fact(B) ;
    printf("         (%i^2 + %i^2)                    = %.5f - [Q]\n", A, B, Q);
    printf("--------------------------------\n");
    printf("      (%i + 5^%i) + %i!",B, C, B);

    getch();
    return 0;
}
