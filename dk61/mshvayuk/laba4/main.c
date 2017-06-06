//За один перегляд текстового файлу надрукувати вміст текстового файлу, 
//виписуючи літери кожного його рядка у зворотному порядку 

#include <stdio.h>
#include <stdlib.h>
#include "list_tools.h"

int main(void)
{
	FILE *testFile_read = fopen("text_before.txt", "r");
	FILE *testFile_write_back_to_front = fopen("text_after_back_to_front.txt", "w");
	FILE *testFile_write_normal = fopen("text_after_normal.txt", "w");

	List *aList = CreateList();

	printTextFromFileBackToFront (aList, testFile_read, testFile_write_normal);
	
	printListToFILE(testFile_write_normal, aList);
	
	FreeList(aList);
	
	return 0;
	
}

