#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>
#include <ctype.h> 
#include "dk_tool2.h"
#include "dk_tools2.c"

int main (void)
{

 printf("Ведіть кількість фігур:");
	int n=inputint(4);
	spisok_figur *spisok=new_spisok_figur(9999);
	for(int i=0; i<n; i++)
    {

  add_сoord(spisok);
    }
	print_figura(spisok);
	delete_spisok_figur(spisok);
}
