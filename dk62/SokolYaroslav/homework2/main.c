#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#include<ctype.h> 
#include "hw2dk_tool.h"
#include "hw2dk_tool.c"
int main(void)
{   
    
    printf("Ведіть кількість фігур:");
	int n=inputint(3);
	spisok_figur *spisok=new_spisok_figur(1000);
	for(int i=0; i<n; i++)
    {
    addсoord(spisok);
    }
	printFigure(spisok);
	destroyFigureList(spisok);
}
