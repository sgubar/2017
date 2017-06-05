#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int Lenght_of_Str;
	char *String = Transform_file (&Lenght_of_Str);
	if(NULL != String)
	{
		clock_t theStart = clock();
		shellSort(Lenght_of_Str,String);
		clock_t theEnd = clock();
		printf ("time of sort: %.10lf\n", (double)(theEnd - theStart)/CLOCKS_PER_SEC);
		putchar('\n');
	}
	
	char Key;
	printf ("Key: ");
	scanf ("%c", &Key);
	clock_t theStart1 = clock();
	int theResult =line_find(Lenght_of_Str ,String, Key);	
	clock_t theEnd1 = clock();
	printf ("time of line search: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
	if(-1 == theResult)
		printf("\nNot found\n");
	else		
		printf("\n Key founded in the %i position \n",theResult+1);
	free(String);
	return 0;
}
