#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


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
	free(String);
	
	char letter;
	printf ("vvedi bukvy kotoruy nada nayti: ");
	scanf ("%c", &letter);
		
		clock_t theStart1 = clock();
		int theResult =lineSearch(Lenght_of_Str ,String, letter);	
		clock_t theEnd1 = clock();

	printf ("time of line search: %.10lf\n", (double)(theEnd1 - theStart1)/CLOCKS_PER_SEC);
	if(-1 == theResult)
		printf("Not found\n");
	else		
		printf("Key founded in the %i position \n",theResult+1);
	
	system("pause");
	free(Lenght_of_Str);
	return 0;
}
