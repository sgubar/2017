#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
	char str[100];
	char search[50];
	int result = 0;

	printf("Enter stroku\n");
	fgets(str, 100, stdin);
	
	printf("Enter word to search\n");
	fgets(search, 50, stdin);
	
	result = sea(str, search);
	printf("%i\n", result);
	
	system("pause");	
	return 0;
}
