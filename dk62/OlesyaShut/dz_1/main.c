#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
	char *str = (char *) malloc(sizeof(char) * 100);
	char *search = (char *) malloc(sizeof(char) * 50);
	int result = 0;

	printf("Enter stroku\n");
	fgets(str, 100, stdin);
	
	printf("Enter word to search\n");
	fgets(search, 50, stdin);
	
	result = sea(str, search);
	printf("%i\n", result);
	
	free(search);
	free(str);
	
	system("pause");	
	return 0;
}
