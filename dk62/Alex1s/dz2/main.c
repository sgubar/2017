#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include "dk_tool.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to make a list of triangles.\n");
printf("You can create 5 different triangles. Enter coordinates\n");
printf("Program works in loop by 3 steps:\n1) Creating figures;\n2) Deleting figures;\n");
printf("3) Try to stop program;\nYou can add and delete figures more then 5 times.\n");

Triangles *Element = (Triangles *) malloc(sizeof(Triangles));
if(!Element)
	exit(10);

Element->max_fig = 5;
Element->current_fig = 0;

Element->place = (Figure *) malloc(sizeof(Figure) * Element->max_fig);
if(!Element->place)
	{
	free(Element);
	exit(11);
	}

Figure *Dots = NULL;

char arg;
int i;

while(true)
	{
	do{
		printf("\nCreating tringle[%i]...\n", Element->current_fig);
		make_triangle(Element, Dots);
		printf("Enter \"y\" to add one more tringle: ");
		scanf("%c", &arg);		
	}while(arg == 'y'|| arg == 'Y');
	
	do{
		do{
			printf("Choose number (0 - 4) of figure to delete: ");
			scanf("%i", &i);
		}while(i < 0 || i > 4);
			
		delete_triangle(Element, Dots, i);
			
		printf("Enter \"d\" to delete one more figure: ");
		scanf("%c", &arg);
	}while(arg == 'd'|| arg == 'D');
	
	printf("Amount of figures: %i\n", Element->current_fig);
	printf("List of areas:\n");
	for(i = 0; i < Element->current_fig; i++)
		printf("%i) %f\n", i, Element->area[i]);
		
	printf("Enter \"e\" to stop working, or else to continue");
	scanf("%c", &arg);
	if(arg == 'e' || arg == 'E')
		break;
	}
delete_all(Element, Dots);
system("pause");
return 0;
}
