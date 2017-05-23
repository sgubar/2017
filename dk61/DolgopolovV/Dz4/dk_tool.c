#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


DK_Polka *createPolka(int aSize)
{
	DK_Polka *thePolka = (DK_Polka *)malloc(sizeof(DK_Polka));

	if (NULL != thePolka)
	{
		thePolka->notes = (DK_Book *)malloc(aSize * sizeof(DK_Book));
	
	
		thePolka->size = aSize;
		thePolka->current_size = 0;
	}

	return thePolka;
}

int addBookToPolka(DK_Polka *aPolka, char *aAuthor, char *aNazva)
{
	int theResult = 0;
	
	if (NULL != aPolka && NULL != aAuthor && NULL != aNazva)
	{
		if (aPolka->current_size < aPolka->size)
		{
			DK_Book *theBook = &(aPolka->notes[aPolka->current_size]);
		
			theBook->Author = (char *)malloc(sizeof(char)*(strlen(aAuthor)+1));
		
			strcpy(theBook->Author, aAuthor);
			strcpy(theBook->Nazva, aNazva);
		
			aPolka->current_size ++;
		}
		else
		{
			theResult = -2;
		}
	}
	else
	{
		theResult = -1;
	}
	
	return theResult;
}

void printBook(DK_Book *aBook)
{
	printf("Author: %s\t", aBook->Author);
	printf("Nazva: %s\n", aBook->Nazva);
}

void printPolka(DK_Polka *inPolka)
{
	printf("size: %d\t", inPolka->size);
	printf("current size: %d\n", inPolka->current_size);
	
	for (int i = 0; i < inPolka->current_size; i++)
	{
		printf("[%d] - ", i);
		printBook(&(inPolka->notes[i]));
	}
}

void sortPhoneBook(DK_PhoneBook *inPhoneBook)
{
	for (int theOut = 0;theOut < inPhoneBook->current_size - 1; theOut ++)
	{
		int theMinIndex = theOut;
	for (int theIn = theOut + 1;theIn < inPhoneBook->current_size; theIn ++)
		{
			if (inPhoneBook->notes[theIn].Author < inPhoneBook->notes[theMinIndex].Author)
			{
				theMinIndex = theIn;
			}
		}
	
		DK_Book theTmp = inPolka->notes[theOut];
		inPolka->notes[theOut] = inPolka->notes[theMinIndex];
		inPolka->notes[theMinIndex] = theTmp;
	}
}
