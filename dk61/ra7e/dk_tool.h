#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

typedef struct tagBook
{
	char* author;
	char* title;
}book;

typedef struct tagShelf
{
	book *books;
	int aSize;
	int current_size;
}BookShelf;

BookShelf *createBookShelf (int aSize);
int addBook( BookShelf *aShelf, char* author, char* title );
void printBook(book *aBook);
void printBookShelf(BookShelf *aShelf);
void destroyBookShelf(BookShelf *aShelf);

#endif /* dk_tool_h */
