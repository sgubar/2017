#ifndef dk_tool_h
#define dk_tool_h
#include <string.h>


	typedef	struct KYKI
	{
		int x;
		int y;
		int z;
} kordinati;

typedef	struct Piramida
{
	kordinati *points[4]; 

} Piramida;


typedef struct filepiramida
{
	Piramida *Piramida;
	int size;
	int current_size;
}filepiramida;



filepiramida *Createfilepiramida(int aSize);
 int addPiramida(filepiramida *polochka);
 float area(Piramida *heops);
void writePiramida(FILE *aFile, Piramida *heops);
void writefilepiramida(FILE *aFile, filepiramida *polochka); 
void swap(Piramida *var1, Piramida *var2);
void Shell_Sort_List( filepiramida *polochka );

int binary_search(float key, filepiramida *polochka);
//void printarea(filepiramida *polochka);

#endif
 
