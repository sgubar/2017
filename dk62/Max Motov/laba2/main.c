#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main (void)
{
    char command;
    float time;

    FILE *file = fopen("file.txt", "r");
    char str[500]; 
    char *estr;
    if(file == NULL)
    {
        printf("No such file found");
        return -1;
    }
    else
        printf("File opened\n");

    while (1)
    {
        estr = fgets (str, sizeof(str), file);

        if (estr == NULL)
        {

            if (feof(file) != 0)
            {
                printf ("\nReading file end\n");
                break;
            }
            else
            {
                printf ("\nError reading\n");
                break;
            }
        }
    }

    printf ("File elements: %s", str);
    int counter = strlen(str);
    printf("Number of elements: %i\n", counter);

    printf ("\nClosing file: ");
    if ( fclose (file) == EOF) printf ("Error\n");
    else printf ("Complete\n");

    while(1)
    {
        printf("Enter command\n List of commands:\n c -> Choose sort;\n b -> Bubble sort;\n i -> Include sort;\n e -> exit.\n\n");
        scanf ("%c\n\n", &command);

        time = clock();

        switch(command)
        {
            case 'c':
            Choose(str, counter);
            printf("Sorted elements: ");
            for(int i = 0; i < counter; i++)
            {
                printf("%c ", str[i]);
            }
            printf("\n");
            break;

            case 'b':
            Bubble(str, counter);
            printf("Sorted elements: ");
            for(int i = 0; i < counter; i++)
            {
                printf("%c ", str[i]);
            }
            printf("\n");
            break;

            case 'i':
            IncludeSort(str, counter);
            printf("Sorted elements: ");
            for(int i = 0; i < counter; i++)
            {
                printf("%c ", str[i]);
            }
            printf("\n");
            break;
            return 0;
        }

        time = clock() - time;
        printf("The time of sort: %.3f sec\n", time / CLOCKS_PER_SEC);
    }
}
