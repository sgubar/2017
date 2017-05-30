

#include <stdio.h>
#include "tool.h"
#include <stdlib.h>

int razmer = 20;

int main()
{

	int w = 0;
	polka *the_polka = new_polka (razmer);
	char a,b;
	while (20)	{
	printf ("Hotite dodatu knigy? 1 - yes, 2 - no\n");
    scanf("%i", &w);
    if (w == 1)			{
    	printf ("Enter nazva\n");
    		scanf("%s", &a);
    		printf ("Enter avtor\n");
    		scanf("%s", &b);
    		new_kniga (the_polka, a, b);
    					}
    else					{
    	break;
    						}
				}

	print_polka(the_polka);

kick_polka (the_polka);
scanf("%s", &a);
return 0;
}
