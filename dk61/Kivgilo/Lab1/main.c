#include <stdio.h>
#include "tool.h" 

int main()
{
    float X=0; 
    float Y=0; 
    float Q=0; 
    float A,C; 
    float B; 
    float D=0; 
    float sum; 

    printf("A=");
    scanf("%f",&A); 
    printf("\n");

    printf("B=");
    scanf("%f",&B); 
    printf("\n");

    printf("C=");
    scanf("%f",&C); 
    printf("\n");

    
   
     if (B + sqr(C) == 0 && B <= 0) 
        {
         printf(" Vvedi chislo > 0 \n"); 
         return 0;
        }
    else
        {
            X=(A*B)/(B+sqr(C)); 
            printf("X=%f",(A*B)/(B+sqr(C))); 
        }
    printf("\n");
    
    Y=suma_factorialov(D,B); 
    
    printf("Y=%f",suma_factorialov(D,B)); 
    printf("\n");

    Q=X+Y;
    printf("Q=%f",X+Y);
}


