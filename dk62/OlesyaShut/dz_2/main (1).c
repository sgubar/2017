#include <stdio.h> 
#include "dk_tool.h" 

int main(int argc, const char *argv[])
{
koordunatu* A = xy_koordunatu();
enter(A);

float S = calculate(A);
printf("\nResult: %.12f\n", S); 

if(NULL != A) 
free(A);

system("pause"); 
return 0; 
}
