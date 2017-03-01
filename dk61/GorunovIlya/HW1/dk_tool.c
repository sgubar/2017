#include <string.h>
#include <stdio.h>
#include "dk_tool.h"

void debugEnterSentence(int maxLenSentence , char sentence[] )
{
    
    printf("Please,enter a sentence which smallest then 100 symbols: ");
    scanf("%s",&(*sentence));
    if(strlen(sentence) > maxLenSentence - 1 )             // overflow check
    {
        do
        {
            printf("Please, enter correctly again: ");
            scanf("%s",&(*sentence));
            
        }while(strlen(sentence) > maxLenSentence - 1);
    }
    
    
    
}


void debugEnterWord(int maxLenWord , char word[])
{
    printf("Please,enter a word which smallest then 100 symbols: ");
    scanf("%s",&(*word));
    
    if(strlen(word) > maxLenWord - 1 )                   // overflow check
    {
        do
        {
            printf("Please, enter correctly again: ");
            scanf("%s",&(*word));
        
        }while(strlen(word) > maxLenWord - 1);
    }
    
}





int search( char  firstWord[] , char  secondWord[])
{
    int firstCounter;   
    int secondCounter = 0;  
    int position = -1;
    int firstLen = strlen(firstWord);
    int secondLen = strlen(secondWord);
    
    
    if(firstLen < secondLen )
    {
        return -2;
    }
    
    
    for(firstCounter = 0; firstCounter <= firstLen - secondLen ; firstCounter ++)  
    {
        
        if(firstWord[firstCounter] == secondWord[secondCounter] && secondCounter < firstLen)        //analysis of compliance
        {
            if(firstWord[firstCounter + 1] == secondWord[secondCounter + 1])
            
            {
                 position = firstCounter ;
            }
           
        }
    }
    
    return position ;
    
}
   
