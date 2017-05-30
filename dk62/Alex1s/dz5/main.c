#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
	printf("Greetings! The program is designed to make a list of triangles.\n");
	printf("You can create 5 different triangles. Enter coordinates\n");
	
	Triangles *Element = createList();
	
	char arg;
	int i;
	
	createTriangle(Element);
	createTriangle(Element);
	createTriangle(Element);
	createTriangle(Element);
	createTriangle(Element);
	
	printf("\nAmount of figures: %i\n", Element->currentSize);
	if(Element->currentSize)
	{
		printf("List of areas:\n");
		printTriangles(Element);
	}
	
	if(Element->currentSize > 1)
	{
		printf("\nEnter \"s\" to sort figures by area.\nEnter: ");
		fflush(stdin);
		arg = getCharValue();
		if(arg == 's' || arg == 'S')
		{
			shellSort(Element);
			printTriangles(Element);
		}
	}
	
	printf("\nEnter \"l\" to search figures by area.\nEnter: ");
	fflush(stdin);
	arg = getCharValue();
	
	if(arg == 'l' || arg == 'L')
	{
		double val;
		
		printf("\nEnter area to search.\nEnter: ");
		scanf("%lf", &val);
		
		int s = lineSearch(Element, val);
		if(s >= 0)
			printTriangle(Element, s);
		else
			printf("Not founded!\n");
	}
	
	deleteList(Element);
	system("pause");
	return 0;
}
