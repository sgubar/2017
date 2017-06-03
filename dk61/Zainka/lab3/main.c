#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "shell_sort.h"

#include <string.h>
int main()
{
int aSize = 10000;
int Size = 10000;
	char *neotsortmassiv = (char *) malloc(sizeof(char) *aSize);
	FILE *neotdfile = fopen("filemassiv.txt", "r"); 
	
	if (NULL != neotdfile)
	{
		int i = 0, c = 0;
		
		memset (neotsortmassiv, '\0', sizeof(char) *aSize);
		printf (" vvod simvilov d neotsortmassiv\n");
		while (c != EOF)
		{
		 
			c = fgetc(neotdfile);
			if
			 ( isalpha(c) || isdigit(c))
			{
				neotsortmassiv[i] = c;
				i++;
			}
		
		}
		fclose (neotdfile);	

	}

	
	char *Sortmassiv = (char *) malloc(sizeof(char) *aSize);     
	Sortmassiv =  shell_sort( aSize, neotsortmassiv );

 FILE *SortFile = fopen("sortirovanij.txt", "w"); 
	
	if (SortFile == NULL)
    {
    
	printf( "error\n");
	
		return -1;
	}
	else
{
	int i;
	int lenght = strlen(Sortmassiv);
	
		for(  i =0; i < lenght; i++)
	    {
			fprintf (SortFile, "%c" , Sortmassiv[i]);
	    }
	
	 	printf("zapis zakonchena\n");
	 }
	fclose(SortFile);
	
	int i;

		for(  i =0; i < strlen(Sortmassiv); i++)
	    {
			printf ( "%c " , Sortmassiv[i]);
	    }
	    printf ( "\n");
	
	 char key ;
	scanf("%c"  , & key);
{
	  
	char  Nshel = binary_search(  key, aSize, Sortmassiv);
	printf("the  is: %i \n" ,Nshel);
}
float starshell;
float start;
float stop;
{



start = clock();
	       shell_sort(  aSize, neotsortmassiv );
			stop = clock();
			
		 starshell =  (stop -start) / CLOCKS_PER_SEC;
			
			printf("\n shellsort: %.20f\n", starshell);
			fprintf(SortFile, " Time of sorting: %.20f.\n", starshell);
		}
		


	return 0;
}
