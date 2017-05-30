#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>



MyShelf *createShelf(int aSize)
{
	MyShelf *theShelf = (MyShelf *)malloc(sizeof(MyShelf));

	if (NULL != theShelf)
	{
		theShelf->Books = (BookDescription *)malloc(aSize * sizeof(BookDescription));
		theShelf->aSize = aSize;
		theShelf->current_size = 0;
	}

	return theShelf;
}

int addBookToMyShelf(MyShelf *aShelf, char *aAuthor, char *aNazva)
{
int theResult = 0;

	if (NULL != aShelf && NULL != aAuthor && NULL != aNazva)
	{
		if (aShelf->current_size < aShelf->aSize)
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
	printf("size: %d\t", inShelf->aSize);
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

void printShelfJson(MyShelf *inShelf)
{
	if(inShelf != NULL)
	{
		FILE *afile = fopen("D\Vlad\json.json","w");
		if(afile == NULL)
		{
			printf("File error\n");
			return;
		}
		fprintf(afile,"{\"Size\":%i,\"Current size\":%i", inShelf->size, inShelf->current_size);
		fprintf(afile, "\"Books\":[\n");

		for(int i = 0; i < inShelf->current_size; i++)
		{
			fprintf(afile, "{\n");
			BookDescription *aCurrent = &(inShelf->Books[i]);
			fprintf(afile, "\t\"Author\":%s,\n", aCurrent->The_author);
			fprintf(afile, "\t\"Name book\":%s,\n", aCurrent->Name_Book);
			fprintf(afile, "},\n");
		}
		fprintf(afile, "]}\n");

		fflush(afile);
		fclose(afile);
		printf("\nAdded to file \"Library.json\"\n");
	}
}

