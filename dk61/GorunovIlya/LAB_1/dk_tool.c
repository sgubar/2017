#include <stdio.h>
#include "dk_tool.h"
 int enterNumberIn10(void)
{
	int a;
	printf("Enter a number in 10-system: ");   //просим пользователя ввести число в 10-системе
	do
	{
	    int theTmp = scanf("%d",&a);         
	    if(theTmp == 1)                            //анализируем то что ввел пользователь
	    {
		    break;
	    }
	    printf("Please,try again: ");
	    fflush(stdin);
    }
	while(1);
	
    return a;                               //возвращаем в main.c
}

int enterNumberIn16(void)
{
	int b;
	printf("Enter a number in 16-system: ");             // просим пользователя ввести число в 16-системе
	do
	{
	int theTmp = scanf("%x",&b);
	if(theTmp == 1)
	{                                      //анализируем то что ввел пользователь
        break;
    }
	printf("Please,try again: ");
	fflush(stdin);
    }
	while(1);
    return b;               // возвращаем  в main.c
}

int theSum(int D,int F, int C)
{
	int A;
	int Q;
	
	for( A = 1; A <= D; A++)
	{
	    Q += A *(F - C);                 //реализуем цикл обсчета суммы
    }
        
    return Q;     //возвращаем значение сумы в main.c
    
}
