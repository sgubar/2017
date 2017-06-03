#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "sort.h"

#include <string.h>
#define AMOUNT_OF_SORT 5
int main(void)
{

int aSize = 1000;


   printf (" vvod simvilov d neotsortmassiv\n");
     char *neotsortmassiv = (char *) malloc(sizeof(char) *aSize);
   FILE *neotdfile = fopen("unsorted.txt", "r"); 
	
	if (NULL != neotdfile)
	{
		int i = 0, c = 0;
		
		memset (neotsortmassiv, '\0', sizeof(char) *aSize);
		while (c != EOF)
		{
		 
			c = fgetc(neotdfile);
			if ( isalpha(c) || isdigit(c))
			{
				neotsortmassiv[i] = c;
				i++;
			}
		
		}
		fclose (neotdfile);	

	}
	    
 char *Sortmassiv = (char *) malloc(sizeof(char) *aSize);     
Sortmassiv =  bubble_sort( aSize, neotsortmassiv );

 FILE *SortFile = fopen("sortBUBBLE.txt", "w"); 
	
	if (SortFile == NULL)
    {
    
	printf( "error\n");
	
	return -1;
	}
	else
{
int i;
int lenght = strlen(Sortmassiv);
//printf("%d",lenght);
	for(  i =0; i < lenght; i++)
    {
     fprintf (SortFile, "%c" , Sortmassiv[i]);
    
       }


 	printf("bubble sort\n");

	fclose(SortFile);
}
      
 char *Sortmassiv1 = (char *) malloc(sizeof(char) *aSize);
Sortmassiv1  = selection_sort( aSize, neotsortmassiv );
FILE *SortFile1 = fopen("sortSEL.txt", "w"); 
	
	if (SortFile1 == NULL)
    {
    
	printf( "error\n");
	
	return -1;
	}
	else
{
int i;
int lenght = strlen(Sortmassiv1);
//printf("%d",lenght);
	for(  i =0; i < lenght; i++)
    {
     fprintf (SortFile1, "%c" , Sortmassiv1[i]);
    
       }


 	printf("selection_sort\n");

	fclose(SortFile1);
}


char *Sortmassiv2 = (char *) malloc(sizeof(char) *aSize);
 Sortmassiv2 =insertion_sort(aSize ,neotsortmassiv);
FILE *SortFile2 = fopen("sortINSER.txt", "w"); 
	
	if (SortFile2 == NULL)
    {
    
	printf( "error\n");
	
	return -1;
	}
	else
{
int i;
int lenght = strlen(Sortmassiv2);
//printf("%d",lenght);
	for(  i =0; i < lenght; i++)
    {
     fprintf (SortFile2, "%c" , Sortmassiv2[i]);
    
       }


 	printf("insen_sort\n");

	fclose(SortFile2);
}






	printf("     S o t e  d   \n");
int i;
	float startBubbl, stopBubbl;
	float bubbleSort;
float startSELL , stopSELL;
float Sellsort;
	
	{
			
		startBubbl = clock();
	bubble_sort( aSize , Sortmassiv);
			stopBubbl = clock();
			
		 bubbleSort =  (stopBubbl - startBubbl) / CLOCKS_PER_SEC;
			
			printf("\n bubbleSort: %.25f\n", bubbleSort);
			fprintf(SortFile, " bubbleSort: %.20f.\n\nYour array after sorting: \n\n\n", bubbleSort);
		
		
		}
				
		{
				startSELL = clock();
	       selection_sort( aSize , Sortmassiv);
			stopSELL = clock();
			
		 Sellsort =  (stopSELL - startSELL) / CLOCKS_PER_SEC;
			
			printf("\n selection_sort: %.25f\n", Sellsort);
			fprintf(SortFile1, " selection_sort: %.20f.\n\nYour array after sorting: \n\n\n", Sellsort);
		}
			float startins , stopins;
			float INSsort;
		{
			startins = clock();
	       insertion_sort( aSize ,Sortmassiv);;
			stopins = clock();
			
		 INSsort =  (stopins - startins) / CLOCKS_PER_SEC;
			
			printf("\n Time of sorting: %.20f\n", INSsort);
			fprintf(SortFile2, " Time of sorting: %.20f.\n\nYour array after sorting: \n\n\n", INSsort);
		}
		
		
	   





return 0;	
	}
