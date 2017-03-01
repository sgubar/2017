#include <string.h>
#include <stdio.h>
#include "dk_tool.h"

void debugEnterSentence(int maxLenSentence , char sentence[] )
{
    
    printf("Please,enter a sentence which smallest then 100 symbols: ");
    gets(sentence);
    if(strlen(sentence) > maxLenSentence - 1 )             // overflow check
    {
        do
        {
            printf("Please, enter correctly again: ");
            gets(sentence);
            
        }while(strlen(sentence) > maxLenSentence - 1);
    }
    
    
    
}


void debugEnterWord(int maxLenWord , char word[])
{
    printf("Please,enter a word which smallest then 100 symbols: ");
    gets(word);
    if(strlen(word) > maxLenWord - 1 )                   // overflow check
    {
        do
        {
            printf("Please, enter correctly again: ");
            gets(word);
        
        }while(strlen(word) > maxLenWord - 1);
    }
    
	
    
}





int search( char  Sentence[] , char  Word[])
{
    int firstCounter;   
    int secondCounter = 0;  
    int position = -1;
    int SentenceLen = strlen(Sentence);
    int WordLen = strlen(Word);
    
    
    if(SentenceLen < WordLen )
    {
        return -2;
    }
    
    
    for(firstCounter = 0; firstCounter <= SentenceLen - WordLen ; firstCounter ++)  
    {
        
        if(Sentence[firstCounter] == Word[secondCounter] && secondCounter < SentenceLen)        //analysis of compliance
        {
            if(Sentence[firstCounter + 1] == Word[secondCounter + 1])
            
            {
                 position = firstCounter ;
            }
           
        }
    }
    
    return position ;
    
}
   
