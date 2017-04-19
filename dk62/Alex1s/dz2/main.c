#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to make a list of triangles.\n");
printf("You can create 5 different triangles. Enter coordinates\n");
printf("Program works in loop by 3 steps:\n1) Creating figures;\n");
printf("2) Try to stop program;\n\nYou can add and delete figures more then 5 times.\n");

Triangles *Element = (Triangles *) malloc(sizeof(Triangles));
if(!Element)
	exit(10);

Element->max_fig = 5;
Element->current_fig = 0;

Figure *Dots = (Figure *) malloc(sizeof(Figure) * Element->max_fig);
if(!Dots)
	{
	free(Element);
	exit(11);
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
	
	printf("\nAmount of figures: %i\nList of areas:\n\n", Element->current_fig);
	for(i = 0; i < Element->current_fig; i++)
		{
		Element->place = &(Dots[i]);
		printf("%i) %f\n", i, Element->place->area);
		}
	
	printf("\nEnter \"d\" to delete anyone figure.\nEnter: ");
	fflush(stdin);
	arg = gchar();	
	if(arg == 'd' || arg == 'D')
		do{
			do{
				printf("\nEnter number of tringle to delete (0 - 4).\nEnter: ");
				i = gint();
			}while(i < 0 || i > Element->current_fig - 1);
			delete_fig(Element, Dots, i);
			
			if(!Element->current_fig)
				break;
			
			printf("\nEnter \"d\" to delete one more figure.\nEnter: ");
			fflush(stdin);
			arg = gchar();
		}while(arg == 'd' || arg == 'D');
	
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
