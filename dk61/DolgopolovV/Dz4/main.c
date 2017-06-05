#include "dk_tool.h"

int main()
{
	DK_Shelf *theShelf = createShelf(20);
	
	addBookToShelf(theShelf, "J.R.R.Tolkien", "The Lord of the Rings");
	addBookToShelf(theShelf, "Nikolai Gogol", "Viy");
	addBookToShelf(theShelf, "Garcia Marquez", "One Hundred Years of Solitude");
	addBookToShelf(theShelf, "Mikhail Bulgakov", "The Master and Margarita");
	
	
	printShelf(theShelf);
	
	sortShelf(theShelf);
	
	printf ("After sorting\n");
	printShelf(theShelf);	
}
