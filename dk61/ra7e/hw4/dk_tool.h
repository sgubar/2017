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
void bubbleSort( BookShelf *aShelf,  int aSize);
void selectionSort(BookShelf *aShelf, int aSize)
void insertionSort(BookShelf *aShelf,  int aSize);
//void writeBook(FILE *aFile, book *BookShelf);
//void writeBookShelf(FILE *aFile, BookShelf *Shelf);

#endif /* dk_tool_h */
