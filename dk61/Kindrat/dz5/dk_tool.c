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



void shellSort(Rack *aPolka )
{
	    int i, step = aPolka -> current_size / 2;
	while (step > 0)
    {
      for (i = 0; i < (aPolka->current_size - step); i++)
        {
      	  int j = i;
          while (j >= 0 && (&aPolka->Books[j].Name ) <( &aPolka->Books[j + step].Name) )
            {
        		
                char tmp = aPolka->Books[j].Name;
                aPolka->Books[j].Name = aPolka->Books[j + step].Name;
                aPolka->Books[j + step].Name = tmp;
            }
		}
    step /= 2;
	}
}


 int binarySearch(Rack *aPolka, char aValue, int size)
{
	int theRightLimit = size - 1;
	int theLeftLimit = 0;
	int theResult = -1;
	int middleValue = 0;

	while(1)
	{
		int middleValue = (theLeftLimit + theRightLimit)/2;

		if(aPolka -> Books[middleValue].Name == aValue)
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
			if(aPolka->Books[middleValue].Name > aValue)
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
