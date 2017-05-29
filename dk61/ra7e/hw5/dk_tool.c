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
			book *Naruto = &(aShelf->books[aShelf->current_size]);

			Naruto->title = (char *)malloc(sizeof(char)*(strlen(title)+1));
			strcpy(Naruto->title, title);

			Naruto->author = (char *)malloc(sizeof(char)*(strlen(author)+1));
			strcpy(Naruto->author, author);

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
	BookShelf *HarryPotter = (BookShelf *) malloc(sizeof(BookShelf));

	if(NULL != HarryPotter)
	{
		HarryPotter->books = (book *) malloc(sizeof(book) * aSize);
		memset(HarryPotter->books, 0, aSize * sizeof(book));

		HarryPotter->aSize = aSize;
		HarryPotter->current_size = 0;
	}
	return HarryPotter;
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

//interface
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
        		//swap( &aShelf->books[j].title, &aShelf->books[j + step] );
                //j--;
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
