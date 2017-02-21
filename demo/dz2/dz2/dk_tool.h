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

typedef struct tagPhoneBook
{
	DK_Note *notes;
	int size;
	int current_size;
}DK_PhoneBook;

DK_PhoneBook *createPhoneBook(int aSize);
void destroyPhoneBook(DK_PhoneBook *aPhoneBook);

//interfaces
int addNoteToPhoneBook(DK_PhoneBook *inPhoneBook, char *aName, char *aPhone);

typedef union tagTest
{
	char a;
	int b;
}DK_Test;

#endif /* dk_tool_h */
