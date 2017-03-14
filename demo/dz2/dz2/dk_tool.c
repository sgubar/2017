//
//  dk_tool.c
//  dz2
//
//  Created by Slava Gubar on 2/21/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "dk_tool.h"
#include <stdlib.h>
#include <string.h>

static void writeString(FILE *aFile, char *aKey, char *aString);

DK_PhoneBook *createPhoneBook(int aSize)
{
	DK_PhoneBook *theBook = (DK_PhoneBook *)malloc(sizeof(DK_PhoneBook));

	if (NULL != theBook)
	{
		theBook->notes = (DK_Note *)malloc(aSize * sizeof(DK_Note));
		bzero(theBook->notes, aSize * sizeof(DK_Note));
	
		theBook->size = aSize;
		theBook->current_size = 0;
	}

	return theBook;
}

void destroyPhoneBook(DK_PhoneBook *aPhoneBook)
{
	if (NULL != aPhoneBook)
	{
		if(NULL != aPhoneBook->notes)
		{
			for (int i = 0; i < aPhoneBook->current_size; i++)
			{
				DK_Note theNote = aPhoneBook->notes[i];
				if (NULL != theNote.name)
				{
					free(theNote.name);
				}
			}
		
			free(aPhoneBook->notes);
		}
	
		free(aPhoneBook);
	}
}


int addNoteToPhoneBook(DK_PhoneBook *aPhoneBook, char *aName, char *aPhone)
{
	int theResult = 0;
	
	if (NULL != aPhoneBook && NULL != aName && NULL != aPhone)
	{
		if (aPhoneBook->current_size < aPhoneBook->size)
		{
			DK_Note *theNote = &(aPhoneBook->notes[aPhoneBook->current_size]);
		
			theNote->name = (char *)malloc(sizeof(char)*(strlen(aName)+1));
		
			strcpy(theNote->name, aName);
			strcpy(theNote->phone, aPhone);
		
			aPhoneBook->current_size ++;
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

/*
		{
			"name" : "Viacheslav",
			"phone" : "123456"
		}
*/
void writeNote(FILE *aFile, DK_Note *aNote)
{
	fprintf (aFile, "{");
	
	writeString(aFile, "name", aNote->name);
	
	fprintf (aFile, ",");
	fprintf (aFile, "\"phone\":\"%s\"", aNote->phone);
	
	fprintf (aFile, "}");
}

/*
{
	"notes" : [
		the list of notes
	],
	"size" : 10,
	"current_size" : 2
}
*/

void writePhoneBook(FILE *aFile, DK_PhoneBook *aBook)
{
	fprintf (aFile, "{");
	
	//	"size" : 10,
	fprintf(aFile, "\"size\":%d", aBook->size);
	fprintf(aFile, ",");

	//	"current_size" : 2
	fprintf(aFile, "\"current_size\":%d", aBook->current_size);
	fprintf(aFile, ",");
	
	fprintf(aFile, "\"notes\":");
	
	if (NULL == aBook->notes)
	{
		fprintf(aFile, "null");
	}
	else
	{
		fprintf(aFile, "[");
	
		for (int i = 0; i < aBook->current_size; i++)
		{
			DK_Note *theNote = &(aBook->notes[i]);
		
			writeNote(aFile, theNote);
		
			if (i < (aBook->current_size - 1))
			{
				fprintf (aFile, ",");
			}
		}
	
		fprintf(aFile, "]");
	}
	
	fprintf (aFile, "}");
}

void printNote(DK_Note *aNote)
{
	printf("name: %s\t", aNote->name);
	printf("phone: %s\n", aNote->phone);
}

void printPhoneBook(DK_PhoneBook *inPhoneBook)
{
	printf("size: %d\t", inPhoneBook->size);
	printf("current size: %d\n", inPhoneBook->current_size);
	
	for (int i = 0; i < inPhoneBook->current_size; i++)
	{
		printf("[%d] - ", i);
		printNote(&(inPhoneBook->notes[i]));
	}
}

void sortPhoneBook(DK_PhoneBook *inPhoneBook)
{
	for (int theOut = 0;
				theOut < inPhoneBook->current_size - 1; theOut ++)
	{
		int theMinIndex = theOut;
	
		for (int theIn = theOut + 1;
					theIn < inPhoneBook->current_size; theIn ++)
		{
//			if (inPhoneBook->notes[theIn].name < inPhoneBook->notes[theMinIndex].name)
			if (-1 == strcmp(
						inPhoneBook->notes[theIn].phone,
						inPhoneBook->notes[theMinIndex].phone))
			{
				theMinIndex = theIn;
			}
		}
	
		DK_Note theTmp = inPhoneBook->notes[theOut];
		inPhoneBook->notes[theOut] = inPhoneBook->notes[theMinIndex];
		inPhoneBook->notes[theMinIndex] = theTmp;
	}
}

#pragma mark -

void writeString(FILE *aFile, char *aKey, char *aString)
{
	fprintf(aFile, "\"%s\":", aKey);
	
	if (NULL == aString)
	{
		fprintf (aFile, "null");
	}
	else
	{
		fprintf (aFile, "\"%s\"", aString);
	}
}

