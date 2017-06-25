#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dk_tool.h"

unsigned int const maxSizeOfBookShelf = 30;
int main()
{
    FILE *theFile = fopen("data.json", "w");

	BookShelf *aShelf = createBookShelf(maxSizeOfBookShelf);
	addBook(aShelf, "Dan Brown", "Da_Vinci_Code");
	addBook(aShelf, "Theodore Herman Albert Dreiser", "Genius");
	addBook(aShelf, "Jack London", "Lost face");
	addBook(aShelf, " Thomas Leo Clancy", "Without Remorse");
	addBook(aShelf, "Robert Lee Frost", "A Further Range");
	addBook(aShelf, "Theodore Herman Albert Dreiser", "Genius");
	addBook(aShelf, "Jack London", "Lost face");
	addBook(aShelf, " Thomas Leo Clancy", "5Without Remorse");
	addBook(aShelf, "Dan Brown", "Da Vinci Code");
	addBook(aShelf, "Theodore Herman Albert Dreiser", "Genius");
	addBook(aShelf, "Jack London", "Lost face");
	addBook(aShelf, " Thomas Leo Clancy", "Without Remorse");
	addBook(aShelf, "Dan Brown", "Da Vinci Code");
	addBook(aShelf, "Theodore Herman Albert Dreiser", "Genius");
	addBook(aShelf, "Jack London", "Lost face");
	addBook(aShelf, " Thomas Leo Clancy", "Without Remorse");
	printBookShelf(aShelf);

	writeBookShelf(theFile, aShelf);
	destroyBookShelf(aShelf);

	fflush(theFile);
	fclose(theFile);

return 0;
	return 0;
}
