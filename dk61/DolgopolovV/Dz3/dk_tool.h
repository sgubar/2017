#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book
{
	char *Author;
	char Nazva[100];
}DK_Book;

typedef struct Shelf
{
	DK_Book *Books;
	int size;
	int current_size;
}DK_Shelf;

DK_Shelf *createShelf(int aSize);
	
int addBookToShelf(DK_Shelf *aShelf, char *aAuthor, char *aNazva);

void printBook(DK_Book *aBook);

void printShelf(DK_Shelf *inShelf);

void writeBook(FILE *aFile, DK_Book *aBook);

void writeShelf(FILE *aFile, DK_Shelf *inShelf);

#endif
