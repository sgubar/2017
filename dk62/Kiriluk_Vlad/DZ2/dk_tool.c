#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>



MyShelf *createShelf(int aSize)
{
	MyShelf *theShelf = (MyShelf *)malloc(sizeof(MyShelf));

	if (NULL != theShelf)
	{
		theShelf->Books = (BookDescription *)malloc(aSize * sizeof(BookDescription));
		theShelf->size = aSize;
		theShelf->current_size = 0;
	}

	return theShelf;
}

int addBookToMyShelf(MyShelf *aShelf, char *aAuthor, char *aNazva)
{
int theResult = 0;

	if (NULL != aShelf && NULL != aAuthor && NULL != aNazva)
	{
		if (aShelf->current_size < aShelf->size)
		{
			BookDescription *theBook = &(aShelf->Books[aShelf->current_size]);

			theBook->The_author = (char *)malloc(sizeof(char)*(strlen(aAuthor)+1));

			strcpy(theBook->The_author, aAuthor);
			strcpy(theBook->Name_Book, aNazva);

			aShelf->current_size ++;
		}
	}
	else
	{
		theResult = -1;
	}

	return theResult;
}

void printBook(BookDescription *aBook)
{
	printf("Author: %s\t", aBook->The_author);
	printf("Name book: %s\n", aBook->Name_Book);
}

void printShelf(MyShelf *inShelf)
{
	printf("size: %d\t", inShelf->size);
	printf("current size: %d\n", inShelf->current_size);

	for (int i = 0; i < inShelf->current_size; i++)
	{
		printf("[%d] - ", i);
		printBook(&(inShelf->Books[i]));
	}
}

void destroyShelf(MyShelf *aShelf)
{
	if (NULL != aShelf)
	{
		if(NULL != aShelf->Books)
		{
			for (int i = 0; i < aShelf->current_size; i++)
			{
				BookDescription theBook = aShelf->Books[i];
				if (NULL != theBook.The_author)
				{
					free(theBook.The_author);
				}
			}

			free(aShelf->Books);
		}

		free(aShelf);
	}
}


