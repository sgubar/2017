#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Kniga
{
	char *Author;
	char Name[100];
}Book;

typedef struct Polka
{
	Book *Books;
	int size;
	int current_size;
}Rack;

Rack *createPolka(int aSize);
	
int addBookToPolka(Rack *aPolka, char *aAuthor, char *aName);

void printBook(Book *aBook);

void printPolka(Rack *inPolka);

void printPolkaJson(Rack *inPolka);

void BsortPolka(Rack *inPolka);

#endif
