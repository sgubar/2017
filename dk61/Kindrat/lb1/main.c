#include <stdio.h>
#include "test.h"

int main(void) {
	
	int a, b, c;
	int d = 0;
	int box = 0;
	int box_c = 0 ;
	int module_result;
 
	printf("vvedite A>0,C ne ravno 0\n"); 
	scanf("%i""%i""%i", &a, &b, &c);
	if (a > 0 && c != 0)
	{ 
		
    	printf("A : %i, B : %i, C : %i, D : %i\n", a, b, c, d);
    	int step1 = module(a,b,c,module_result);
    	int step2 = step_c(c,box_c);
    	int step3 = sum(a,d,box);
    	printf("sum result : %i\n", step3);
    	printf("power result :%i\n",step2);
		printf("main modul %i\n", step1);
		float del = ((float)step1/(float)step2);
		float resultat = del*step3;
		printf("result : %f\n", resultat); 
	}
	else
	{
		printf("ERROR!");
	}	
	
}
