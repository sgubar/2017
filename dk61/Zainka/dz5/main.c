#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"
#include <conio.h>

int main(int argc, const char *argv[])
{
	int value = 0;
	int sort = 0;
 filepiramida *polochka = Createfilepiramida(7);
 addPiramida(polochka);
  Piramida *heops = &polochka->Piramida[0];
  printf("Square = %.3f", area(heops));
  FILE *aFile;
  fopen_s(&aFile, "data.json" , "w");
   
//printarea(polochka);
{
int index = 0 ;

float key  =0;	
printf("\n\nType the point which do you want to find ");
scanf(" %i", & key  );

		 printf("\n\n Binary_search:\n\n" );
	  index = binary_search(key, polochka);
		if ( index != -1)
		{
			printf("\n 6 Found in object #%d:\n", index );	
				
		}
		else 
			printf("\nError 404. Not found object");	
}

	writefilepiramida(aFile,polochka);//print pyramid list in file
printf( "                                 bouble sorting\n");
switch (sort) {
	
		Bubble_Sort_List(polochka);
		
		break;
}
	_getch();



	return 0;
}
