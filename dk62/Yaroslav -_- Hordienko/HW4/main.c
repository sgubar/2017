/*
 * main.c
 *
 *  Created on: 16 ìàÿ 2017 ã.
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
	Selection_Sort_List(the_spisok);
	print_spisok(the_spisok);

	kick_spisok (the_spisok);
	scanf("%i", &y);
}
