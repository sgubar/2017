#include <stdio.h>
#include <string.h>
#include "hw1.h"


int main() 
{
	char Sentence[1000]; 
	char Word  [100];

	printf("Please, enter your sentence. The characters should not exceed 1000:\n");
	gets(Sentence);
	while (strlen(Sentence)>1000)
	{
		printf("Please enter a smaller line:\n");
		gets(Sentence);
	}
	
	printf("Please, enter your word. The characters should not exceed 100:\n ");
	gets(Word);
		while (strlen(Word)>100)
	{
		printf("Please enter a smaller word:\n");
		gets(Word);
	}
	
	printf("The location of your word: %i\n", SearchWord(Sentence, Word));
	
	return 0;
}
