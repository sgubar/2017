#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"
#include "dk_tool.c"

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
	printf("Q = %.5f", Q);

    getch();
    return 0;
}
