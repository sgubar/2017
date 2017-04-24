#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 
#include "dk_tool.h"
int main(void)
{   
    printf("vodim figuri:");
	int n=inputint(4);
	spisok_figur *spisok=spisok_figur(1000);
	for(int i=0; i<n; i++)
    {
    add_coord(spisok);
    }
	print_figura(spisok);
	 InsertionSort(spisok);
	printf("Sortuim viguri:\n");
	print_figura(spisok);
	FILE *file=fopen("file.json", "w");
	printinfile_spisok(file, spisok);
	fflush(file);
	fclose(file);
	delete_spisok_figur(spisok);
}
