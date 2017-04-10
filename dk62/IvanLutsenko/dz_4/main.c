#include "dk_tool.h"
#include <string.h>

int main() 
{
	circle* array = NULL;
	int size = 0;
	do
	{
		printf("Set new circle`s x, y and radius (r = 0 to end):\n");
		int x, y, r;
		scanf("%i %i %i", &x, &y, &r);
		if (r == 0)
			break;		
		if (init(&array, &size, x, y, r) == 1) 
		{
			printf("ERROR\n");
			return 1;
		}
	}while(1);

	circle* tmp = (circle*)malloc(sizeof(circle)*size);
	memcpy(tmp, array, sizeof(circle)*size);
	output("unsorted.json", array, size);
	
	sortInsert(&array, size);
	output("insert.json", array, size);
	
	memcpy(array, tmp, sizeof(circle)*size);
	sortSelect(&array, size);
	output("select.json", array, size);
	
	memcpy(array, tmp, sizeof(circle)*size);
	sortBubble(&array, size);
	output("bubble.json", array, size);
	
	free(tmp);
	free(array);
	return 0;
}
