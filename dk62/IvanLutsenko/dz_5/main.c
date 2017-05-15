#include "dk_tool.h"
#include <string.h>

int main() {
	circle* array = NULL;
	int size = 0, i;
	do{
		printf("Set new circle`s x, y and radius (r = 0 to end):\n");
		int x,y,r;
		scanf("%i %i %i",&x,&y,&r);
		if (r == 0)
			break;		
		if (init(&array,&size,x,y,r) == 1) {
			printf("ERROR\n");
			return 1;
		}
	}while(1);
	output("unsortedShell.json",array,size);
	
	printf("Set radius to find: ");
	scanf("%i",&i);
	i = find(array,size,i);
	if (i == -1)
		printf("No element with such radius found\n");
	else 
		printf("Element with such radius has index %i\n",i);
	
	sortShell(array, size);
	output("sortedShell.json",array,size);
	
	free(array);
	return 0;
}
