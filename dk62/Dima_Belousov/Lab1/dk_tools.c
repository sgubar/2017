#include <stdio.h>
#include "dk_tools.h"

int modul(int a, int b,int c){

int result = (a * c) - b;

if(result < 0) return result * (-1);

else return result;
}

int degree(int x){
if(x == 0) return 1;

else return x*x*x;
}


int sum(int x){

int k;
int  i,j;
int result = 1;

for(i = 0; i < x; i++){
        k = 1;
    for(j = 0; j < 1+i; j++){
        k *= 2;
    }
    result += k;
}

return result;
}

float result(float mod, float deg,float su){
	return ((mod)/(deg))*(su);
}
