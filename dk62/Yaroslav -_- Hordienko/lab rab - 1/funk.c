#include "funk.h"

int stepin (int a, int b) {
 int x = 0;
 int result = 1;
 while ( x < b ) {
    result = result * a;
    x++;
 }
return result;
}

int faktorial (int e) {
int result = 1;
while( e != 0 ) {
    result = result * e;
    e--;
}
return result;
}

int kvadrat (int a) {
 int result = 0;
 result = a*a;
 return result;
}

void enter_peremennye (struct ABCQ *p) {
    printf("Hello\n Rivnyannya mae vud Q = ((A^2 + B^2)/(B + 5^C)) + B!\n");
    printf("Enter A\n");
    scanf("%d", &p->A);
    printf("Enter B\n");
    scanf("%d", &p->B);
      while (p->B <0 ) {
    printf("Peremennaya B ne mojet bytu < 0\n Povtorit sproby\n");
    scanf("%d", &p->B);
            }
    printf("Enter C\n");
    scanf("%d", &p->C);
}

float syma (float a, float b){
float result = 0;
result = a + b;
return result;
}

float dilennya (float a, float b){
float result = 0;
result = a / b;
return result;
}

  void result (struct ABCQ *p){

    p->Q= syma( dilennya ( syma(  kvadrat(p->A), kvadrat(p->B) ), syma(p->B, stepin(5, p->C))   ), faktorial(p->B) );
    printf("Result uravneniya = %f", p->Q);
}
