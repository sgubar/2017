#include "dk_tool.h"

DK_Shelf *createShelf(int aSize)
{
	DK_Shelf *theShelf = (DK_Shelf *)malloc(sizeof(DK_Shelf));

	if (NULL != theShelf)
	{
		theShelf->Books = (DK_Book *)malloc(aSize * sizeof(DK_Book));
		theShelf->size = aSize;
		theShelf->current_size = 0;
	}

	return theShelf;
}

int addBookToShelf(DK_Shelf *aShelf, char *aAuthor, char *aNazva)
{
	int theResult = 0;

	if (NULL != aShelf && NULL != aAuthor && NULL != aNazva)
	{
		if (aShelf->current_size < aShelf->size)
		{
			DK_Book *theBook = &(aShelf->Books[aShelf->current_size]);

			theBook->Author = (char *)malloc(sizeof(char)*(strlen(aAuthor) + 1));

			strcpy(theBook->Author, aAuthor);
			strcpy(theBook->Nazva, aNazva);

			aShelf->current_size++;
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

void printShelf(DK_Shelf *inShelf)
{
	printf("size: %d\t", inShelf->size);
	printf("current size: %d\n", inShelf->current_size);

	for (int i = 0; i < inShelf->current_size; i++)
	{
		printf("[%d] - ", i);
		printBook(&(inShelf->Books[i]));
	}
}

void qs(DK_Shelf *arr, int low, int high)
{
	int pivot, i, j;
	DK_Book temp;
	if (low < high) 
	{
		pivot = low; 
		i = low;
		j = high;
		while (i < j) 
		{
			while (arr->Books[i].Author[0] <= arr->Books[pivot].Author[0] && i < high)
				i++;
			while (arr->Books[j].Author[0] > arr->Books[pivot].Author[0] && j > low)
				j--;
			if (i < j)
			{
				temp = arr->Books[i];
				arr->Books[i] = arr->Books[j];
				arr->Books[j] = temp;
			}
		}

		temp = arr->Books[j];
		arr->Books[j] = arr->Books[pivot];
		arr->Books[pivot] = temp;
		qs(arr, low, j - 1);
		qs(arr, j + 1, high);
	}
}

void LineSearch(DK_Shelf *arr, int string_lenght)
{
	char key;
	printf("Enter symbol to find : ");
	scanf("%c", &key);
	printf("You entered : %c\n", key);
	printf("Position : ");
	for (int i = 0; i < string_lenght; i++)
	{
		if (arr->Books[i].Author[0] == key)
		{
			printf("[%i] ", i);
		}
	}
}