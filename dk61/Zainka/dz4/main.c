#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"
#include <conio.h>

int main(int argc, const char *argv[])
{
	int sort = 0;
 filepiramida *polochka = Createfilepiramida(7);
 addPiramida(polochka);
  Piramida *heops = &polochka->Piramida[0];
  printf("Square = %.3f", area(heops));
  FILE *aFile;
  fopen_s(&aFile, "data.json" , "w");
   
//printarea(polochka);
	writefilepiramida(aFile,polochka);//print pyramid list in file
printf( "                                 bouble sorting\n");
switch (sort) {
	
		Bubble_Sort_List(polochka);
		
		break;
}
	_getch();



	return 0;
}
