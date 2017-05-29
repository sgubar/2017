#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dk_tool.h"


unsigned int const maxSizeOfBookShelf = 30;
int main( int argc, char **argv)
{
    int aSize;
    char aValue;


    printf("Welcome to library\n\n");
	BookShelf *aShelf = createBookShelf(maxSizeOfBookShelf);
	addBook(aShelf, "Kisimoto Masashi", "Naruto");
	addBook(aShelf, "Itagaki Keisuke", "Grappler Baki");
	addBook(aShelf, "Makoto Sinkai", "Your name");
	addBook(aShelf, "Makoto Sinkai", "5 cm in a second");
	addBook(aShelf, "D.Rithi, B.Kernigan", "The C language");
	addBook(aShelf, "Itagaki Keisuke", "Grappler Baki");
	addBook(aShelf, "Makoto Sinkai", "Your name");
	addBook(aShelf, "Makoto Sinkai", "5 cm in a second");
	addBook(aShelf, "Kisimoto Masashi", "Naruto");
	addBook(aShelf, "Itagaki Keisuke", "Grappler Baki");
	addBook(aShelf, "Makoto Sinkai", "Your name");
	addBook(aShelf, "Makoto Sinkai", "5 cm in a second");
	addBook(aShelf, "Kisimoto Masashi", "Naruto");
	addBook(aShelf, "Itagaki Keisuke", "Grappler Baki");
	addBook(aShelf, "Makoto Sinkai", "Your name");
	addBook(aShelf, "Makoto Sinkai", "5 cm in a second");

	printBookShelf(aShelf);


	printf("Its Shell sort\n");

    shellSort(aShelf);
	printf (" Array is sorted!!! ");

	binarySearch (aShelf, aValue, aSize);
	printBookShelf(aShelf);

//	destroyBookShelf(BookShelf *aShelf);
}







