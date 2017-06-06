#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"
int main (void)
{
    float time1, time2, time3;
	
	FILE *file = fopen("file.txt", "r");
    int i;
    char str[500]; 
    char *estr;
    
	if(file == NULL)
    {
        printf("No such file found");
        return -1;
    }else
        printf("File opened\n");

    
    estr = fgets (str, sizeof(str), file);
	if (estr == NULL)
    {

        if (feof(file) != 0)
        {
            printf ("\nReading file end\n");
        }
        else
        {
            printf ("\nError reading\n");
        }
    }

    printf ("File elements: %s\n", str);
    int counter = strlen(str);
    printf("Number of elements: %i\n", counter);

    printf ("\nClosing file: ");
    if ( fclose (file) == EOF) printf ("Error\n");
    else printf ("Complete\n");

        time1 = clock();
        SelectionSort(str, counter); 
		printf("SelectionSort: \n");
		for(i = 0; i < counter; i++) 
		{ 
			printf("%c", str[i]); 
		}  
		time1 = clock()-time1; 
		printf("\n"); 
		printf("The time1 of sorting: %.3f sec\n ", time1 / CLOCKS_PER_SEC); 
		printf("\n");
		
		time2 = clock();
        BubbleSort(str, counter); 
		printf("BubbleSort: \n");
		for(i = 0; i < counter; i++) 
		{ 
			printf("%c", str[i]); 
		}  
		time2 = clock()-time2; 
		printf("\n"); 
		printf("The time2 of sorting: %.3f sec\n ", time2 / CLOCKS_PER_SEC); 
		printf("\n");
		
		time3 = clock();
        InsertionSort(str, counter); 
		printf("InsertionSort: \n");
		for(i = 0; i < counter; i++) 
		{ 
			printf("%c", str[i]); 
		}  
		time3 = clock()-time3; 
		printf("\n"); 
		printf("The time3 of sorting: %.3f sec\n ", time3 / CLOCKS_PER_SEC); 
		printf("\n");
}
