#include <stdio.h>
#include <stdlib.h>
#include "dk_lib.h"

int main () 
{
	int c, d, f, q;
	char *p, cs[8], ds[8], fs[8];
	do 
	{
		printf("Set input data (C, D in decimal format, F in hex format): ");
		scanf("%s %s %s", cs, ds, fs);
		c = atoi(cs); 
		d = atoi(ds);
		f = strtoul(fs, &p, 16); 
	} 
	while (c == 0 || d == 0 || f == 0); 
	printf("Q = sum from A=1 to D (A*(F16 - C))\n");
	q = result(c, d, f);
	printf("Q = %i\n", q);
	return 0;
}
