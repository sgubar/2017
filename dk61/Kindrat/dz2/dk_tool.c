#include "dk_tool.h"

Rack *createPolka(int aSize)
{
	Rack *thePolka = (Rack *)malloc(sizeof(Rack));

	if (NULL != thePolka)
	{
		thePolka->Books = (Book *)malloc(aSize * sizeof(Book));
		thePolka->size = aSize;
		thePolka->current_size = 0;
	}

	return thePolka;
}

int addBookToPolka(Rack *aPolka, char *aAuthor, char *aName)
{
int theResult = 0;	

	if (NULL != aPolka && NULL != aAuthor && NULL != aName)
	{
		if (aPolka->current_size < aPolka->size)
		{
			Book *theBook = &(aPolka->Books[aPolka->current_size]);
		
			theBook->Author = (char *)malloc(sizeof(char)*(strlen(aAuthor)+1));
		
			strcpy(theBook->Author, aAuthor);
			strcpy(theBook->Name, aName);
		
			aPolka->current_size ++;
		}
	}
	else
	{
		theResult = -1;
	}
	
	return theResult;
}

void printBook(Book *aBook)
{
	printf("Author: %s\t", aBook->Author);
	printf("Name: %s\n", aBook->Name);
}

void printPolka(Rack *inPolka)
{
	printf("size: %d\t", inPolka->size);
	printf("current size: %d\n", inPolka->current_size);
	
	for (int i = 0; i < inPolka->current_size; i++)
	{
		printf("[%d] - ", i);
		printBook(&(inPolka->Books[i]));
	}
}
