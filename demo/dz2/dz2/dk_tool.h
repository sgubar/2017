//
//  dk_tool.h
//  dz2
//
//  Created by Slava Gubar on 2/21/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

typedef struct tagNote
{
	char *name;
	char phone[12];
}DK_Note, *PDK_Note;

void writeNote(FILE *aFile, DK_Note *aNote);

typedef struct tagPhoneBook
{
	DK_Note *notes;
	int size;
	int current_size;
}DK_PhoneBook;

void writeNote(FILE *aFile, DK_Note *aNote);
void writePhoneBook(FILE *aFile, DK_PhoneBook *aBook);

/*
{
	"notes":[
		{
			"name" : "Viacheslav",
			"phone" : "123456"
		},
		{
			"name" : "Viacheslav2",
			"phone" : "1234567"
		}
	],
	"size" : 20,
	"current_size" : 2
}
*/


DK_PhoneBook *createPhoneBook(int aSize);
void destroyPhoneBook(DK_PhoneBook *aPhoneBook);

//interfaces
int addNoteToPhoneBook(DK_PhoneBook *inPhoneBook, char *aName, char *aPhone);

#endif /* dk_tool_h */
