//  main.c
//  dz1 
//  Created by Stanislav Havulyak on 13/3/17.


#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
	int x, y, i, j;
	int *d, *f;
	d=&x;
	f=&y;
	printf("Write lines and colums");
	scand("%i""%i", &x, &y);
	create_matrixt(*d, *f);//Create matr1 and matr2;
	substraction_matrix(*matrx1, *matrx2, *d, *f); //matr1-matr2;
	return 0;
}

	

