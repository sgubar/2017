#include "dk_tool.h"
#include <stdio.h>

int HEXtoDEC(void) //hexademical to decimal
{
    int f;
    printf("Number in HEX: \n");
     do
	{
	    int temp = scanf("%x",&f);         
	    if(temp == 1)                           
	    {
		    break;
	    }
	    printf("Write another number: ");
	    fflush(stdin);
    }
	while(1);
	
   
    
    printf("Your HEX number in DEC format %d\n",f); 
return f;
}
 int DECnumbers(void) //user is writing DEC numbers
 {
 	int c;
 	printf("Print in DEC system: \n");
 	
 	 do
	{
	    int temp = scanf("%d",&c);         
	    if(temp == 1)                           
	    {
		    break;                               //if the numbers contain an uknown symbol ask user to write another
	    }
	    printf("Write another number: ");
	    fflush(stdin);
    }
	while(1);
	
 	
 	
 	
 	return c;
 	
 }


int summing(int d,int f, int c)  //the main function
{
	int a;
    int q;
for (a=1;a<=d;a++);
	{
		
		q += a*(f-c);
	}
return q;
}


