#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"
int main (void)
{
    float time;
    char searched_element;
    int result;
    char str[500];

    FILE *file = fopen("file.txt", "r");
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


    time = clock();
    ShellSort(counter, str);
    time = clock() - time;
    printf("The time of sort: %.3f sec\n\n", time / CLOCKS_PER_SEC);


    printf("Input element u want to find\n");
    scanf("%c", &searched_element);
    result = BinarySearch(str, searched_element, counter);
    if(result == -1)
        printf("No such element in file");
    else
        printf("Index of searched element is: %i\n", result);
}
