#include"dk_tool.h"
#include <stdio.h>

double func_pow(double A)
 { 
 double D=0, Sigma=0; \\ініціалізація значень 
 double pow=1;
 int i;
 if(A>0) \\перевірка на знак константи А
{
 for(i=0; i<A-1; i++)
 {
     pow*=2;   \\піднесення 2^A
 }
 for( D=0; D<=A; D++)
 {
 	pow*=2; \\піднесення 2^(A+D)
 	Sigma+=pow; \\додавання значень
 }
   return Sigma; \\повернення результату 
 }

else \\якщо А має зворотній знак
{
for(i=0; i<A*(-1)-1; i++)
 {
     pow*=0.5;   \\піднесення 2^(-A)
 }
 for( D=0; D<=A*(-1); D++)
 {
 	pow*=0.5; \\піднесення 2^-(A+D)
 	Sigma+=pow;
 }
   return Sigma; \\повернення результату
 }
}
