#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int size;
	printf("Write number of figures: \n");
	scanf("%i",&size);
	circle *mass =(circle *) malloc(sizeof(circle)*size);
    for (int i = 0; i < size; ++i) {
        NewCircle(&mass[i]);
        mass[i].square = Squareof(mass[i]);
    }
    ShowTheFigures(mass,size);
	return 0;
}
