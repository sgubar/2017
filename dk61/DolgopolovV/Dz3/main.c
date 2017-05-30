#include "dk_tool.h"

int main()
{
	DK_Shelf *theShelf = createShelf(20);
	
	FILE *theFile = fopen("data.json", "w");
	
	addBookToShelf(theShelf, "Nikolai Gogol", "Viy");
	addBookToShelf(theShelf, "Garcia Marquez", "One Hundred Years of Solitude");
	addBookToShelf(theShelf, "Mikhail Bulgakov", "The Master and Margarita");
	addBookToShelf(theShelf, "J.R.R.Tolkien", "The Lord of the Rings");
	
	printShelf(theShelf);
	
	fflush(theFile);
	fclose(theFile);
	
}
