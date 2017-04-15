#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lw.h"
int main (void)
{
	float time;
	char method;
	int counter;
	char aline[100];

	char *line = readingFromFile(&counter) ;
	if(line!=NULL)
    {
	time = clock();
    sorting_Choice(line, counter);
	time = clock() - time;
    printf("The time of sorting: %.3f sec\n", time / CLOCKS_PER_SEC);
	}
    
    if(line!=NULL)
    {
        time=clock();
        sorting_Bubble(line, counter);
	time = clock() - time;
    printf("The time of sorting: %.3f sec\n", time / CLOCKS_PER_SEC);
    }
 
    if(line!=NULL)
    {
        time=clock();
        sorting_Inserts(line, counter);
	time = clock() - time;
    printf("The time of sorting: %.3f sec\n", time / CLOCKS_PER_SEC);
    }

	
}

