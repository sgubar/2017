
#include "tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int new_kniga(polka *new_polka, char a, char b)
{
		if ( new_polka->current_size < new_polka -> size )
		{
			kniga *the_kniga = &(new_polka -> knigi [new_polka -> current_size] );
				if (NULL != the_kniga)
			{
					the_kniga -> name = a;
					the_kniga -> avtor = b;

				new_polka -> current_size ++;
			}
		}

	printf("Nowa kniga sozdano\n");
	return 0;
}

polka *new_polka ( int aSize)
{
	polka *the_polka = (polka *)malloc (sizeof(polka));
	if (the_polka != NULL)
	{
		the_polka -> knigi = (kniga *) malloc(aSize * sizeof(kniga));
		memset(the_polka -> knigi, 0, aSize * sizeof(kniga) );

		the_polka -> size = aSize;
		the_polka -> current_size = 0;
	printf("Spisok sozdan!\n");
	}
return the_polka;
}

int print_kniga(kniga *nove_kniga){
	if (NULL == nove_kniga)
			printf("Pusto");
			else
			{
				printf (" x  : %s\n", nove_kniga->avtor);
				printf (" y  : %s\n", nove_kniga->name);

			}
	return 0;
}

int print_polka(polka *the_polka){
	int i;
	for(i = 0; i < the_polka->current_size; i++)
	{
		kniga *kniga = &(the_polka->knigi[i]);
		printf("Nomer kola %i\n",i);
		print_kniga(kniga);
		printf("\n\n\n");
	}
return 0;
}

void sad (void)
{
system("color 4F");
}

void kick_polka (polka *the_polka)
{
	if (NULL != the_polka)
	{
		if(NULL != the_polka -> knigi)
		{
			free(the_polka->knigi);
		}
	free(the_polka);
	}
}
