#include <stdio.h> 
#include "dk_tool.h"
#define Size 100

int main() 
{
    char sentence[Size];
    char word[Size];

    debugEnterSentence(Size,sentence);
    debugEnterWord(Size,word);
    
    int position = search(sentence, word);
    
    printf("Program search only latest position and position is: %d\n",position);
    
    return 0;
}
