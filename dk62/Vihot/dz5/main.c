#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 
#include "dk_tool5.h"
#include "dk_tool5.c"
int main(void)
{   
    printf("Vedit Figur:");
	int n=inputint(4);
	spisok_figur *spisok=n_spisok_figur(9999);
	for(int i=0; i<n; i++)
    {
    add_coord(spisok);
    }
	print_figura(spisok);
	quickSort2(spisok, 0, spisok->Flag - 1);
	printf("===============================\n");
	printf(" Figuri:\n");
	print_figura(spisok);
	FILE *file=fopen("newfile.json", "w");
	printinfile_spisok(file, spisok);
	fflush(file);
	fclose(file);
	delete_spisok_figur(spisok);
}

