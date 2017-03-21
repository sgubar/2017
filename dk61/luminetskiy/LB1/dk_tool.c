#include "dk_tool.h"
#include <stdio.h>

int HEXtoDEC(void) //hexademical to decimal
{
    int f;
    printf("Number in HEX: \n");
    
    scanf("%x",&f);
    printf("Your HEX number in DEC format %d\n",f);
return f;
}
 int DECnumbers(void)
 {
 	int c;
 	printf("Print in DEC system: \n");
 	scanf("%i",&c); 
 	
 	
 	return c;
 	
 }


int sum(int d,int f, int c)
{
	int a;
    int q;
for (a=1;a<=d;a++);
	{
		
		q += a*(f-c);
	}
return q;
}



