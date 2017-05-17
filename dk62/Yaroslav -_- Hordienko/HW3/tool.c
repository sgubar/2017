/*
 * tool.c
 *
 *  Created on: 16 мая 2017 г.
 *      Author: Yaroslav Hordiienko
 */
#include "tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int new_kolo (spisok *aList, int a, int b, int c)
{
		if ( aList->current_size < aList -> size )
		{
		      kolo *the_kolo = &(aList -> kolas [aList -> current_size] );
				if (NULL != the_kolo)
			{
					the_kolo -> x = a;
					the_kolo -> y = b;
					the_kolo -> r = c;
				aList -> current_size ++;
			}
		}
		else
		{
			printf("\tErrorka, spisok polon.\n");
			return -2;
		}

	printf("Nowa kniga sozdano\n");
	return 0;
}

spisok *new_spisok ( int aSize)
{
	spisok *the_spisok = (spisok *)malloc (sizeof(spisok));
	if (the_spisok != NULL)
	{
		the_spisok -> kolas = (kolo *) malloc(aSize * sizeof(kolo));
		memset(the_spisok -> kolas, 0, aSize * sizeof(kolo) );

		the_spisok -> size = aSize;
		the_spisok -> current_size = 0;
	printf("Spisok sozdan!\n");
	}
return the_spisok;
}

int print_kolo(kolo *nove_kolo){
	if (NULL == nove_kolo)
			printf("Pusto");
			else
			{
				printf (" x  : %i\n", nove_kolo->x);
				printf (" y  : %i\n", nove_kolo->y);
				printf (" radius  : %i\n\n", nove_kolo->r);

			}
	return 0;
}

int print_spisok(spisok *the_spisok){
	int i;
	for(i = 0; i < the_spisok->current_size; i++)
	{
		kolo *kolo = &(the_spisok->kolas[i]);
		printf("Nomer kola %i\n",i);
		print_kolo(kolo);
		printf("\n\n\n");
	}
return 0;
}

void sad (void)
{
system("color 4F");
}

void kick_spisok (spisok *the_spisok)
{
	if (NULL != the_spisok)
	{
		if(NULL != the_spisok -> kolas)
		{
			free(the_spisok->kolas);
		}
	free(the_spisok);
	}
}

float print_nomer_kolo(spisok *the_spisok, int i){
			kolo *kolo = &(the_spisok->kolas[i]);
			return kolo->r*kolo->r*3.14;
}

int zapis (spisok *the_spisok, int i){
	FILE *f;

	     if ((f = fopen("ploshca.json","w")) == NULL)
	        printf("Error 404\n");
	     else{
	    	 kolo *kolo = &(the_spisok->kolas[i]);
	    	 fprintf(f,"Kolo mae taki xarakteristiku\n x = %i\n y = %i\n radius = %i\n ploshcha = %f", kolo->x, kolo->y, kolo->r, print_nomer_kolo(the_spisok, i) );
	     }
	     fclose(f);
	 	printf("Danni v file zapisany\n");
	     return 0;
}
