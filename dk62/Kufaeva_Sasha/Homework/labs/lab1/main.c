
#include <stdio.h>
#include "Math.h"

//int Divide (int A, int B, int C);

int main(int argc, char *argv[])
{
    int NumberA = 0;
    int NumberB = 0;
    int NumberC = 0;
    
    printf("Vvedite A:");
    scanf("%i", &NumberA);
    
    printf("Vvedite B:");
    scanf("%i", &NumberB);
    
    printf("Vvedite C:");
    scanf("%i", &NumberC);
    
    
    float Result = Divide( NumberA, NumberB, NumberC)+factorial(NumberB);

    printf ("The Result: %.2f\n", Result );
    
    
    return 0; 
}
