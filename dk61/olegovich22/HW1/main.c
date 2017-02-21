#include <stdio.h>
#include "dk_tool.h"

int main() {
    int maxText=222;
    int maxWord=22;
    char text[maxText];
    char searchWord[maxWord];

    getText(maxText, text);

    getWord(maxWord, searchWord);

    int result=countWord(searchWord, text);

    printf("In this text we have found %d %s\n", result, searchWord);

    return 0;
}