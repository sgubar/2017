#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 
#include "hw4dk_tool.h"
#include "hw4dk_tool.c"
int main(void)
{   
    printf("Ведіть кількість фігур:");
	int n=inputint(4);
	spisok_figur *spisok=new_spisok_figur(9999);
	for(int i=0; i<n; i++)
    {
    add_сoord(spisok);
    }
	print_figura(spisok);
	BubbleSort (spisok);
	printf("===============================\n");
	printf("Відсортовані фігури:\n");
	print_figura(spisok);
	FILE *file=fopen("newfile.json", "w");
	printinfile_spisok(file, spisok);
	fflush(file);
	fclose(file);
	delete_spisok_figur(spisok);
}
