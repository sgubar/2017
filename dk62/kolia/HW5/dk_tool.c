#include <stdio.h>
#include "dk_tool.h"
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
		book *Da_Vinci_Code = &(aShelf->books[i]);
		printBook(Da_Vinci_Code);
	}
}

void printBook(book *aBook)
{
	printf("Title  = \"%s\" \n", aBook->title );
	printf("Author = \"%s\" \n", aBook->author );
	printf("\n");
}

void shellSort(BookShelf *aShelf )
{
	    int i, step = aShelf -> current_size / 2;
	while (step > 0)
    {
      for (i = 0; i < (aShelf->current_size - step); i++)
        {
      	  int j = i;
          while (j >= 0 && (&aShelf->books[j].title ) <( &aShelf->books[j + step].title) )
            {


                char tmp = aShelf->books[j].title;
                aShelf->books[j].title = aShelf->books[j + step].title;
                aShelf->books[j + step].title = tmp;
            }
		}
    step /= 2;
	}
}


 int binarySearch(BookShelf *aShelf, char aValue, int aSize)
{
	int theRightLimit = aSize - 1;
	int theLeftLimit = 0;
	int theResult = -1;
	int middleValue = 0;

	while(1)
	{
		int middleValue = (theLeftLimit + theRightLimit)/2;

		if(aShelf -> books[middleValue].title == aValue)
		{
			theResult = middleValue;
			break;
		}
		else if(theLeftLimit > theRightLimit)
		{
			break;
		}
		else
		{
			if(aShelf->books[middleValue].title > aValue)
			{
				theRightLimit = middleValue - 1;
			}
			else
			{
				theLeftLimit = middleValue + 1;
			}
		}
	}
	return theResult;

}
