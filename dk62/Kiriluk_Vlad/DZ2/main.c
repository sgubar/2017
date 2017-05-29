#include "dk_tool.h"

int main()
{
	MyShelf *theShelf = createShelf(20);


	addBookToMyShelf(theShelf, "J. K. Rowling", "Harry Potter");
	addBookToMyShelf(theShelf, "Leo Tolstoy", "Anna Karenina");
	addBookToMyShelf(theShelf, "Fodor Dostoyevsky", "Crime and Punishment");
	addBookToMyShelf(theShelf, "Stephen King", "It");
	addBookToMyShelf(theShelf, "Dante Alighieri", "Divine Comedy");
	addBookToMyShelf(theShelf, "J.R.R.Tolkien", "The Lord of the Rings");
	addBookToMyShelf(theShelf, "Oscar Wilde", "The Picture of Dorian Gray");

	printShelf(theShelf);
	destroyShelf(theShelf);
}
