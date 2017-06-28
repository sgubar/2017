#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>

int addBook( BookShelf *aShelf, char* author, char* title )
{
	int theResult = 0;

	if (NULL != aShelf && NULL != author && NULL != title )
	{
		if (aShelf->current_size < aShelf->aSize)
		{
			book *Da_Vinci_Code = &(aShelf->books[aShelf->current_size]);

			Da_Vinci_Code->title = (char *)malloc(sizeof(char)*(strlen(title)+1));
			strcpy(Da_Vinci_Code->title, title);

			Da_Vinci_Code->author = (char *)malloc(sizeof(char)*(strlen(author)+1));
			strcpy(Da_Vinci_Code->author, author);

			aShelf->current_size ++;
		}
		else
		{
			theResult = -1;
		}
	}
	else
	theResult = -2;

	return theResult;
}

BookShelf *createBookShelf (int aSize)
{
	BookShelf *The_Open_Boat = (BookShelf *) malloc(sizeof(BookShelf));

	if(NULL != The_Open_Boat)
	{
		The_Open_Boat->books = (book *) malloc(sizeof(book) * aSize);
		memset(The_Open_Boat->books, 0, aSize * sizeof(book));

		The_Open_Boat->aSize = aSize;
		The_Open_Boat->current_size = 0;
	}
	return The_Open_Boat;
}

void destroyBookShelf(BookShelf *aShelf)
{
	if (NULL != aShelf)
	{
		if( NULL != aShelf->books )
		{
			int i;
			for(i = 0; i < aShelf->current_size; i++)
			{
				book *aBook = &(aShelf->books[i]);

				if (NULL != aBook->author)
					free(aBook->author);

				if(NULL != aBook->title )
					free(aBook->title);
			}
			free(aShelf->books);
		}
		free(aShelf);
	}

}


void printBookShelf(BookShelf *aShelf)
{
	int i;
	for(i = 0; i < aShelf->current_size; i++)
	{
		printf("Book #%i \n", i );
		book *Naruto = &(aShelf->books[i]);
		printBook(Naruto);
	}
}

void printBook(book *aBook)
{
	printf("Title  = \"%s\" \n", aBook->title );
	printf("Author = \"%s\" \n", aBook->author );
	printf("\n");
}
