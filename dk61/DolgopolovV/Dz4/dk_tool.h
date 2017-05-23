#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

typedef struct tagBook
{
	char *Author;
	char Nazva[100];
}DK_Book;

typedef struct tagPolka
{
	DK_Book *notes;
	int size;
	int current_size;
}DK_Polka;

DK_Polka *createPolka(int aSize);
	
int addBookToPolka(DK_Polka *inPolka, char *aAuthor, char *aNazva);

void printBook(DK_Book *aBook);

void printPolka(DK_Polka *inPolka);

void sortPhoneBook(DK_Polka *inPolka)

#endif
