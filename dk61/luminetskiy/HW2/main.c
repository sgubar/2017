#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size;
	printf("Write number of figures: \n");
	scanf("%i",&size);
	circle *mass =(circle *)malloc(sizeof(circle)*size);
	
	return 0;
}
