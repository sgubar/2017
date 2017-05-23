#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "dk_tool.h"

int main(int argc, const char *argv[])
{
	
 filepiramida *polochka = Createfilepiramida(7);
 addPiramida(polochka);
  Piramida *heops = &polochka->Piramida[0];
  printf("Square = %.3f", area(heops));
  

}
