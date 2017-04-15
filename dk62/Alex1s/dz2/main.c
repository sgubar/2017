#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to make a list of triangles.\n");
printf("You can create 5 different triangles. Enter coordinates\n");
printf("Program works in loop by 2 steps:\n1) Creating figures;\n");
printf("2) Try to stop program;\n\n");

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

Figure *Dots = &(Element->place[Element->current_fig]);
if(!Dots)
	{
	free(Element->place);
	free(Element);
	exit(12);
	}

char arg;
int i;

while(true)
	{
	do{
		printf("\nCreating tringle[%i]...\n\n", Element->current_fig);
		make_triangle(Element, Dots);
		printf("Enter \"y\" to add one more figure, or else for next step.\nEnter: ");
		fflush(stdin);
		arg = gchar();	
	}while(arg == 'y'|| arg == 'Y');
	
	printf("\nAmount of figures: %i\n", Element->current_fig);
	printf("List of areas:\n\n");
	for(i = 0; i < Element->current_fig; i++)
		printf("%i) %f\n", i, Element->area[i]);
		
	printf("\nEnter \"e\" to stop working, or else to continue: ");
	fflush(stdin);
	arg = gchar();	
	if(arg == 'e' || arg == 'E') 
		break;
	}
delete_all(Element, Dots);
system("pause");
return 0;
}
