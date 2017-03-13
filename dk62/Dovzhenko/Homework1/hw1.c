#include "hw.h"
#include <stdio.h>
#include <string.h>
 int SearchWord(char Sentence[], char Word[])
 {
 	int counter = 0;
 	for (int k =0; k<strlen(Sentence); k++)
 	{
 		if(Sentence[k]==Word[0])
 		{
 			for(int t=0; t<strlen(Word); t++)
 			{
 				if(Sentence[k+t]==Word[t])
 				counter++;
 				if (counter==strlen(Word))
 				return (k);
			}
		}
		counter=0;
	}
 	
 if (counter == 0)
 return -1;	

 }
