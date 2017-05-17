#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[])
{
char *str = (char *) malloc(sizeof(char) * 100);	
char *txt = (char *) malloc(sizeof(char) * 15);		
int result = 0;

printf("Enter text:\n");							
fgets(str, 100, stdin);								

printf("Enter word to search:\n");					
fgets(txt, 15, stdin);								

result = search(str, txt);							
printf("%i\n", result);					

free(str);											
free(txt);											

system("pause");	
return 0;
}
