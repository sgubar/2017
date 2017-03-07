#include <stdio.h>
#include <string.h>
#include "dk_tool.h"
#define N 100

int main() 
{
	char TheString[N]; 
	char TheWord  [N];

	printf("Enter your string. Maximum lenght = 100.\n");
	gets(TheString);
	
		while(strlen(TheString) > N)
		{
			printf("You have a buffer overflow. Enter a new string that is less than 100 characters.\n");
			gets(TheString);
		}

	printf("Enter your word. Maximum lenght = 100.\n");
	gets(TheWord);
		
		while(strlen(TheWord) > N)
		{
			printf("You have a buffer overflow. Enter a new word that is less than 100 characters.\n");
			gets(TheWord);
		}
	
	printf("Your word coordinates: %i\n", Search(TheString, TheWord));
	
	return 0;
}
