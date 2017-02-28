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


/*
{
	"name" : nill,
	"phone" : "12345"
}
*/

//JSON
/*
{
	"notes" : [
		{
			"name" : "Viacheslav",
			"phone" : "12345"
		},
		{
			"name" : "Viacheslav2",
			"phone" : "123456"
		}
	],
	"size" : 10,
	"current_size" : 2
}
*/
typedef struct tagPhoneBook
{
	DK_Note *notes;
	int size;
	int current_size;
}DK_PhoneBook;

void writeNote(FILE *aFile, DK_Note *aNote);
void writePhoneBook(FILE *aFile, DK_PhoneBook *aBook);

DK_PhoneBook *createPhoneBook(int aSize);
void destroyPhoneBook(DK_PhoneBook *aPhoneBook);

//interfaces
int addNoteToPhoneBook(DK_PhoneBook *inPhoneBook, char *aName, char *aPhone);

#endif /* dk_tool_h */
