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

/*void writeBook(FILE *aFile, book *BookS)
{
	fprintf (aFile, "{");

	writeString(aFile, "Author name", BookS->author);

	fprintf (aFile, ",");
	fprintf (aFile, "\"Title\":\"%s\"", BookS->title);

	fprintf (aFile, "}");
}


void writeBookShelf(FILE *aFile, BookShelf *Shelf)
{
	fprintf (aFile, "{");


	fprintf(aFile, "\"size\":%d", Shelf->aSize);
	fprintf(aFile, ",");

	fprintf(aFile, "\"current_size\":%d", Shelf->current_size);
	fprintf(aFile, ",");

	fprintf(aFile, "\"books\":");

	if (NULL == Shelf->books)
	{
		fprintf(aFile, "null");
	}
	else
	{
		fprintf(aFile, "[");
		int i;

		for ( i=0; i < Shelf->current_size; i++)
		{
			book *aBook = &(Shelf->books[i]);

			writeBook(aFile,aBook);

			if (i < (Shelf->current_size - 1))
			{
				fprintf (aFile, ",");
			}
		}

		fprintf(aFile, "]");
	}

	fprintf (aFile, "}");
}


void bubbleSort(BookShelf *aShelf)
{
	int theOut=aShelf->current_size;

	for (theOut; theOut > 1; theOut --)// 1 цикл
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)//2 цикл
		{
			if (aShelf->books[theIn].title > aShelf->books[theIn+ 1].title )
			{
				book *timeBook = aShelf->books[theIn].title;
				aShelf->books[theIn].title = aShelf->books[theIn + 1].title;
                aShelf->books[theIn + 1].title = timeBook;
			}
		}
	}
}

void selectionSort(BookShelf *aShelf)
{
		int i = 0;
	for (i=0; i < aShelf->current_size - 1; i ++)
	{
		int theMinIndex = i;

		int theIn = i + 1;
		for (theIn; theIn < aShelf->current_size; theIn ++)
		{
			if (aShelf->books[theIn].title < aShelf->books[theMinIndex].title)
			{
				theMinIndex = theIn;
			}
		}

		book *timeBook = aShelf->books[theIn].title;
		aShelf->books[theIn].title = aShelf->books[theMinIndex].title;
        aShelf->books[theMinIndex].title = timeBook;
	}
}
void insertionSort(BookShelf *aShelf,  int aSize)
{
	int i = 1;
	for (i; i < aSize; i ++)
	{
	    int theIn = i;
		book *timeBook = aShelf->books[theIn].title[i];


		while (theIn > 0 && aShelf->books[theIn - 1].title >= timeBook)
		{
			aShelf->books[theIn].title = aShelf->books[theIn -1 ].title;
			-- theIn;
		}

		aShelf->books[theIn].title = timeBook;
	}
}
*/

    int binarySearch(BookShelf *aShelf)


{
    int aValue ;
	int theRightLimit = aShelf->current_size - 1;
	int theLeftLimit = 0;
	int theResult = aShelf->current_size;
	char middleValue = 0;

	while(1)
	{
		middleValue = (theLeftLimit + theRightLimit)/2;

		if(aShelf->books[middleValue].title == aValue)
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



void shellSort(BookShelf *aShelf )
{
    int i, step = aShelf-> current_size / 2;
	while (step > 0)
    {
      for (i = 0; i < (aShelf->current_size - step); i++)
        {
            int j=0;
      	    j = i;
            while  (&aShelf->books[j].title  >  &aShelf->books[j+ step].title )
        {
        		//swap( &aShelf->books[j].title, &aShelf->books[j + step].title);

        		book* timeBook = aShelf->books[j].title ;
        		aShelf->books[j].title = (aShelf->books[j + step].title);
        		aShelf->books[j + step].title = timeBook;

                 j--;
            }
		}
    step /= 2;
	}
}

