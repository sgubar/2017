#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct A_Book
{
	char *The_author;
	char *Name_Book[100];
}BookDescription;

typedef struct The_Shelf
{
	BookDescription *Books;
	int aSize;
	int current_size;
}MyShelf;

MyShelf *createShelf(int aSize);
int addBookToMyShelf(MyShelf *aShelf, char *aAuthor, char *aNazva);

void printBook(BookDescription *aBook);

void printShelf(MyShelf *inShelf);
void BubbleSortShelf(MyShelf *TheShelf, int aSize);
void destroyShelf(MyShelf *aShelf);

#endif
