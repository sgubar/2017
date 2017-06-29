#include "dk_tool.h"

int main()
{
	DK_Shelf *theShelf = createShelf(20);

	addBookToShelf(theShelf, "Nikolai Gogol", "Viy");
	addBookToShelf(theShelf, "Garcia Marquez", "One Hundred Years of Solitude");
	addBookToShelf(theShelf, "Mikhail Bulgakov", "The Master and Margarita");
	addBookToShelf(theShelf, "J.R.R.Tolkien", "The Lord of the Rings");

	printShelf(theShelf);
	getch();

	system("cls");
	qs(theShelf, 0, theShelf->current_size-1);
	printShelf(theShelf);
	LineSearch(theShelf, theShelf->current_size - 1);
	getch();
}
