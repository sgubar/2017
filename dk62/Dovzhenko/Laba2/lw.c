#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readingFromFile (int *InpInt)
{
	FILE *file = fopen("txt.txt", "r");
	char *aline;
	char line[1000];
    if (file == NULL)
    {
    	printf("Sorry, but file not found.\n");
    	return 0;
	}
	aline= fgets (line, sizeof(line), file);
	printf("Elements of the file: %s \n", aline);
	int counter = strlen(line);

	printf ("\nClosing file: ");
	if ( fclose (file) == EOF) printf ("Error\n");
	else printf ("Complete.\n");
}

void sorting_Choice(char line[],  int counter)
{
int min;
	for(int i=0; i<counter; i++)
	{
		 min = i;
		for(int k=i; k<counter-1; k++)
		{
			if(line[k]<line[min])
			{
				min=k;
			}
		int tmp=line[i];
		line[i]=line[min];
		line[min]=tmp;
        printf("Sorted elements: ");
        printf("%c ", line[i]);
		}		
	}
}

void sorting_Bubble(char line[], int counter)
{
	for(int i =counter - 1; i>1; i--)
	{
		for(int k = 0; k<i; k++)
		{
			if(line[k]>line[k+1])
			{
				int tmp = line[k];
				line[k]=line[k+1];
				line[k+1]=tmp;
			}
		}
		printf("Sorted elements: ");
        printf("%c ", line[i]);
	}
}

void sorting_Inserts(char line[], int counter)
{
	for(int i =1; i<counter; i++)
	{
		int tmp=line[i];
		int k=i;
		while(k>0 && line[k-1]>=tmp)
		{
			line[k]=line[k-1];
			k--;
		}
	line [k]=tmp;
printf("Sorted elements: ");
        printf("%c ", line[i]);
	}
}

