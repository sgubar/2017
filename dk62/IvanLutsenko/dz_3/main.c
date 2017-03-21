#include "dk_tool.h"

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
	}
	while(1);
	output("out.json", array, size);
	return 0;
}