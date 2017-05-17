/*
 * main.c
 *
 *  Created on: 16 мая 2017 г.
 *      Author: Yaroslav Hordiienko
 */

#include <stdio.h>
#include "tool.h"
#include <stdlib.h>

int razmer = 10;

int main()
{
	sad ();
	int w = 0;
	spisok *the_spisok = new_spisok (razmer);
	int x, y, r;
	while (10)	{
	printf ("Hotite dodatu kolo? 1 - yeees, 2 - no\n");
    scanf("%i", &w);
    if (w == 1)			{
    	printf ("Enter x\n");
    		scanf("%i", &x);
    		printf ("Enter y\n");
    		scanf("%i", &y);
    		printf ("Enter r\n");
    		scanf("%i", &r);
    		new_kolo (the_spisok, x, y, r);
    					}
    else					{
    	break;
    						}
				}

	print_spisok(the_spisok);
	printf("Ploshchy kakoho kola vu hotite yznaty?\n");
	scanf("%i", &y);
	float S = print_nomer_kolo(the_spisok, y);
	printf("Ploshcha ravna %f\n", S);
	printf("Hochete zapisaty ci danni v fayl? 1 - yes, 2 - no\n");
	scanf("%i", &x);
	if (x==1)   {
	zapis (the_spisok, y);
				}
	kick_spisok (the_spisok);
	scanf("%i", &y);
}
